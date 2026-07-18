#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

// Class Design as per Section 8 Requirements
class StudentResult {
private:
    string studentName;
    string indexNumber;
    double caScore;
    double examScore;
    double totalScore;
    string grade;
    string status;

public:
    // Prompt and set student data
    void setStudentDetails(int studentNum) {
        cout << "\nStudent " << studentNum << endl;
        cout << "Enter student name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, studentName);
        cout << "Enter index number: ";
        getline(cin, indexNumber);
    }

    // Input validation loop for scores
    void validateScores() {
        // Validate CA Score (0 to 40)
        while (true) {
            cout << "Enter CA score out of 40: ";
            if (cin >> caScore && caScore >= 0 && caScore <= 40) {
                break;
            } else {
                cout << "Invalid entry. CA score must be between 0 and 40.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }

        // Validate Exam Score (0 to 60)
        while (true) {
            cout << "Enter exam score out of 60: ";
            if (cin >> examScore && examScore >= 0 && examScore <= 60) {
                break;
            } else {
                cout << "Invalid entry. Exam score must be between 0 and 60.\n";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }

    // Calculate overall mark
    void calculateTotal() {
        totalScore = caScore + examScore;
    }

    // Assign grades according to Section 6 Grading Guide
    void assignGrade() {
        if (totalScore >= 80 && totalScore <= 100) {
            grade = "A";
            status = "Pass";
        } else if (totalScore >= 70 && totalScore < 80) {
            grade = "B";
            status = "Pass";
        } else if (totalScore >= 60 && totalScore < 70) {
            grade = "C";
            status = "Pass";
        } else if (totalScore >= 50 && totalScore < 60) {
            grade = "D";
            status = "Pass";
        } else if (totalScore >= 40 && totalScore < 50) {
            grade = "E";
            status = "Pass";
        } else if (totalScore >= 0 && totalScore < 40) {
            grade = "F";
            status = "Fail";
        } else {
            grade = "Invalid";
            status = "Invalid Score";
        }
    }

    // Console output for immediate verification
    void displayResult() {
        cout << "Total Score: " << totalScore << endl;
        cout << "Grade: " << grade << endl;
        cout << "Status: " << status << endl;
    }

    // Helper getters for reporting metrics
    string getStatus() const { return status; }
    
    // Formats student records cleanly for file writing
    void saveResult(ofstream &outFile) {
        outFile << left << setw(25) << studentName 
                << setw(15) << indexNumber 
                << setw(10) << caScore 
                << setw(12) << examScore 
                << setw(12) << totalScore 
                << setw(8) << grade 
                << setw(10) << status << "\n";
    }
};

int main() {
    // Welcome Screen
    cout << "==================================================\n";
    cout << "        EXAMINATION RESULT PROCESSING SYSTEM       \n";
    cout << "==================================================\n";

    int numberOfStudents;
    while (true) {
        cout << "Enter number of students: ";
        if (cin >> numberOfStudents && numberOfStudents > 0) {
            break;
        } else {
            cout << "Please enter a valid number of students greater than 0.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Use vector container to dynamic store student instances
    vector<StudentResult> studentList(numberOfStudents);
    int totalPassed = 0;
    int totalFailed = 0;

    // Process loop
    for (int i = 0; i < numberOfStudents; i++) {
        studentList[i].setStudentDetails(i + 1);
        studentList[i].validateScores();
        studentList[i].calculateTotal();
        studentList[i].assignGrade();
        studentList[i].displayResult();

        // Count metrics
        if (studentList[i].getStatus() == "Pass") {
            totalPassed++;
        } else if (studentList[i].getStatus() == "Fail") {
            totalFailed++;
        }
    }

    // Display runtime summary
    cout << "\n============================================\n";
    cout << "               CLASS SUMMARY                \n";
    cout << "============================================\n";
    cout << "Total Students: " << numberOfStudents << endl;
    cout << "Passed: " << totalPassed << endl;
    cout << "Failed: " << totalFailed << endl;

    // File Output Handling (ofstream)
    ofstream outFile("examination_result_report.txt");
    if (!outFile) {
        cerr << "Error creating or opening the output file.\n";
        return 1;
    }

    // Formatting the saved text file output beautifully
    outFile << "====================================================================================\n";
    outFile << "                        ACCRA TECHNICAL UNIVERSITY                                  \n";
    outFile << "                     EXAMINATION RESULT SUMMARY REPORT                              \n";
    outFile << "====================================================================================\n\n";
    outFile << left << setw(25) << "Student Name" 
            << setw(15) << "Index Number" 
            << setw(10) << "CA Score" 
            << setw(12) << "Exam Score" 
            << setw(12) << "Total Score" 
            << setw(8) << "Grade" 
            << setw(10) << "Status" << "\n";
    outFile << "------------------------------------------------------------------------------------\n";

    for (const auto &student : studentList) {
        // Safe casting to write out elements sequentially
        StudentResult currentStudent = student;
        currentStudent.saveResult(outFile);
    }

    outFile << "------------------------------------------------------------------------------------\n";
    outFile << "\nSTATISTICAL SUMMARY:\n";
    outFile << "Total Enrolled Class Size: " << numberOfStudents << "\n";
    outFile << "Total Passed             : " << totalPassed << "\n";
    outFile << "Total Failed             : " << totalFailed << "\n";
    outFile << "====================================================================================\n";

    outFile.close();
    cout << "Report saved successfully to examination_result_report.txt\n";

    return 0;
}