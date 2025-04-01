#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Student {
public:
	int id;
	string name;
	int age;

	Student(int i, string n, int a);
	void display();
	void saveToFile();
};

void addStudent();
void showStudents();
void editStudent();
void deleteStudent();
#endif
