#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    Task newTask;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] "
             << tasks[i].description << "\n";
    }
    cout << endl;
}

void markTaskCompleted() {
    viewTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask() {
    viewTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void showMenu() {
    cout << "\n====== TO-DO LIST MANAGER ======\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option (1-5): ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting the To-Do List Manager.\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
