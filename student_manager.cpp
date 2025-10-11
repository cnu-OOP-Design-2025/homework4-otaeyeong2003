#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    Student newstudent(name, id, midterm, final);
    students[num_of_students] = newstudent;
    ++num_of_students;

}

void StudentManager::deleteStudent(int id) {
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getID() == id) {
            students[i] = students[i+1];
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    for (int i=0; i<num_of_students; i++) {
        if (student.getID() == students[i].getID()) {
            students[i] = student;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    for (int i=0; i<num_of_students; i++) {
        if (id == students[i].getID()) {
            return i;
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    int bmid = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > students[bmid].getRecord().getMidterm()){
        bmid = i;
        }
    }
    return bmid;
}

int StudentManager::findBestStudentInFinal() const {
    int bfin = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getFinal() > students[bfin].getRecord().getFinal()){
        bfin = i;
        }
    }
    return bfin;
}

int StudentManager::findBestStudent() const {
    int bmid = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > bmid){
        bmid = students[i].getRecord().getMidterm();
        }
    }
    return bmid;
}

float StudentManager::getMidtermAverage() const {
    float smid = 0;
    for (int i=0; i<num_of_students; i++) {
        smid += students[i].getRecord().getMidterm();
    }
    return smid/num_of_students;
}

float StudentManager::getFinalAverage() const {
    float sfin = 0;
    for (int i=0; i<num_of_students; i++) {
        sfin += students[i].getRecord().getFinal();
    }
    return sfin/num_of_students;
}

float StudentManager::getTotalAverage() const {
    float ans = 0;
    for (int i=0; i<num_of_students; i++) {
        ans += students[i].getRecord().getFinal();
        ans += students[i].getRecord().getMidterm();
    }
    return ans/num_of_students;
}

