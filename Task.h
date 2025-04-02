#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Task
{
public:
	int id;
	string description;
	bool completed;

	Task(int i, string d, bool c = false);
	void display();
	void saveToFile();

};


void addTask();
void showTasks();
void editTask();
void deleteTask();


#endif