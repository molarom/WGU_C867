#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

#define ROSTERSIZE 5

class Roster {
public:
    Roster();
    ~Roster();
    
    // Create array of pointers to hold Student objects.
    Student **classRosterArray;
    
    // Function prototypes to modify student objects.
    void Add(int array_pos, std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void Remove(std::string studentID);
    
    // Function prototype to parse student data in CSV format.
    void Parse(int array_pos, const std::string studentData);
    
    // Function prototypes to display student information stored in table.
    void PrintAll();
    void PrintAverageDaysInCourse(int student_index, std::string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degree);
    
};

#endif
