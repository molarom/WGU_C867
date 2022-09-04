#include <iostream>
#include <string>

#include "degree.h"
#include "student.h"
#include "roster.h"

using namespace std;

#define COURSE_TITLE "Scripting and Programmming - Applications (WGU C867)"
#define STUDENT_ID "000957566"
#define STUDENT_NAME "Brandon Epperson"
#define SEPARATOR "-----------------------------------------------------------------"


int main (int argc, char** argv) {
    
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Brandon,Epperson,bepper3@wgu.edu,24,20,34,54,SOFTWARE" };

    Roster *classRoster = new Roster();
    
    printf("%s\n%s\n%s\n%s\n", COURSE_TITLE, STUDENT_ID, STUDENT_NAME, SEPARATOR);
    
    for (int i = 0; i < ROSTERSIZE; i++) {
        classRoster->Parse(i, studentData[i]);
    }
    classRoster->PrintAll();
    classRoster->PrintInvalidEmails();
    
    cout << "\nGetting average days in each course...\n";
    cout << "\n----------------------------------------\n";
    for (int i = 0; i < ROSTERSIZE; i++) {
        classRoster->PrintAverageDaysInCourse(i, classRoster->classRosterArray[i]->GetStudentID());
    }
    
    cout << "\nGetting students enrolled in the SOFTWARE degree...\n";
    cout << "\n---------------------------------------------------\n";
    classRoster->PrintByDegreeProgram(SOFTWARE);
    classRoster->Remove("A3");
    printf("\n%s\n", SEPARATOR);
    classRoster->PrintAll();
    classRoster->Remove("A3");
    
    classRoster->~Roster();
    return 0;
}
