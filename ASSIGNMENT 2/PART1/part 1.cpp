//#Implement a simple C++ student management program. For this part, you only need to keep the information of each student's name.
//(1) Use C++ array data structure to store the list of all students' names.
//(2) Implement a function that allows users to add a new student to the list of all students.
//(3) Implement a function to display the list of all students.
//(4) Implement a function to remove a student from the list of all students based on the name input from the user. If the student name does not exist in the current list of all students, inform the user about that.
//(5) Use C++ WHILE loop to create a text-based menu that allows users to choose the above functionalities or to exit the program.

#include <iostream>
#include <string>
#include <cctype> //function isdigit
using namespace std;
const int maxStu = 10000;
string students[maxStu];
int studentCount = 0;
bool isValidName(const  string& name) {
    for (char ch : name) {
        if (isdigit(ch) || ispunct(ch)||iscntrl(ch)) { // Kiểm tra nếu không phải chữ cái và không phải khoảng trắng
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
void addStudent(const string& name) {
    if (studentCount >= maxStu) {
        cout << "Max student capacity reached." << endl;
        return;
    }
    if (!isValidName(name)) {
        cout << "Invalid name!" <<  endl;
        return;
    }
    // Kiểm tra tên trùng lặp không phân biệt hoa thường
     string lowerCaseName = toLowerCase(name);
    for (int i = 0; i < studentCount; i++) {
        if (toLowerCase(students[i]) == lowerCaseName) {
            cout << "Student already exists." << endl;
            return;
        }
    }
    students[studentCount++] = name;
    cout << "Student added successfully." << endl;
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "No students to display." << endl;
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        cout << i + 1 << ". " << students[i] << endl;
    }
}

void removeStudent(const string& name) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == name) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student removed successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void menu() {
    while (true) {
        cout << "\nStudent Management System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";

        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear(); // Xóa trạng thái lỗi của cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua phần còn lại của dòng
            cout << "Invalid input, please enter a number between 1 and 4." << endl;
            continue; // Quay lại đầu vòng lặp
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(choice) {
            case 1: {
                string name;
                cout << "Enter student's name: ";
                getline(cin, name);
                addStudent(name);
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
                return; // Thoát khỏi hàm và kết thúc chương trình
            }
            default: {
                cout << "Invalid choice, please enter a number between 1 and 4." << endl;
                break;
            }
        }
    }
}
int main() {
    menu();
    return 0;
}
