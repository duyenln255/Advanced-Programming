//PART 6
//Improve the simple C++ student management program from Part 5.
//From Part 5, you have already created two new classes UniStudent and CollegeStudent derived from the existing class Student.
//For this Part 6, you need to utilize C++ polymorphism to implement the three functions DoAssignment, TakeTest and TakeExam
// for all the students. Essentially, calling these functions will randomly assign scores for all the assignments, tests and
// exams of all the courses of all the assignments of a student. However, the implementation for these functions are different
// for UniStudent and CollegeStudent due to their different numbers of semesters, courses, and assessments. Since this program
// manages all the students in one dynamic array of pointers to the base class Student, polymorphism is required to have correct
// function calls for different types of students.
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

bool isValidName(const string& input) {
    for (auto ch : input) {
        if (isdigit(ch) || ispunct(ch) || iscntrl(ch)) return false;
    }
    return true;
}

bool isValidDOB(const string& dob) {
    for (auto ch : dob) {
        if (!isdigit(ch) && !isspace(ch)) return false;
    }
    return true;
}

class Student {
public:
    string name, dob, schoolName, courseName;

    Student(string n, string dob, string schoolName, string courseName)
            : name(n), dob(dob), schoolName(schoolName), courseName(courseName) {}

    virtual ~Student() {}
    virtual void displayInfo() = 0;
    virtual void simulateAcademicActivities() = 0;

protected:
    static int generateScore(int min = 0, int max = 100) {
        return rand() % (max - min + 1) + min;
    }
};

class UniStudent : public Student {
public:
    UniStudent(string n, string dob, string schoolName, string courseName)
            : Student(n, dob, schoolName, courseName) {}

    void displayInfo() override {
        cout << "University Student: " << name << ", DOB: " << dob << ", School: " << schoolName << endl;
    }

    void simulateAcademicActivities() override {
        for (int sem = 1; sem <= 8; ++sem) {
            for (int course = 1; course <= 4; ++course) {
                cout << "Semester " << sem << ", Course " << course << ": ";
                cout << "Assignment Score: ";
                for (int assign = 0; assign < 3; ++assign) {
                    cout << generateScore() << (assign < 2 ? ", " : "; ");
                }
                cout << "Test Score: ";
                for (int test = 0; test < 2; ++test) {
                    cout << generateScore() << (test < 1 ? ", " : "; ");
                }
                cout << "Exam Score: " << generateScore() << endl;
            }
        }
    }
};

class CollegeStudent : public Student {
public:
    CollegeStudent(string n, string dob, string schoolName, string courseName)
            : Student(n, dob, schoolName, courseName) {}

    void displayInfo() override {
        cout << "College Student: " << name << ", DOB: " << dob << ", School: " << schoolName << endl;
    }

    void simulateAcademicActivities() override {
        for (int sem = 1; sem <= 4; ++sem) {
            for (int course = 1; course <= 3; ++course) {
                cout << "Semester " << sem << ", Course " << course << ": ";
                cout << "Assignment Score: " << generateScore() << ", ";
                cout << "Test Score: " << generateScore() << ", ";
                cout << "Exam Score: " << generateScore() << endl;
            }
        }
    }
};

class University {
private:
    vector<Student*> students;
    string universityName;

public:
    University(string name) : universityName(name) {}

    ~University() {
        for (auto student : students) {
            delete student;
        }
    }

    void addStudent() {
        string type, name, dob, schoolName, courseName;
        cout << "Enter student type (Uni/College): ";
        while (true) {
            getline(cin, type);
            for (auto & c: type) c = toupper(c);
            if (type == "UNI" || type == "COLLEGE") break;
            cout << "Invalid student type. Please enter 'Uni' or 'College': ";
        }

        cout << "Enter student's name: ";
        while (getline(cin, name) && !isValidName(name)) {
            cout << "Invalid name. Please enter a valid name: ";
        }

        cout << "Enter student's DOB (digits and spaces only): ";
        while (getline(cin, dob) && !isValidDOB(dob)) {
            cout << "Invalid DOB. Please enter a valid DOB: ";
        }

        cout << "Enter student's School Name: ";
        while (getline(cin, schoolName) && !isValidName(schoolName)) {
            cout << "Invalid school name. Please enter a valid school name: ";
        }

        cout << "Enter student's Course Name: ";
        while (getline(cin, courseName) && !isValidName(courseName)) {
            cout << "Invalid course name. Please enter a valid course name: ";
        }

        if (type == "UNI") {
            students.push_back(new UniStudent(name, dob, schoolName, courseName));
        } else {
            students.push_back(new CollegeStudent(name, dob, schoolName, courseName));
        }
        cout << "Student added successfully." << endl;
    }

    void simulateAcademicActivities() {
        if (students.empty()) {
            cout << "No students to simulate." << endl;
            return;
        }
        for (auto student : students) {
            student->displayInfo();
            student->simulateAcademicActivities();
        }
    }
};

void menu(University& uni) {
    srand(static_cast<unsigned int>(time(nullptr))); // Initialize random seed

    while (true) {
        cout << "\n1. Add Student\n2. Simulate Academic Activities\n3. Exit\nSelect an option: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer

        if (choice == 3) break;

        switch (choice) {
            case 1:
                uni.addStudent();
                break;
            case 2:
                uni.simulateAcademicActivities();
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
                break;
        }
    }
}

int main() {
    University uni("My University");
    menu(uni);
    return 0;
}
