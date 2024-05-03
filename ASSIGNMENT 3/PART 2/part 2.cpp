#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
#include <limits>

using namespace std;

struct Course {
    string subjectName;
    vector<int> assignments;
    vector<int> tests;
    int exam;

    Course(string subName, int numAssignments, int numTests, int hasExam)
            : subjectName(subName), exam(hasExam ? -1 : 0) {
        assignments.resize(numAssignments, -1);
        tests.resize(numTests, -1);
    }
};

bool isValidName(const string& name) {
    for (char ch : name) {
        if (isdigit(ch) || ispunct(ch) || iscntrl(ch)) {
            return false;
        }
    }
    return true;
}

bool isValidID(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool isValidDOB(const string& str) {
    for (char ch : str) {
        if (!(isdigit(ch) || ch == '/' || ch == '-' || ch == ' ')) {
            return false;
        }
    }
    return true;
}

class Student {
protected:
    string name, dob, schoolName, courseName;
    int score;
    vector<vector<Course>> semesters;
    bool dataSimulated = false;

public:
    Student(string n, string d, string sN, string cN, int sc, vector<vector<Course>> sems)
            : name(n), dob(d), schoolName(sN), courseName(cN), score(sc), semesters(sems) {}
    virtual ~Student() {}
    virtual void displayInfo() = 0;
    virtual void simulateAcademicActivities() = 0;
    virtual void displayAcademicRecord() = 0;
    virtual void customizeCourses() = 0;
};

class UniStudent : public Student {
public:
    UniStudent(string n, string d, string sN, string cN, int sc, vector<vector<Course>> sems) : Student(n, d, sN, cN, sc, sems) {}
    void displayInfo() override {
        cout << "Student Name: " << name << ", DOB: " << dob
             << ", School Name: " << schoolName << ", Major: " << courseName
             << ", Score: " << score << endl;
    }
    void simulateAcademicActivities() override {
        dataSimulated = true;
        for (auto& semester : semesters) {
            for (auto& course : semester) {
                for (auto& assignment : course.assignments) {
                    assignment = rand() % 100 + 1;
                }
                for (auto& test : course.tests) {
                    test = rand() % 100 + 1;
                }
                course.exam = rand() % 100 + 1;
            }
        }
    }
    void displayAcademicRecord() override {
        cout << "Type: University student" << endl;
        cout << "+----------+------------------+--------------+--------------+--------------+----------+----------+----------+" << endl;
        cout << "| Semester | Subject          | Assignment 1 | Assignment 2 | Assignment 3 | Test 1   | Test 2   | Exam 1   |" << endl;
        cout << "+----------+------------------+--------------+--------------+--------------+----------+----------+----------+" << endl;
        for (int i = 0; i < semesters.size(); ++i) {
            for (int j = 0; j < semesters[i].size(); ++j) {
                cout << "| " << setw(8) << i + 1 << " | " << setw(16) << semesters[i][j].subjectName << " |";
                cout << setw(13) << (dataSimulated ? semesters[i][j].assignments[0] : -1) << " |";
                cout << setw(13) << (dataSimulated ? semesters[i][j].assignments[1] : -1) << " |";
                cout << setw(13) << (dataSimulated ? semesters[i][j].assignments[2] : -1) << " |";
                cout << setw(9) << (dataSimulated ? semesters[i][j].tests[0] : -1) << " |";
                cout << setw(9) << (dataSimulated ? semesters[i][j].tests[1] : -1) << " |";
                cout << setw(9) << (dataSimulated ? semesters[i][j].exam : -1) << " |";
                cout << endl;
            }
        }
        cout << "+----------+------------------+--------------+--------------+--------------+----------+----------+----------+" << endl;
    }
    void customizeCourses() override {
        for (auto& semester : semesters) {
            for (auto& course : semester) {
                cout << "Current Course Name: " << course.subjectName << endl;
                cout << "Enter new name for this course: ";
                getline(cin, course.subjectName);
                while (!isValidName(course.subjectName)) {
                    cout << "Invalid name. Please enter a valid course name: ";
                    getline(cin, course.subjectName);
                }
            }
        }
    }
};

class CollegeStudent : public Student {
public:
    CollegeStudent(string n, string d, string sN, string cN, int sc, vector<vector<Course>> sems) : Student(n, d, sN, cN, sc, sems) {}
    void displayInfo() override {
        cout << "Student Name: " << name << ", DOB: " << dob
             << ", School Name: " << schoolName << ", Major: " << courseName
             << ", Score: " << score << endl;
    }
    void simulateAcademicActivities() override {
        dataSimulated = true;
        for (auto& semester : semesters) {
            for (auto& course : semester) {
                course.assignments[0] = rand() % 100 + 1;
                course.tests[0] = rand() % 100 + 1;
                course.exam = rand() % 100 + 1;
            }
        }
    }
    void displayAcademicRecord() override {
        cout << "Type: College student" << endl;
        cout << "+----------+------------------+--------------+----------+----------+" << endl;
        cout << "| Semester | Subject          | Assignment 1 | Test 1   | Exam 1   |" << endl;
        cout << "+----------+------------------+--------------+----------+----------+" << endl;
        for (int i = 0; i < semesters.size(); ++i) {
            for (int j = 0; j < semesters[i].size(); ++j) {
                cout << "| " << setw(8) << i + 1 << " | " << setw(16) << semesters[i][j].subjectName << " |";
                cout << setw(13) << (dataSimulated ? semesters[i][j].assignments[0] : -1) << " |";
                cout << setw(9) << (dataSimulated ? semesters[i][j].tests[0] : -1) << " |";
                cout << setw(9) << (dataSimulated ? semesters[i][j].exam : -1) << " |";
                cout << endl;
            }
        }
        cout << "+----------+------------------+--------------+----------+----------+" << endl;
    }
    void customizeCourses() override {
        for (auto& semester : semesters) {
            for (auto& course : semester) {
                cout << "Current Course Name: " << course.subjectName << endl;
                cout << "Enter new name for this course: ";
                getline(cin, course.subjectName);
                while (!isValidName(course.subjectName)) {
                    cout << "Invalid name. Please enter a valid course name: ";
                    getline(cin, course.subjectName);
                }
            }
        }
    }
};

class StudentFactory {
public:
    static Student* createStudent(const string& type, string n, string d, string sN, string cN, int sc, vector<vector<Course>> sems) {
        if (type == "Uni" || type == "uni") {
            return new UniStudent(n, d, sN, cN, sc, sems);
        } else if (type == "College" || type == "college") {
            return new CollegeStudent(n, d, sN, cN, sc, sems);
        } else {
            return nullptr;
        }
    }
};

map<string, Student*> students;

void addStudent() {
    string id, type, name, dob, schoolName, courseName;
    int score;
    cout << "Enter student type (Uni/College): ";
    getline(cin, type);
    while (type != "Uni" && type != "uni" && type != "College" && type != "college") {
        cout << "Invalid type. Please enter 'Uni' or 'College': ";
        getline(cin, type);
    }
    cout << "Enter student ID: ";
    getline(cin, id);
    while (!isValidID(id)) {
        cout << "Invalid ID. Please enter a valid ID: ";
        getline(cin, id);
    }
    while (students.find(id) != students.end()) {
        cout << "Student ID already exists. Please use a different ID." << endl;
        getline(cin, id);
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

    cout << "Enter student's major name: ";
    getline(cin, courseName);
    while (!isValidName(courseName)) {
        cout << "Invalid course name. Please enter a valid major name: ";
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

    vector<vector<Course>> semesters;
    int numSemesters = (type == "Uni" || type == "uni") ? 8 : 4;
    int numCoursesPerSemester = (type == "Uni" || type == "uni") ? 4 : 3;
    int numAssignments = (type == "Uni" || type == "uni") ? 3 : 1;
    int numTests = (type == "Uni" or type == "uni") ? 2 : 1;

    semesters.resize(numSemesters);
    for (int i = 0; i < numSemesters; i++) {
        vector<Course> semesterCourses;
        for (int j = 0; j < numCoursesPerSemester; j++) {
            semesterCourses.emplace_back("Course " + to_string(j + 1), numAssignments, numTests, 1);
        }
        semesters[i] = semesterCourses;
    }

    students[id] = StudentFactory::createStudent(type, name, dob, schoolName, courseName, score, semesters);
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "No students to display." << endl;
        return;
    }
    for (const auto& pair : students) {
        pair.second->displayInfo();
        pair.second->displayAcademicRecord();
    }
}

void simulateAcademicActivities() {
    if (students.empty()) {
        cout << "No students to simulate." << endl;
        return;
    }
    for (const auto& pair : students) {
        pair.second->simulateAcademicActivities();
    }
    cout << "Simulation complete.\n";
}

void customizeCourseNames() {
    if (students.empty()) {
        cout << "No students to customize." << endl;
        return;
    }
    for (const auto& pair : students) {
        pair.second->customizeCourses();
    }
    cout << "Courses updated.\n";
}

void menu() {
    srand(time(nullptr)); // Initialize random seed for simulations

    string option;
    while (true) {
        cout << "\n1. Add Student\n2. Display All Students\n3. Simulate Academic Activities\n4. Customize Course Names\n5. Exit\nSelect an option: ";
        getline(cin, option);

        if (option == "1") {
            addStudent();
        } else if (option == "2") {
            displayStudents();
        } else if (option == "3") {
            simulateAcademicActivities();
            displayStudents(); // Displaying students after simulation to show updated scores
        } else if (option == "4") {
            customizeCourseNames();
        } else if (option == "5") {
            break; // Exit the program
        } else {
            cout << "Invalid option. Please choose a valid option." << endl;
        }
    }

    // Cleanup memory when exiting the program
    for (auto& pair : students) {
        delete pair.second;
    }
    students.clear();
}

int main() {
    menu();
    return 0;
}
