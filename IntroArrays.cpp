#include <iostream>
#include <string>

using namespace std;

// Constants for the number of students and grade limits
const int NUM_STUDENTS = 5;
const double MAX_GRADE = 98.0;
const double MIN_GRADE = 75.0;

// Function prototypes
void displayStudents(const string names[], const double grades[], int size);
double calculateAverage(const double grades[], int size);
void findMinMax(const double grades[], int size, double &minGrade, double &maxGrade);
void searchStudent(const string names[], const double grades[], int size, const string &studentName);
int validateGrade(double grade);

int main() {

    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(2);
    // Arrays to store student names and their grades
    string studentNames[NUM_STUDENTS];
    double studentGrades[NUM_STUDENTS];
    
    double minGrade, maxGrade;
    double grade;
    string name;
    char choice;

    // Input student names and grades
    cout << "Enter the names and grades of " << NUM_STUDENTS << " students:\n";
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << "Student " << i + 1 << " Name: ";
        cin >> studentNames[i];

        cout << "Grade: ";
        cin >> grade;

        // Validate the grade to ensure it's within the range [75, 98]
        studentGrades[i] = validateGrade(grade);
    }

    // Display menu options
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
                displayStudents(studentNames, studentGrades, NUM_STUDENTS);
                break;
                
            case 'C':
            case 'c':
                cout << "Average Grade: " << calculateAverage(studentGrades, NUM_STUDENTS) << endl;
            break;

            case 'F':
            case 'f': 
                findMinMax(studentGrades, NUM_STUDENTS, minGrade, maxGrade);
                cout << "Highest Grade: " << maxGrade << "\nLowest Grade: " << minGrade << endl;
            break;
            
            case 'S':
            case 's': 
                cout << "Enter student name to search: ";
                cin >> name;
                searchStudent(studentNames, studentGrades, NUM_STUDENTS, name);
            break;

            case 'A':
            case 'a':
                displayStudents(studentNames, studentGrades, NUM_STUDENTS);
                cout << endl;
                findMinMax(studentGrades, NUM_STUDENTS, minGrade, maxGrade);
                cout << "Highest Grade: " << maxGrade << "\nLowest Grade: " << minGrade << endl;
                cout << "Average Grade: " << calculateAverage(studentGrades, NUM_STUDENTS) << endl;

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

// Function to display all students and their grades
void displayStudents(const string names[], const double grades[], int size) {
    cout << "\n--- Student Grades ---\n";
    for (int i = 0; i < size; ++i) {
        cout << "Name: " << names[i] << " | Grade: " << grades[i] << endl;
    }
}

// Function to calculate the average grade of the class
double calculateAverage(const double grades[], int size) {
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += grades[i];
    }
    return sum / size;
}

// Function to find the lowest and highest grades
void findMinMax(const double grades[], int size, double &minGrade, double &maxGrade) {
    minGrade = grades[0];
    maxGrade = grades[0];

    for (int i = 1; i < size; ++i) {
        if (grades[i] < minGrade) minGrade = grades[i];
        if (grades[i] > maxGrade) maxGrade = grades[i];
    }
}

// Function to search for a student's grade by name
void searchStudent(const string names[], const double grades[], int size, const string &studentName) {
    for (int i = 0; i < size; ++i) {
        if (names[i] == studentName) {
            cout << "Grade of " << studentName << ": " << grades[i] << endl;
            return;
        }
    }
    cout << "Student record not found." << endl;
}

// Function to validate and adjust a grade within the range [75, 98]
int validateGrade(double grade) {
    if (grade < MIN_GRADE) return MIN_GRADE;
    if (grade > MAX_GRADE) return MAX_GRADE;
    return grade;
}
