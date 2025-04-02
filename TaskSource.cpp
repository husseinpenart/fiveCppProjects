#include "Task.h"

int main() {
    int choice;
    do {
        cout << "\n1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            showTasks();
            break;
        case 3:
            editTask();
            break;
        case 4:
            deleteTask();
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
