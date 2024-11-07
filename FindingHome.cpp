#include <iostream>
using namespace std;

void findHome(int x, int y, string name);
string makeName();

int main() {
    string name = makeName();

    findHome(3, 4, name);
    return 0;
}

void findHome(int x, int y, string name) {
    cout << "x = " << x << ", y = " << y << endl;
    if (x != 1) {
        cout << name << " Moved Left..." << endl;
        return findHome(x - 1, y, name);
    }
    if (y != 1) {
        cout << name << " Moved Down..." << endl;
        return findHome(x, y - 1, name);
    }
    cout << name << " is Home!" << endl;
}

string makeName() {
    string name;
    cout << "Enter your Name: ";
    cin >> name;
    return name;
}
