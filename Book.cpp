#include "Book.h"
#include <string>
Book::Book(int i, string t, string a) {
	id = i;
	title = t;
	author = a;
}

void Book::display() {
	cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
}

void Book::saveToFile() {
	ofstream file("../books.csv", ios::app);
	if (file.is_open()) {
		file << id << " " << title << " " << author << endl;
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}

void addBook() {
	int id;
	string title, author;

	cout << "Enter Book ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter Book Title: ";
	getline(cin, title);
	cout << "Enter Author: ";
	getline(cin, author);

	Book newBook(id, title, author);
	newBook.saveToFile();
}

void showBooks() {
	ifstream file("../books.csv");
	int id;
	string title, author;

	if (file.is_open()) {
		while (file >> id >> title >> author) {
			Book book(id, title, author);
			book.display();
		}
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}
void searchBook() {
	ifstream file("../books.csv");
	int id, searchId;
	string title, author;
	bool found = false;

	cout << "Enter Book ID to search: ";
	cin >> searchId;

	if (file.is_open()) {
		while (file >> id >> title >> author) {
			if (id == searchId) {
				cout << "Book Found!" << endl;
				cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
				found = true;
				break;
			}
		}
		file.close();

		if (!found) {
			cout << "Book not found!" << endl;
		}
	}
	else {
		cout << "Error opening file!" << endl;
	}
}


void deleteBook() {
	ifstream file("../books.csv");
	ofstream tempFile("../temp.csv"); // فایل موقت برای ذخیره کتاب‌های غیر حذف‌شده

	int id, deleteId;
	string title, author;
	bool found = false;

	cout << "Enter Book ID to delete: ";
	cin >> deleteId;

	if (file.is_open() && tempFile.is_open()) {
		while (file >> id >> title >> author) {
			if (id == deleteId) {
				cout << "Book deleted successfully!" << endl;
				found = true;
			}
			else {
				tempFile << id << " " << title << " " << author << endl;
			}
		}
		file.close();
		tempFile.close();

		if (found) {
			remove("../books.csv");           // حذف فایل اصلی
			rename("../temp.csv", "../books.csv"); // تغییر نام فایل موقت
		}
		else {
			cout << "Book not found!" << endl;
		}
	}
	else {
		cout << "Error opening file!" << endl;
	}
}


void editBook() {
	ifstream file("../books.csv");
	ofstream tempFile("../temp.csv");

	int id, editId;
	string title, author;
	string newTitle, newAuthor;
	bool found = false;

	cout << "Enter Book ID to edit: ";
	cin >> editId;

	if (file.is_open() && tempFile.is_open()) {
		while (file >> id >> title >> author) {
			if (id == editId) {
				cout << "Enter new Title: ";
				cin >> newTitle;
				cout << "Enter new Author: ";
				cin >> newAuthor;
				tempFile << id << " " << newTitle << " " << newAuthor << endl;
				cout << "Book updated successfully!" << endl;
				found = true;
			}
			else {
				tempFile << id << " " << title << " " << author << endl;
			}
		}
		file.close();
		tempFile.close();

		if (found) {
			remove("../books.csv");
			rename("../temp.csv", "../books.csv");
		}
		else {
			cout << "Book not found!" << endl;
		}
	}
	else {
		cout << "Error opening file!" << endl;
	}
}
