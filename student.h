/* 
 * File:   student.h
 * Author: DPati
 *
 * Created on July 28, 2019, 10:44 AM
 */

#ifndef STUDENT_H
#define	STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
    
    Student();
    Student (string newStudentID, string newFirstName, string newLastName, string newEmailAddress, int newAge, int newNumDaysInCourse[], Degree newDegree);

    
    // Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int    getAge();
    int*   getNumDaysInCourse();
    
    
    // Mutators
    void setStudentID(string newStudentID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setEmailAddress(string newEmailAddress);
    void setAge(int newAge);
    void setNumDaysInCourse(int days[]);
    void setDegreeProgram(Degree degree);

    
    virtual Degree getDegreeProgram() = 0;
    virtual void print();
    
    ~Student();
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int    age;
    int    numDaysInCourse[3];

    
    Degree degree;
    

};


#endif	/* STUDENT_H */

