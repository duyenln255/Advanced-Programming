//Improve the simple C++ student management program from Part 1. For this part, you need to keep the information of each
// student's name and their score in two separate dynamically allocated arrays using pointers.
//(1) Use C++ dynamic array data structure using pointers to store two lists of all students' names and students' scores,
// 1 list for students' names & 1 list for student' scores.
//(2) Implement a function that allows users to add a new student and the corresponding score to the two above lists.
//(3) Implement a function to display the list of all students and the scores.
//(4) Implement a function to display the best student(s)'s name(s) and their score(s) (there could be more than one
// student who has the same highest score).
//(5) Use C++ WHILE loop to create a text-based menu that allows users to choose the above functionalities or to exit
// the program.
#include <iostream>
#include <string>
#include <limits>
#include <cctype> // For isdigit, ispunct, and iscntrl
using namespace std;

const int maxStu = 10000;
string* nameList = new string[maxStu]; // Mảng động cho tên
int* scoreList = new int[maxStu]; // Mảng động cho điểm số
int currNum = 0;

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

void addStudent(const string& name, int score) {
    if (currNum >= maxStu) {
        cout << "Maximum capacity reached." << endl;
        return;
    }
    if (!isValidName(name)) {
        cout << "Invalid name! Only letters and spaces are accepted." << endl;
        return;
    }

    string lowerCaseName = toLowerCase(name);
    for (int i = 0; i < currNum; i++) {
        if (toLowerCase(nameList[i]) == lowerCaseName) {
            cout << "Student already exists." << endl;
            return;
        }
    }

    nameList[currNum] = name;
    scoreList[currNum] = score;
    currNum++;
    cout << "Student added successfully." << endl;
}

void displayStudents() {
    if (currNum == 0) {
        cout << "No students to display." << endl;
        return;
    }
    cout << "Student List - Score"<<endl;
    for (int i = 0; i < currNum; i++) {
        cout << i + 1 << ". " << nameList[i] << " - " << scoreList[i] << endl;
    }
}

void removeStudent(const string& name) {
    for (int i = 0; i < currNum; i++) {
        if (toLowerCase(nameList[i]) == toLowerCase(name)) {
            for (int j = i; j < currNum - 1; j++) {
                nameList[j] = nameList[j + 1];
                scoreList[j] = scoreList[j + 1];
            }
            currNum--;
            cout << "Student removed successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}
void displayTop() {
    if (currNum == 0) {
        cout << "No students to display." << endl;
        return;
    }
    int highestScore = scoreList[0];
    for (int i = 1; i < currNum; i++) {
        if (scoreList[i] > highestScore) {
            highestScore = scoreList[i];
        }
    }
    cout << "Top student(s) with the highest score of " << highestScore << ":" << endl;
    for (int i = 0; i < currNum; i++) {
        if (scoreList[i] == highestScore) {
            cout << nameList[i] << " - " << scoreList[i] << endl;
        }
    }
}

void menu() {
    while (true) {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students and Their scores" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Display Top Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Select an option: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number between 1 and 5." << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Prevents getline from skipping

        switch(choice) {
            case 1: {
                string name;
                int score;
                cout << "Enter student's name: ";
                getline(cin, name);
                cout << "Enter student's score: ";
                cin >> score;
                while(cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid score, please enter a numeric value: ";
                    cin >> score;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addStudent(name, score);
                break;
            }
            case 2: {
                displayStudents();
                break;
            }
            case 3: {
                string name;
                cout << "Enter student's name to remove: ";
                getline(cin, name);
                removeStudent(name);
                break;
            }
            case 4: {
                displayTop();
                break;
            }
            case 5: {
                delete[] nameList;
                delete[] scoreList;
                return; // Exit program
            }
            default: {
                cout << "Invalid choice, please enter a number between 1 and 5." << endl;
                break;
            }
        }
    }
}
int main() {
    menu();
    return 0;
}
