#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string n, int s) : name(n), score(s) {}
    ~Student() {} // Destructor
};
const int initial = 10;
Student** student = new Student*[initial];
int listSize = 0;
int capacity = initial;
bool isValidName(const string& name) {
    for (char ch : name) {
        if (isdigit(ch) || ispunct(ch) || iscntrl(ch)) {
            return false;
        }
    }
    return true;
}
string toLowerCase(const string& str) {
    string lowerCaseStr = str;
    for (char& ch : lowerCaseStr) {
        ch = tolower(ch);
    }
    return lowerCaseStr;
}
void resize() {
    capacity *= 2;
    auto** newArr = new Student*[capacity];
    for (int i = 0; i < listSize; i++) {
        newArr[i] = student[i];
    }
    delete[] student;
    student = newArr;
}
void addStudent(const string& name, int score) {
    for (int i = 0; i < listSize; i++) {
        if (student[i]->name == name) {
            cout << "A student with the same name already exists." << endl;
            return;
        }
    }
    if (listSize == capacity) {
        resize();
    }
    student[listSize++] = new Student(name, score);
    cout << "Student added successfully." << endl;
}

void displayStudents() {
    if (listSize == 0) {
        cout << "No student to display." << endl;
        return;
    }
    for (int i = 0; i < listSize; i++) {
        cout << student[i]->name << " - " << student[i]->score << endl;
    }
}

void removeStudent(const string& name) {
    int idxRemove = -1;
    for (int i = 0; i < listSize; i++) {
        if (toLowerCase(student[i]->name) == toLowerCase(name)) {
            idxRemove = i;
            break;
        }
    }

    if (idxRemove == -1) {
        cout << "Student not found." << endl;
    } else {
        delete student[idxRemove]; // Delete the student object to free memory
        for (int j = idxRemove; j < listSize - 1; j++) {
            student[j] = student[j + 1];
        }
        listSize--;
        cout << "Student removed successfully." << endl;
    }
}

void displayTop() {
    if (listSize == 0) {
        cout << "No student to display." << endl;
        return;
    }
    int highestScore = student[0]->score;
    for (int i = 1; i < listSize; i++) {
        if (student[i]->score > highestScore) {
            highestScore = student[i]->score;
        }
    }
    cout << "Top student(s) with the highest score of " << highestScore << ":" << endl;
    for (int i = 0; i < listSize; i++) {
        if (student[i]->score == highestScore) {
            cout << student[i]->name << " - " << student[i]->score << endl;
        }
    }
}

void menu() {
    while (true) {
        cout << "\n1. Add Student\n2. Display All Students\n3. Remove Student\n4. Display Top Students\n5. Exit\nSelect an option: ";
        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number between 1 and 5." << endl;
            continue;
        }
        if (choice == 5) break;
        string name;
        int score;

        switch (choice) {
            case 1:
                cout << "Enter student's name: ";
                cin >> ws; // To consume any leading whitespace
                getline(cin, name); // Correctly reads the student's name

                if (!isValidName(name)) {
                    cout << "Invalid name entered. Please ensure the name contains only letters and spaces." << endl;
                    break; // Exit this case; you might want to loop or handle this differently
                }

                cout << "Enter student's score (0-100): ";
                while (true) { // Keep asking until a valid score is entered
                    cin >> score;
                    if (cin.fail() || score < 0 || score > 100) { // Check if the input is not an integer or out of range
                        cin.clear(); // Clears the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the line
                        cout << "Invalid score, please enter a numeric value between 0 and 100: ";
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Correct input; clear the buffer
                        break; // Valid score entered; proceed
                    }
                }
                addStudent(name, score);
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Enter student's name to remove: ";
                cin >> ws;
                getline(cin, name);
                removeStudent(name);
                break;
            case 4:
                displayTop();
                break;
            default:
                cout << "Invalid choice, please enter a number between 1 and 5." << endl;
                break;
        }
    }

    // Cleanup
    for (int i = 0; i < listSize; i++) {
        delete student[i];
    }
    delete[] student;
}

int main() {
    menu();
    return 0;
}
