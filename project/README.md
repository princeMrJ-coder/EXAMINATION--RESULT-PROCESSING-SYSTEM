GROUP PROJECT.
EXAMINATION-RESULT-PROCESSING-SYSTEM

GROUP MEMBERS            INDEX NUMBER
Prince Joshua Abbe Abbey  01245040B 
Yinime Daniel Tidow       01235160B
Francis Dompreh           01243076B
Andzie Blessing Maniche   01242429B
Derrick Agyei Ofori       01245574B
Ackah Daniel Kofi         01244549B
Quartey Allen             01246746B
Fatah King Saana          01243745B
Botchway Auxwell Kwakye   01242635B 
 
 
 Problem Statement
A lecturer may need to process examination results for many students. Manual calculation of total marks, grades and pass or fail status can be slow and error-prone. There is a need for a C++ application that records student details, calculates final scores, assigns grades and saves a result report.


Aim of the Project
To develop a C++ Examination Result Processing System that records student results, calculates total marks, assigns grades and produces a final result report.



We were able to solve this problem by creating an application that asks for student's results, records them, calculates and assigns grades, and aslo produces a report.
The grading rules are simple. If studentResult >= 80; grade=A and status=pass, 
                                if studuntResult >= 70; grade=B and status=pass,
                                and so on...
                        but if studentResult >= 40; grade=E and status=pass
                            else grade=F and status=fail.
When all this is done depending on how many students there are, the totalPassed and totalFailed outputs get updated.


We faced a couple challenges, of which we solved as a group. some of the challenges were;
1- finding alternatives to standard fixed-size arrys, of which we used #include <vector> to solve that
problem.
2- the need to format how the data looks when printed, so we used #include <iomanip>

Conclusion:
This application can help lecturers be efficient and save time when recording student's reaults. It becomes a problem when a mistake is made but theat can be rectified by alterting the results.

