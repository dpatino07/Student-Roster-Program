#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student() {
    
}

Student::Student(string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newNumDaysInCourse[3], Degree newDegree) {
    setStudentID(newStudentID);
    setFirstName(newFirstName);
    setLastName(newLastName);
    setEmailAddress(newEmailAddress);
    setAge(newAge);
    setNumDaysInCourse(newNumDaysInCourse);
    setDegreeProgram(newDegree);

}

// Accessor for each instance
string Student::getStudentID() {
    
    return studentID;
    
}

string Student::getFirstName() {
    
    return firstName;
    
}

string Student::getLastName() {
    
    return lastName;
    
}

string Student::getEmailAddress() {
    
    return emailAddress;
    
}

int Student::getAge() {
    
    return age;
    
}

int* Student::getNumDaysInCourse() {
    
    return numDaysInCourse;
    
}

Degree Student::getDegreeProgram() {
    
    return degree;
    
}


// Mutators for each instance
void Student::setStudentID(string newStudentID) {
    
    studentID = newStudentID;
    
}

void Student::setFirstName(string newFirstName) {
    
    firstName = newFirstName;
    
}

void Student::setLastName(string newLastName) {
    
    lastName = newLastName;
    
}

void Student::setEmailAddress(string newEmailAddress) {
    
    emailAddress = newEmailAddress;
    
}

void Student::setAge(int newAge) {
    
    age = newAge;

}

void Student::setNumDaysInCourse(int days[]) {
    
    for (int i = 0; i < 3; i++) {
        numDaysInCourse[i] = days[i];
    }
}

void Student::setDegreeProgram(Degree newDegree) {
    
    degree = newDegree;
    
}


void Student::print() {
    int* numDaysInCourse = getNumDaysInCourse();
    string degree;
    
    cout << getStudentID() << "\t";
    cout << "First Name: " << getFirstName() << "\t";
    cout << "Last Name: " << getLastName() << "\t";
    cout << "Email Address: " << getEmailAddress() << "\t";
    cout << "Age: " << getAge() << "\t";
    cout << "Number of Days In Course: " << numDaysInCourse[0] << ", " << numDaysInCourse[1] << ", " << numDaysInCourse[2] << "\t";
    cout << "Degree Program: " << degree << "\n";
    
    switch (getDegreeProgram()) {
        case 0: cout << "Security";
        break;
        case 1: cout << "Networking";
        break;
        case 2: cout << "Software";
        break;
    }
    return;
}

Student::~Student() {
    
};
