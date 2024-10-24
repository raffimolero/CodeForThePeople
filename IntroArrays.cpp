#include <iostream>
#include <string>

/*
Kromyko 90 Lorelee 120 Bryan 0 Vincent 85 Alvin 98
*/

using namespace std;

const int MAX_STUDENTS = 5;
const double MAX_GRADE = 98.0;
const double MIN_GRADE = 75.0;

void displayStudents(string names[], double grades[]);
double calculateAverage(double grades[]);
void findMinMax(double grades[], double& minGrade, double& maxGrade);
void findStudent(string names[], double grades[], string& studentName);

int main() {
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    string studentNames[MAX_STUDENTS];
    double studentGrades[MAX_STUDENTS];

    double minGrade, maxGrade;
    double grade;
    string name;
    char choice;

    cout << "Enter the names and grades of " << MAX_STUDENTS << " students:\n";
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> studentNames[i];
        cout << "Grade: ";
        cin >> grade;
        studentGrades[i] = max(MIN_GRADE, min(grade, MAX_GRADE));
    }

    do {
        cout << "\n--- Student Grade Management Menu ---" << endl;
        cout << "[D]isplay all students and grades" << endl;;
        cout << "[C]alculate average grade" << endl;
        cout << "[F]ind highest and lowest grades" << endl;;
        cout << "[S]earch for a student's grade" << endl;
        cout << "[A] Show all displays D,C, & F" << endl;
        cout << "[E]xit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 'D':
        case 'd':
            displayStudents(studentNames, studentGrades);
            break;

        case 'C':
        case 'c':
            cout << "Average Grade: " << calculateAverage(studentGrades) << endl;
            break;

        case 'F':
        case 'f':
            findMinMax(studentGrades, minGrade, maxGrade);
            cout << "Highest Grade: " << maxGrade << "\nLowest Grade: " << minGrade << endl;
            break;

        case 'S':
        case 's':
            cout << "Enter student name to search: ";
            cin >> name;
            findStudent(studentNames, studentGrades, name);
            break;

        case 'A':
        case 'a':
            displayStudents(studentNames, studentGrades);
            cout << endl;
            findMinMax(studentGrades, minGrade, maxGrade);
            cout << "Highest Grade: " << maxGrade << "\nLowest Grade: " << minGrade << endl;
            cout << "Average Grade: " << calculateAverage(studentGrades) << endl;

            break;

        case 'E':
        case 'e':
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid Input. Please try again." << endl;
            break;
        }
    } while (choice != 'E' && choice != 'e');

    return 0;
}

void displayStudents(string names[], double grades[]) {
    cout << "\n--- Student Grades ---\n";
    for (int i = 0; i < MAX_STUDENTS; i++) {
        cout << "Name: " << names[i] << "\tGrade: " << grades[i] << endl;
    }
}

double calculateAverage(double grades[]) {
    double sum = 0;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        sum += grades[i];
    }
    return sum / MAX_STUDENTS;
}

void findMinMax(double grades[], double& minGrade, double& maxGrade) {
    minGrade = grades[0];
    maxGrade = grades[0];

    for (int i = 1; i < MAX_STUDENTS; i++) {
        minGrade = min(minGrade, grades[i]);
        maxGrade = max(maxGrade, grades[i]);
    }
}

void findStudent(string names[], double grades[], string& name) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (names[i] == name) {
            cout << "Grade of " << name << ": " << grades[i] << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
}
