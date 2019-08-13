/* 
 * File:   roster.h
 * Author: DPati
 *
 * Created on July 28, 2019, 10:44 AM
 */

#ifndef ROSTER_H
#define	ROSTER_H

#include <iostream>
#include "Student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

using namespace std;

const int NUM_STUDENTS = 5;

class Roster {
    
public:
    Roster();
    int index = 0;

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
    void printAll();
    void remove(string studentID);
    void printByDegreeProgram(Degree degree);
    void printNumDaysInCourse(string studentID);
    void printInvalidEmails();
    
    Student* classRosterArray[NUM_STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    
    ~Roster();
};


#endif	/* ROSTER_H */

