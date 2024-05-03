//PART 4
//Improve the simple C++ student management program from Part 3. For this part, you need to create a new class University.
// The two main private member attributes of this class are the university name and the list of the student. Bring all
// the features of Part 3 to the University class as methods; also keep the WHILE loop in the main function. Make sure
// to have appropriate scope (private, protected, public) for the methods of the
//University class; some of them need to be public so they can be invoked from the WHILE loop in the main function.
// Created byLê Ngọc Duyên on 18/03/2024.
//
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student {
public:
    string name;
    int score;
    Student(string n, int s) : name(n), score(s) {}
    ~Student(){}
};

class University {
private:
    Student** student;
    int listSize, capacity;
    string universityName;

    void resize() {
        capacity *= 2;
        auto** newArr = new Student*[capacity];
        for (int i = 0; i < listSize; i++) {
            newArr[i] = student[i];
        }
        delete[] student;
        student = newArr;
    }

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

public:
    University(string name) : universityName(name), student(new Student*[10]), listSize(0), capacity(10) {}

    ~University() {
        for (int i = 0; i < listSize; i++) {
            delete student[i];
        }
        delete[] student;
    }

    void addStudent(const string& name, int score) {
        if (!isValidName(name)) {
            cout << "Invalid name entered. Please ensure the name contains only letters and spaces." << endl;
            return;
        }
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
            delete student[idxRemove];
            for (int j = idxRemove; j < listSize - 1; j++) {
                student[j] = student[j + 1];
            }
            listSize--;
            cout << "Student removed successfully." << endl;
        }
    }
    void displayTopStudents() {
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
};
void menu(University& uni) {
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
                cin >> ws;
                getline(cin, name);
                cout << "Enter student's score (0-100): ";
                while (true) {
                    cin >> score;
                    if (cin.fail() || score < 0 || score > 100) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid score, please enter a numeric value between 0 and 100: ";
                    } else {
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        break;
                    }
                }
                uni.addStudent(name, score);
                break;
            case 2:
                uni.displayStudents();
                break;
            case 3:
                cout << "Enter student's name to remove: ";
                cin >> ws;
                getline(cin, name);
                uni.removeStudent(name);
                break;
            case 4:
                uni.displayTopStudents();
                break;
            default:
                cout << "Invalid choice, please enter a number between 1 and 5." << endl;
                break;
        }
    }
}
int main() {
    University uni("HCMUT");
    menu(uni);
    return 0;
}