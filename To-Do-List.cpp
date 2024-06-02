#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to display the to-do list
void displayToDoList(const vector<string>& toDoList) {
    cout << "To-Do List:" << endl;
    if (toDoList.empty()) {
        cout << "Empty" << endl;
    } else {
        for (size_t i = 0; i < toDoList.size(); ++i) {
            cout << i + 1 << ". " << toDoList[i] << endl;
        }
    }
}

int main() {
    vector<string> toDoList;
    int choice;

    cout << "Welcome to the To-Do List Application!" << endl;

    do {
        cout << "\nMenu:\n1. Add Task\n2. Remove Task\n3. Display To-Do List\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore(); // Clear input buffer
                getline(cin, task);
                toDoList.push_back(task);
                cout << "Task added successfully!" << endl;
                break;
            }
            case 2: {
                if (toDoList.empty()) {
                    cout << "To-Do List is already empty." << endl;
                } else {
                    int index;
                    cout << "Enter the index of the task to remove: ";
                    cin >> index;
                    if (index >= 1 && index <= static_cast<int>(toDoList.size())) {
                        toDoList.erase(toDoList.begin() + index - 1);
                        cout << "Task removed successfully!" << endl;
                    } else {
                        cout << "Invalid index! Please enter a valid index." << endl;
                    }
                }
                break;
            }
            case 3:
                displayToDoList(toDoList);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid menu option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
