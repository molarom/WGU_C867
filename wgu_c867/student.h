#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"

#include <string>


// Student Class
// Stores student information into variables based on parsed CSV input from Roster class.
class Student {
private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string Email;
    int Age;
    int DaysToComplete[3] = {0};
    DegreeProgram Degree;

public:
    Student();
    ~Student();

    // Mutator function prototypes for object variable population.
    const void SetStudentID(std::string setID);
    const void SetFirstName(std::string setFirstName);
    const void SetLastName(std::string setLastName);
    const void SetEmail(std::string setEmail);
    const void SetAge(int setAge);
    const void SetDaysToComplete(int setDay1, int setDay2, int setDay3);
    const void SetDegree(DegreeProgram setDegree);

    // Accessor function prototypes to access object values.
    std::string GetStudentID();
    std::string GetFirstName();
    std::string GetLastName();
    std::string GetEmail();
    int GetAge();
    int* GetDaysToComplete();
    DegreeProgram GetDegree();
    
    // Print function to retrieve specific Student data.
    void Print(int data_selector);

};

#endif
