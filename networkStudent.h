/* 
 * File:   networkStudent.h
 * Author: DPati
 *
 * Created on July 28, 2019, 10:44 AM
 */

#ifndef NETWORKSTUDENT_H
#define	NETWORKSTUDENT_H

#include "student.h"

class NetworkStudent : public Student {
    public:
        using Student::Student;
        Degree getDegreeProgram() override;
        
    private:
        Degree degree = NETWORKING;
            
};


#endif	/* NETWORKSTUDENT_H */

