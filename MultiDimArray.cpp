#include <iostream>
using namespace std;

int main() {

	//Multidimensional Arrays
	int numberOfScores[5] = { 1, 2, 3, 4, 5 };
    string students[] = {"Anna", "Elsa",  "Julia"};

	//Student 1 90, 80, 70, 90
	//Student 2 80, 80, 100, 95
	//Student 3 90, 100, 90, 100
	int studentQuizzes[][4] = {
		{90, 80, 70, 90},
		{80, 80, 100, 95},
		{90, 100, 90, 100}
	};
	
	int numberOfStudents = sizeof(studentQuizzes)/sizeof(studentQuizzes[0]);
	for (int i = 0; i < numberOfStudents; i++) {
	    cout << students[i] << " Results are: ";
	    for (int j = 0; j < 4; j++) {
	        cout << studentQuizzes[i][j] << " ";
	    }
	    cout << endl;
	}

	return 0;
}


//NEXT THiNG 

#include <iostream> 
#include <time.h>
using namespace std;

int main() {

    int count = 1;

    // Declaring 2D array 
    int array1[2][4];

    // Initialize 2D array using loop 
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            array1[i][j] = count;
            count++;
        }
    }

    // Printing the element of 2D array 
    for (int row = 0; row < 2; row++) {
        int sumRow = 0;
        for (int column = 0; column < 4; column++) {
            cout << array1[row][column] << "\t";
            sumRow += array1[row][column];
        }
        cout << sumRow << endl;
    }
    
    for (int column = 0; column < 4; column++){
        int sumColumn = 0;
        for (int row = 0; row < 2; row++) {
            sumColumn += array1[row][column];
        }
        cout << sumColumn << "\t";
    }




    return 0;
}
