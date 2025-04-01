#include "Student.h"
#include <string>
using namespace std;



Student::Student(int i, string n, int a) {
	id = i;
	name = n;
	age = a;
}

void Student::display() {
	cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
}

void Student::saveToFile() {
	ofstream file("../students.txt", ios::app);
	if (file.is_open()) {
		file << id << " " << name << " " << age << endl;
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}

void addStudent() {
	int id, age;
	string name;

	cout << "Enter ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter Name: ";
	getline(cin, name);
	cout << "Enter Age: ";
	cin >> age;

	Student newStudent(id, name, age);
	newStudent.saveToFile();
}

void showStudents() {
	ifstream file("students.txt");
	int id, age;
	string name;

	if (file.is_open()) {
		while (file >> id >> name >> age) {
			Student student(id, name, age);
			student.display();
		}
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}


void editStudent() {
	int id, newAge;
	string newName;
	bool found = false;
	cout << "Enter the ID of the student to edit: ";
	cin >> id;
	cin.ignore();
	fstream file("../students.txt", ios::in | ios::out);
	if (file.is_open()) {
		vector<Student> students;
		int tempId, tempAge;
		string tempName;
		while (file >> tempId >> tempName >> tempAge) {
			students.push_back(Student(tempId, tempName, tempAge));
		}
		for (size_t i = 0; i < students.size(); i++) {
			if (students[i].id == id) {
				cout << "Enter new name: ";
				getline(cin, newName);
				cout << "Enter new age: ";
				cin >> newAge;
				students[i].name = newName;
				students[i].age = newAge;
				found = true;
				break;
			}
		}

		if (found) {
			file.clear();
			file.seekp(0, ios::beg);
			for (const auto& student : students) {
				file << student.id << " " << student.name << " " << student.age << endl;
			}
			cout << "Student information updated!" << endl;
		}
		else {
			cout << "Student with ID " << id << " not found." << endl;
		}
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;

	}

}

void deleteStudent() {
	int id;
	bool found = false;

	cout << "Enter the ID of the student to delete: ";
	cin >> id;
	fstream file("../students.txt", ios::in | ios::out);
	if (file.is_open()) {
		vector<Student> students;
		int tempId, tempAge;
		string tempName;

		while (file >> tempId >> tempName >> tempAge) {
			students.push_back(Student(tempId, tempName, tempAge));
		}
		for (size_t i = 0; i < students.size(); i++) {
			if (students[i].id == id) {
				students.erase(students.begin() + i);
				found = true;
				break;
			}
		}
		if (found) {
			file.clear();
			file.seekp(0, ios::beg);
			for (const auto& student : students) {
				file << student.id << " " << student.name << " " << student.age << endl;
			}
			cout << "Student deleted!" << endl;
		}
		else {
			cout << "Student with ID " << id << " not found." << endl;
		}
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;

	}
}