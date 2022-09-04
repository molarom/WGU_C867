#include <iostream>
#include "student.h"

using namespace std;

#define VALS_TO_SEPARATE 2

// Constructor for student object.
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->Email = "";
    this->Age= 0;
    this->DaysToComplete[0] = 0;
    this->DaysToComplete[1] = 0;
    this->DaysToComplete[2] = 0;
    this->Degree = DegreeProgram::UNDEF;
}

// Mutator functions begin here.
const void Student::SetStudentID(std::string setID) {
    this->studentID = setID;
}
const void Student::SetFirstName(std::string setFirstName) {
    this->firstName = setFirstName;
}
const void Student::SetLastName(std::string setLastName) {
    this->lastName = setLastName;
}
const void Student::SetEmail(std::string setEmail){
    this->Email = setEmail;
}
const void Student::SetAge(int setAge){
    this->Age = setAge;
}
const void Student::SetDaysToComplete(int setDay1, int setDay2, int setDay3){
    this->DaysToComplete[0] = setDay1;
    this->DaysToComplete[1] = setDay2;
    this->DaysToComplete[2] = setDay3;
}
const void Student::SetDegree(DegreeProgram setDegree){
    this->Degree = setDegree;
}

// Accessor functions begin here.
std::string Student::GetStudentID() { return studentID; }
std::string Student::GetFirstName() { return firstName; }
std::string Student::GetLastName() { return lastName; }
std::string Student::GetEmail() { return Email; }
int Student::GetAge() { return Age; }
int* Student::GetDaysToComplete() { return DaysToComplete; }
DegreeProgram Student::GetDegree() { return Degree; }

// Print function begins here.
void Student::Print(int data_selector) {
    switch (data_selector) {
        case 0:
            cout << studentID;
            break;
        case 1:
            cout << firstName;
            break;
        case 2:
            cout << lastName;
            break;
        case 3:
            cout << Email;
            break;
        case 4:
            cout << Age;
            break;
        case 5:
            for (int i = 0; i < 2; i++){
                cout << DaysToComplete[i] << ",";
            }
            cout << DaysToComplete[2];
            break;
        case 6:
            // Simple enum verification to make output prettier.
            if (Degree == 0) { cout << "SECURITY"; }
            else if (Degree == 1) { cout << "NETWORK"; }
            else if (Degree == 2) { cout <<  "SOFTWARE"; }
            else { cout << "UNDEF"; }
            
            break;
        default:
            cout << "OUT OF RANGE" << "\n" ;
            break;
    }
}
