//
//  main.cpp
//  lab9oops
//
//  Created by Ragupathi on 28/09/2022.
//

/*
 Virtual Functions

 Consider 4 classes student, pg_student, research_student, and TA. The student class has name and roll_number as data members. It has a pure virtual display member function. The pg_student class has course1, course2, and course3 data members. It also has a display member function that displays the name, roll_number, course1, 2, and 3 credited by the pg_student. The research_student class has course1 and research_area data members. It has a display function that displays the name, roll_number, course, and research_area of the research_student. The TA class has course_assigned and role data members. The ‘role’ can be either a "PG student" or a "Research student". It also has a display that displays the name, roll_number, course_assigned, and role. Based on the 'role', the display function should additionally display course1, 2, and 3 if the role was a "PG student", and course, and research_area if the role is a "Research student". Also, the course_assigned should not be the same as course1, course2, and course3 for a pg_student, and course_assigned should not be the same as course for a research_student.
     Identify the inheritance required and use the virtual keywords wherever necessary. For simplicity, create arrays of objects and set details only for the TA class alone. Maintain proper boundary conditions and follow coding best practices.
 Write a menu-driven program with the following menus:
 Set Details
 Display
 Exit


 */
#include <iostream>
#include <vector>
using namespace std;

class Student{
protected:
    string name;
    int roll_number;
public:
    virtual void display() = 0;
};

void Student::display(){
    cout << "\nName is : " << name;
    cout << "\nRoll number is : " << roll_number;
}

class pg_student: public Student{
protected:
    string course_1;
    string course_2;
    string course_3;
    
public:
    void display();
};

void pg_student::display(){
    Student::display();
    cout << "\nCourse 1 : " << course_1;
    cout << "\nCourse 2 : " << course_2;
    cout << "\nCourse 3 : " << course_3;
}

class research_student: public Student{
protected:
    string course_1;
    string research_area;
    
public:
    void display();
};

void research_student::display(){
    Student::display();
    cout << "\nCourse 1 : " << course_1;
    cout << "\nResearch Area : " << research_area;
}

class TA: public pg_student, public research_student{
private:
    string course_assigned;
    string role;
    //pg student == 1, research student == 2
    int flag;
public:
    void display();
    //pg_student
    void set(string n, int rol, string c1, string c2, string c3, string ca, string rolee);
    //research_student
    void set(string n, int rol, string c, string ra, string ca, string rolee);
    friend TA* search(int roll, vector<TA *> TA);
    friend bool exists(int roll, vector<TA *> TA);
};

void TA::set(string n, int rol, string c1, string c2, string c3, string ca, string rolee){
    pg_student::name = n;
    pg_student::roll_number = rol;
    pg_student::course_1 = c1;
    pg_student::course_2 = c2;
    pg_student::course_3 = c3;
    course_assigned = ca;
    role = rolee;
    flag = 1;
}

void TA::set(string n, int rol, string c, string ra, string ca, string rolee){
    research_student::name = n;
    research_student::roll_number = rol;
    research_student::course_1 = c;
    research_student::research_area = ra;
    course_assigned = ca;
    role = rolee;
    flag = 2;
}

void TA::display(){
    if(flag == 1){
        pg_student::display();
    }
    else if(flag == 2){
        research_student::display();
    }
    cout << "\nResearch Student : " << course_assigned;
}

TA* search(int roll, vector<TA *> students){
    for(auto stud:students){
        if(stud->pg_student::roll_number == roll || stud->research_student::roll_number == roll){
            return stud;
        }
    }
    TA * new_stud = new TA;
    return new_stud;
}

bool exists(int roll, vector<TA *> students){
    for(auto stud : students){
        if(stud->pg_student::roll_number == roll || stud->research_student::roll_number == roll){
            return true;
        }
    }
    return false;
}

int main() {
    int choice = 4, option = 4;
    vector<TA *> TA;
    
    while(choice != 3){
        cout << "\nPlease choose one of the options :\n1. Set Details\n2. Display\n3. Exit ";
        cin >> choice;
        switch(choice){
            case 1: {
                while(option != 3){
                    cout << "\nDo you wish to :\n1. Set details of PG-Student TA\n2. Set details of Research-Student TA\n3. Go back to main menu" << endl;
                    cin >> option;
                    string name, course1, course2, course3, researchArea, role, courseAssigned;
                    int rollno;
                    //option 1 == pg student
                    if(option == 1){
                        cout << "\nPlease enter the name : "; cin >> name;
                        cout << "\nPlease enter the roll number : "; cin >> rollno;
                        if(exists(rollno, TA)){
                            cout << "\nRoll number exists\n";
                            break;
                        }
                        cout << "\nPlease enter course 1 : "; cin >> course1;
                        cout << "\nPlease enter course 2 : "; cin >> course2;
                        cout << "\nPlease enter course 3 : "; cin >> course3;
                        cout << "\nPlease enter the course assigned : "; cin >> courseAssigned;
                        cout << "\nPlease enter the role : "; cin >> role;
                        class TA *student = new class TA;
                        if(courseAssigned != course1 && courseAssigned != course2 && courseAssigned != course3){
                        student->set(name, rollno, course1, course2, course3, courseAssigned, role);
                        TA.push_back(student);
                        }
                        else {
                            cout << "\nCourse Assigned cannot be the same as course 1, 2 or 3 \n";
                        }
                    }
                    if (option == 2){
                        cout << "\nPlease enter the name : "; cin >> name;
                        cout << "\nPlease enter the roll number : "; cin >> rollno;
                        if(exists(rollno, TA)){
                            cout << "\nRoll number exists\n";
                            break;
                        }
                        cout << "\nPlease enter course 1 : "; cin >> course1;
                        cout << "\nPlease enter the research area : "; cin >> researchArea;
                        cout << "\nPlease enter the course assigned : "; cin >> courseAssigned;
                        cout << "\nPlease enter the role : "; cin >> role;
                        class TA *student = new class TA;
                        if(courseAssigned != course1){
                        student->set(name, rollno, course1, researchArea, courseAssigned, role);
                        TA.push_back(student);
                        }
                        else{
                            cout << "\nCourse Assigned cannot be the same as course 1 \n";
                        }
                    }
                    if (option == 3){
                        break;
                    }
                    else{
                        cout << "\nplease enter a valid choice\n";
                    }
                    
                }
                option = 4;
                break;
            }
            case 2: {
                int roll;
                cout << "\nFor display\nPlease enter the roll number : "; cin >> roll;
                if(!exists(roll, TA)){
                    cout << "\nRoll number does not exist\n";
                    break;
                }
                class TA * stud = search(roll, TA);
                stud->display();
                break;
            }
            case 3: {
                cout << "\nyou've sucessfully exited the program :)\n";
                break;
            }
            default : {
                cout << "\nplease enter a valid choice\n";
                break;
            }
        }
    }
    return 0;
}
