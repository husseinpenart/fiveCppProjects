#include "Student.h"

int main() {
	int choice;
	do {
		cout << "1. Add Student\n";
		cout << "2. Show Students\n";
		cout << "3. Edit Student\n";
		cout << "4. Delete Student\n";
		cout << "5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			addStudent();
			break;
		case 2:
			showStudents();
			break;
		case 3:
			editStudent();
			break;
		case 4:
			deleteStudent();
			break;
		case 5:
			cout << "Exiting program..." << endl;
			break;
		default:
			cout << "Invalid choice!" << endl;
		}
	} while (choice != 5);

	return 0;
}
