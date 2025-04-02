#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;

    Book(int i, string t, string a);
    void display();
    void saveToFile();
};

void addBook();
void showBooks();
void searchBook();
void deleteBook();
void editBook(); 

#endif
