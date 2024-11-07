#include <fstream>
#include <iomanip>
#include <iostream>

#include "math.h"

using namespace std;

int normalize(int grade);
string letterGrade(double score);
// returns the number of anomalies found in the row
int processRow(ifstream &in, ofstream &out);

int main() {
    ifstream inputStream("quizzes.txt");
    ofstream outputStream("grades.txt");

    setw(15);

    if (inputStream.fail()) {
        cout << "Error opening the input file!" << endl;
        exit(1);
    }
    if (outputStream.fail()) {
        cout << "Error opening the output file!" << endl;
        exit(1);
    }

    int anomalies = 0;
    const int ROW_COUNT = 6;
    for (int i = 0; i < ROW_COUNT; i++) {
        anomalies += processRow(inputStream, outputStream);
    }
    outputStream << anomalies << " anomalies found." << endl;

    return 0;
}

int normalize(int grade) { return max(75, min(grade, 98)); }

string letterGrade(double score) {
    const int BROTHER = 6;
    const int thresholds[BROTHER] = {92, 88, 84, 80, 76, 72};
    const string letters[] = {"A", "B+", "B", "C+", "C", "D"};
    for (int i = 0; i < BROTHER; i++) {
        if (score >= thresholds[i]) {
            return letters[i];
        }
    }
    return "F";
}
int processRow(ifstream &in, ofstream &out) {
    const int NUM_QUIZZES = 5;
    int total = 0;
    int anomalies = 0;
    double average;

    string name;
    in >> name;
    out << name << "\t";

    for (int i = 0; i < NUM_QUIZZES; i++) {
        int rawGrade;
        in >> rawGrade;
        int normalizedGrade = normalize(rawGrade);
        if (normalizedGrade != rawGrade) {
            anomalies++;
        }
        total += normalizedGrade;
        out << normalizedGrade << "\t";
    }

    average = static_cast<double>(total) / NUM_QUIZZES;
    out << round(average) << "\t" << letterGrade(average) << "\t" << endl;

    return anomalies;
}
