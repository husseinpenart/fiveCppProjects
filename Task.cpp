#include <string>
#include "Task.h"
Task::Task(int i, string d, bool c) {
	id = i;
	description = d;
	completed = c;
}

void Task::display() {
	cout << "ID: " << id << " - " << (completed ? "[✓]" : "[ ]") << " " << description << endl;
}

void Task::saveToFile() {
	ofstream file("../tasks.txt", ios::app);
	if (file.is_open()) {
		file << id << " " << completed << " " << description << endl;
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}

void addTask() {
	int id;
	string description;

	cout << "Enter Task ID: ";
	cin >> id;
	cin.ignore();
	cout << "Enter Task Description: ";
	getline(cin, description);

	Task newTask(id, description);
	newTask.saveToFile();
}


void showTasks() {
	ifstream file("../tasks.txt");
	int id;
	bool completed;
	string description;

	if (file.is_open()) {
		while (file >> id >> completed) {
			file.ignore();
			getline(file, description);
			Task task(id, description, completed);
			task.display();
		}
		file.close();
	}
	else {
		cout << "Error opening file!" << endl;
	}
}


void editTask() {
    ifstream file("../tasks.txt");
    vector<Task> tasks;
    int id, editID;
    bool completed;
    string description;

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (file >> id >> completed) {
        file.ignore();
        getline(file, description);
        tasks.push_back(Task(id, description, completed));
    }
    file.close();

    cout << "Enter Task ID to Edit: ";
    cin >> editID;
    cin.ignore();

    bool found = false;
    for (Task& task : tasks) {
        if (task.id == editID) {
            found = true;
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Is completed? (1: Yes, 0: No): ";
            cin >> task.completed;
            cin.ignore();
            break;
        }
    }

    if (!found) {
        cout << "Task not found!" << endl;
        return;
    }

    ofstream outFile("../tasks.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (const Task& task : tasks) {
        outFile << task.id << " " << task.completed << " " << task.description << endl;
    }
    outFile.close();
    cout << "Task updated successfully!" << endl;
}
void deleteTask() {
    ifstream file("../tasks.txt");
    vector<Task> tasks;
    int id, deleteID;
    bool completed;
    string description;

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (file >> id >> completed) {
        file.ignore();
        getline(file, description);
        tasks.push_back(Task(id, description, completed));
    }
    file.close();

    cout << "Enter Task ID to Delete: ";
    cin >> deleteID;
    cin.ignore();

    // حذف کار موردنظر
    bool found = false;
    vector<Task> newTasks;
    for (const Task& task : tasks) {
        if (task.id == deleteID) {
            found = true;
            continue;
        }
        newTasks.push_back(task);
    }

    if (!found) {
        cout << "Task not found!" << endl;
        return;
    }

    ofstream outFile("../tasks.txt");
    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (const Task& task : newTasks) {
        outFile << task.id << " " << task.completed << " " << task.description << endl;
    }
    outFile.close();
    cout << "Task deleted successfully!" << endl;
}
