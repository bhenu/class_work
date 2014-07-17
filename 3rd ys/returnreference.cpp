#include <iostream>
using namespace std;

double & GetWeeklyHours() {
	double h = 46.50;
    double &hours = h;
    return hours;
}

int main() {
    double hours = GetWeeklyHours();
    cout << "Weekly Hours:" << hours << endl;
    return 0;
}
