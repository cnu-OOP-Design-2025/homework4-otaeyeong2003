#include "student.h"

#include <iostream>

/* StudentRecord */

StudentRecord::StudentRecord(float midterm, float final) 
    :midterm{midterm}, final{final}  
{
    

}

float StudentRecord::getTotal() const {
    float avg = (midterm+final)/2;
    return avg;
}

void StudentRecord::updateScores(float midterm, float final) {
    this->midterm = midterm;
    this->final = final;
}


/* Student */

Student::Student() 
    :name(""), id(id), record(0.0f, 0.0f)
{
    
}

Student::Student(const char *name, int id, float midterm, float final)
    : name(name), id(id), record(midterm, final)
{  }

void Student::updateRecord(const char *name, float midterm, float final) {
    this->record.updateScores(midterm, final);
}
