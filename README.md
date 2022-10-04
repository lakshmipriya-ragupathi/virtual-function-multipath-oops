# virtual-function-multipath-oops
## implementation of multipath oops
Virtual Functions
<br> Consider 4 classes student, pg_student, research_student, and TA. The student class has name and roll_number as data members. It has a pure virtual display member function. The pg_student class has course1, course2, and course3 data members. It also has a display member function that displays the name, roll_number, course1, 2, and 3 credited by the pg_student. The research_student class has course1 and research_area data members. It has a display function that displays the name, roll_number, course, and research_area of the research_student. The TA class has course_assigned and role data members. The ‘role’ can be either a "PG student" or a "Research student". It also has a display that displays the name, roll_number, course_assigned, and role. Based on the 'role', the display function should additionally display course1, 2, and 3 if the role was a "PG student", and course, and research_area if the role is a "Research student". Also, the course_assigned should not be the same as course1, course2, and course3 for a pg_student, and course_assigned should not be the same as course for a research_student. 
     <br>Identify the inheritance required and use the virtual keywords wherever necessary. For simplicity, create arrays of objects and set details only for the TA class alone. Maintain proper boundary conditions and follow coding best practices. </br>
 <br>Write a menu-driven program with the following menus:
 <br>Set Details
 <br>Display
 <br>Exit
