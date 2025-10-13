#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    if (num_of_students>=100) return;
    int id = ++last_student_id;
    Student newstudent(name, id, midterm, final);
    students[num_of_students] = newstudent;
    ++num_of_students;
}

void StudentManager::deleteStudent(int id) {
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getID() == id) {
            for (int j=i; j<num_of_students-1; j++) {
                Student s = students[j+1];
                students[j] = s;
            }
            --num_of_students;
            break;
        }
    }
}

void StudentManager::modifyStudent(const Student& student) {
    for (int i=0; i<num_of_students; i++) {
        if (student.getID() == students[i].getID()) {
            students[i] = student;
            break;
        }
    }
}

int StudentManager::findStudentByID(int id) const {
    for (int i=0; i<num_of_students; i++) {
        if (id == students[i].getID()) {
            return i; // 인덱스반환
        }
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    int bmid = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getMidterm() > students[bmid].getRecord().getMidterm()){
        bmid = i; // 인덱스반환
        }
    }
    return bmid;
}

int StudentManager::findBestStudentInFinal() const {
    int bfin = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getFinal() > students[bfin].getRecord().getFinal()){
        bfin = i; // 인덱스반환
        }
    }
    return bfin;
}

int StudentManager::findBestStudent() const {
    int bmid = 0;
    for (int i=0; i<num_of_students; i++) {
        if (students[i].getRecord().getMidterm()+students[i].getRecord().getFinal()
        > students[bmid].getRecord().getMidterm()+students[bmid].getRecord().getFinal()) {
        bmid = i;
        }
    }
    int ans = students[bmid].getID();// id반환
    return ans;
}

float StudentManager::getMidtermAverage() const {
    float smid = 0;
    if (num_of_students == 0) return 0.0f;
    for (int i=0; i<num_of_students; i++) {
        smid += students[i].getRecord().getMidterm();
    }
    float ans = smid/num_of_students;
    return ans;
}

float StudentManager::getFinalAverage() const {
    float sfin = 0;
    if (num_of_students == 0) return 0.0f;
    for (int i=0; i<num_of_students; i++) {
        sfin += students[i].getRecord().getFinal();
    }
    float ans = sfin/num_of_students;
    return ans;
}

float StudentManager::getTotalAverage() const {
    float ans = 0;
    if (num_of_students == 0) return 0.0f;
    for (int i=0; i<num_of_students; i++) {
        ans += students[i].getRecord().getTotal();
    }
    return ans/num_of_students;
}

