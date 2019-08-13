/* 
 * File:   softwareStudent.h
 * Author: DPati
 *
 * Created on July 28, 2019, 10:45 AM
 */

#ifndef SOFTWARESTUDENT_H
#define	SOFTWARESTUDENT_H

#include "student.h"

class SoftwareStudent : public Student {
    
    public:
        using Student::Student;
        virtual Degree getDegreeProgram() override;
        
    private:
        Degree degree = SOFTWARE;
        
};


#endif	/* SOFTWARESTUDENT_H */

