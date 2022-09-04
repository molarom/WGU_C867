#include <iostream>
#include "roster.h"

using namespace std;

#define FIELDS 7
#define DAYS 3
#define STUDENT_ERR -1

// Constructor to initialize array of Student objects.
Roster::Roster(){
    classRosterArray = new Student*[ROSTERSIZE];
}

// Destructor to free allocated memory.
Roster::~Roster(){
    delete [] classRosterArray;
}


// Roster::parse()
// Tokenizes CSV studentData for assigment to variables of a Student object.
void Roster::Parse(int array_pos, const string studentData) {
    // Parse each of the fields.
    size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
     
    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
     
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
     
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysLeft_1 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysLeft_2 = stoi(studentData.substr(lhs, rhs - lhs));
        
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysLeft_3 = stoi(studentData.substr(lhs, rhs - lhs));
     
    lhs = rhs + 1;
    DegreeProgram degree;
     
    string degreePlan = studentData.substr(lhs, studentData.length() - lhs);
    if (degreePlan == "SOFTWARE") { degree = DegreeProgram::SOFTWARE; }
    else if (degreePlan == "NETWORK") { degree = DegreeProgram::NETWORK; }
    else if (degreePlan == "SECURITY") { degree = DegreeProgram::SECURITY; }
    else { degree = DegreeProgram::UNDEF; }

    Add(array_pos, studentID, firstName, lastName, email, age, daysLeft_1, daysLeft_2, daysLeft_3, degree);
    
}

// Creates and assigns all variables to Student object.
void Roster::Add(int array_pos,std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    Student* student_obj = new Student;
    
    student_obj->SetStudentID(studentID);
    student_obj->SetFirstName(firstName);
    student_obj->SetLastName(lastName);
    student_obj->SetEmail(emailAddress);
    student_obj->SetAge(age);
    student_obj->SetDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);
    student_obj->SetDegree(degreeprogram);
    
    classRosterArray[array_pos] = student_obj;
}

// Clears entries for a student in table based on studentID.
void Roster::Remove(std::string studentID) {
    // If found, value changes from -1 to index of the array.
    int student_index = STUDENT_ERR;
    
    cout << "\nTask: Searching for " << studentID << "\n";
    
    for (int i = 0; i < ROSTERSIZE; i++) {
        if (studentID == this->classRosterArray[i]->GetStudentID()) {
            student_index = i;
        }
    }
    
    if (student_index >= 0) {
        Student* blank_student = new Student();
        
        blank_student->SetStudentID("REMOVED");
        blank_student->SetFirstName("");
        blank_student->SetLastName("");
        blank_student->SetEmail("");
        blank_student->SetAge(0);
        blank_student->SetDaysToComplete(0, 0, 0);
        blank_student->SetDegree(UNDEF);
        
        classRosterArray[student_index] = blank_student;
    } else {
        cout << "\n*ERR: Student " << studentID << " not found." << "\n";
    }
}

// Displays all invalid student emails.
// Verifies the email contains at least one '@' and '.', disallows ' '.
void Roster::PrintInvalidEmails() {
    
    cout << "\nSearching for invalid emails...\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < ROSTERSIZE; i++) {
        string tmp_email_str = classRosterArray[i]->GetEmail();
        if (tmp_email_str.find('@') == string::npos) { cout << tmp_email_str << "\n"; }
        if (tmp_email_str.find('.') == string::npos) { cout << tmp_email_str << "\n"; }
        if (tmp_email_str.find(' ') != string::npos) { cout << tmp_email_str << "\n"; }
    }
}

// Print the average days for each student by studentID.
void Roster::PrintAverageDaysInCourse(int student_index, std::string studentID) {
    int *tmp_days = {0};
    int avg = 0;
    
    for (int i = 0; i < ROSTERSIZE; i++) {
        if (studentID == this->classRosterArray[i]->GetStudentID()) {
            tmp_days = this->classRosterArray[i]->GetDaysToComplete();
            
            for (int j = 0; j < DAYS; j++) {
                avg += tmp_days[j];
            }
            avg /= DAYS;
        cout << "Student ID: " << studentID << " | "<< this->classRosterArray[i]->GetFirstName() << " " << this->classRosterArray[i]->GetLastName() << " | Average Days: " << avg << "\n";
        }
    }
}

// Print the average days for each student by studentID.
void Roster::PrintByDegreeProgram(DegreeProgram degree) {
    for (int i = 0; i < ROSTERSIZE; i++) {
        if (classRosterArray[i]->GetDegree() == degree){
            for (int j = 0; j < FIELDS; j++) {
                classRosterArray[i]->Print(j);
                cout << "\t";
            }
            cout << "\n";
        }
    }
}

// Displays all student information in the table.
void Roster::PrintAll() {
    for (int i = 0; i < ROSTERSIZE; i++) {
        for (int j = 0; j < FIELDS; j++) {
            classRosterArray[i]->Print(j);
            cout << "\t";
        }
        
        cout << "\n-------------------------------------------------------------------------------\n";
    }
}
