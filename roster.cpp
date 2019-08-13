#include <vector>
#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

    const string studentData[] = {
        
    "A1, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
    "A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
    "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
    "A4, Erin, black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
    "A5, Dominique, Patino, dpatin2@wgu.edu, 27, 30, 35, 20, SOFTWARE"
            
    };

int main() {
    
        
    cout << "Scripting and Programming Applications (C867), C++, 0001134127, Dominique Patino" << endl;

    Roster classRoster;
   
    
    // function to populate the ClassRosterArray
	for (int i = 0; i < 5; i++) {
		stringstream ss(studentData[i]);   
		vector<string> input;
		while (ss.good()) {
			string substr;
			getline(ss, substr, ',');
			input.push_back(substr);
		}
                Degree degree;
		if (input[8] == "SECURITY") {
			degree = Degree::SECURITY;
		}
		if (input[8] == "SOFTWARE") {
			degree = Degree::SOFTWARE;
		}
		if (input[8] == "NETWORK") {
			degree = Degree::NETWORKING;
		}
		classRoster.add(input[0], input[1], input[2], input[3], stoi(input[4]), stoi(input[5]),
			stoi(input[6]), stoi(input[7]), degree);
	}
    
    classRoster.printAll();
    classRoster.printInvalidEmails();
    cout << endl;
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        classRoster.printNumDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    classRoster.remove("A3");
    cout << endl;
    
    for (int j = 0; j < 5; ++j) {
        if (classRoster.classRosterArray[j] != nullptr) {
            string iD = classRoster.classRosterArray[j]->getStudentID();
            string fullName = classRoster.classRosterArray[j]->getFirstName() + " " + classRoster.classRosterArray[j]->getLastName();
            cout << "Student ID: " << iD << endl;
            cout << "Name: " << fullName << endl;
            classRoster.printNumDaysInCourse(iD);
            cout << endl;
        }
    }
}

Roster::Roster() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster(){
    
    delete * classRosterArray;
}
    
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
                        int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {

    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
            if (degreeProgram == SECURITY) {
                classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
            }
            else if (degreeProgram == NETWORKING) {
                classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
            }
            else if (degreeProgram == SOFTWARE) {
                classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
            }
            break;
        }
    }
}

    void Roster::remove(string studentID) {
        for (int i = 0; i < NUM_STUDENTS; i++) {
            if (classRosterArray[i] == nullptr) {
                cout << "Error: Student with ID: " << studentID << " not found" << endl;
                break;
            }
            else if (studentID == classRosterArray[i]->getStudentID()) {
                classRosterArray[i] = nullptr;
                cout << "Student removed." << endl;
            }
        }
    }
    
    void Roster::printAll() {
        int i = 0;
        
        while (i < NUM_STUDENTS) {
            if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
            i++;
        }
    }
    
    void Roster::printByDegreeProgram(Degree degree){
        for (int i = 0; i < NUM_STUDENTS; i++) {
            if (classRosterArray[i]->getDegreeProgram() == degree) {
                classRosterArray[i]->print();
            }
        }
    }
    
    void Roster::printNumDaysInCourse(string studentID) {
        int i = 0;
 
        while (i < NUM_STUDENTS) {
            if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
                int* avgDays = classRosterArray[i]->getNumDaysInCourse();
                float sum = 0.0;
                for (int i = 0; i < 3; i++) {
                    sum += avgDays[i];
                }
                cout << (sum/3) << endl;
            }
            i++;
        }
    }
    
    void Roster::printInvalidEmails() {
        for (int i = 0; i < NUM_STUDENTS; i++) {
            string email = classRosterArray[i]->getEmailAddress();
            if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
                cout << email << " is not a valid email address." << endl;
            }
        }
    }