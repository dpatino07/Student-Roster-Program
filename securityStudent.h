/* 
 * File:   securityStudent.h
 * Author: DPati
 *
 * Created on July 28, 2019, 10:45 AM
 */

#ifndef SECURITYSTUDENT_H
#define	SECURITYSTUDENT_H

#include "student.h"

class SecurityStudent : public Student {
    public:using Student::Student;
        Degree getDegreeProgram() override;
        
        
    private:
        Degree degree = SECURITY;
            
};


#endif	/* SECURITYSTUDENT_H */

