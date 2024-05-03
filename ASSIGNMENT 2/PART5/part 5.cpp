//PART 5
//Improve the simple C++ student management program from Part 4. For this part, you need to create two new classes UniStudent and CollegeStudent derived from the existing class Student. While both types of students have similar attributes like names, day of births, school names, course names; there are differences between uni students and college students. Uni students have 8 semesters, and each semester has 4 courses, and each course has 3 assignments, 2 tests and 1 exam. College students have only 4 semesters, each semester has 3 courses, and each course has 1 assignment, 1 test and 1 exam.
//You need to appropriately decide the common attributes/methods and the distinguished attributes/methods for the parent class Student and its two child classes UniStudent and CollegeStudent.
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

using namespace std;

bool isValidName(const string& str) {
    for (char ch : str) {
        if (!(isalpha(ch) || isspace(ch))) {
            return false;
        }
    }
    return true;
}

bool isValidDOB(const string& str) {
    // Simplistic check for valid DOB format
    for (char ch : str) {
        if (!(isdigit(ch) || ch == '/')) {
            return false;
        }
    }
    return true;
}

class Student {
protected:
    string name, dob, schoolName, courseName;
    int score;

public:
    Student(string n, string d, string sN, string cN, int sc)
            : name(n), dob(d), schoolName(sN), courseName(cN), score(sc) {}

    virtual ~Student() {}

    virtual void displayInfo() {
        cout << "Student Name: " << name << ", DOB: " << dob
             << ", School Name: " << schoolName << ", Course Name: " << courseName
             << ", Score: " << score << endl;
    }

    virtual void simulateAcademicActivities() = 0;
};

class UniStudent : public Student {
public:
    UniStudent(string n, string d, string sN, string cN, int sc) : Student(n, d, sN, cN, sc) {}

    void simulateAcademicActivities() override {
        cout << "University Student Academic Activities Simulation for " << name << ":" << endl;
        for (int semester = 1; semester <= 8; ++semester) {
            for (int course = 1; course <= 4; ++course) {
                cout << "Semester " << semester << ", Course " << course << ": ";
                cout << "Assignments[";
                for (int assignment = 1; assignment <= 3; ++assignment) {
                    cout << (assignment > 1 ? ", " : "") << (rand() % 100 + 1);
                }
                cout << "], Tests[";
                for (int test = 1; test <= 2; ++test) {
                    cout << (test > 1 ? ", " : "") << (rand() % 100 + 1);
                }
                cout << "], Exam: " << (rand() % 100 + 1) << endl;
            }
        }
    }
};

class CollegeStudent : public Student {
public:
    CollegeStudent(string n, string d, string sN, string cN, int sc) : Student(n, d, sN, cN, sc) {}

    void simulateAcademicActivities() override {
        cout << "College Student Academic Activities Simulation for " << name << ":" << endl;
        for (int semester = 1; semester <= 4; ++semester) {
            for (int course = 1; course <= 3; ++course) {
                cout << "Semester " << semester << ", Course " << course << ": ";
                cout << "Assignment: " << (rand() % 100 + 1);
                cout << ", Test: " << (rand() % 100 + 1);
                cout << ", Exam: " << (rand() % 100 + 1) << endl;
            }
        }
    }
};

vector<Student*> students;

void addStudent() {
    string type, name, dob, schoolName, courseName;
    int score;

    cout << "Enter student type (Uni/College): ";
    getline(cin, type);
    while (type != "Uni" && type != "uni" && type != "College" && type != "college") {
        cout << "Invalid type. Please enter 'Uni' or 'College': ";
        getline(cin, type);
    }

    cout << "Enter student's name: ";
    getline(cin, name);
    while (!isValidName(name)) {
        cout << "Invalid name. Please enter a valid name: ";
        getline(cin, name);
    }

    cout << "Enter student's DOB (dd/mm/yyyy): ";
    getline(cin, dob);
    while (!isValidDOB(dob)) {
        cout << "Invalid DOB. Please enter a valid DOB: ";
        getline(cin, dob);
    }

    cout << "Enter student's school name: ";
    getline(cin, schoolName);
    while (!isValidName(schoolName)) {
        cout << "Invalid school name. Please enter a valid school name: ";
        getline(cin, schoolName);
    }

    cout << "Enter student's course name: ";
    getline(cin, courseName);
    while (!isValidName(courseName)) {
        cout << "Invalid course name. Please enter a valid course name: ";
        getline(cin, courseName);
    }

    cout << "Enter student's score: ";
    cin >> score;
    while (cin.fail() || score < 0 || score > 100) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid score. Please enter a score between 0 and 100: ";
        cin >> score;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer

    if (type == "Uni" || type == "uni") {
        students.push_back(new UniStudent(name, dob, schoolName, courseName, score));
    } else {
        students.push_back(new CollegeStudent(name, dob, schoolName, courseName, score));
    }
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }
    for (auto* student : students) {
        student->displayInfo();
    }
}

void simulateAcademicActivities() {
    if (students.empty()) {
        cout << "No students to simulate." << endl;
        return;
    }
    for (auto* student : students) {
        student->simulateAcademicActivities();
    }
}

void menu() {
    srand(time(nullptr)); // Initialize random seed

    string option;
    while (true) {
        cout << "\n1. Add Student\n2. Display All Students\n3. Simulate Academic Activities\n4. Exit\nSelect an option: ";
        getline(cin, option);

        if (option == "1") {
            addStudent();
        } else if (option == "2") {
            displayStudents();
        } else if (option == "3") {
            simulateAcademicActivities();
        } else if (option == "4") {
            break;
        } else {
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    }

    // Cleanup
    for (Student* student : students) {
        delete student;
    }
    students.clear();
}

int main() {
    menu();
    return 0;
}
