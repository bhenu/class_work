#include <iostream>
using namespace std;

inline int largest(int a, int b, int c){
    return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int main() {
    int a, b, c;
    cout << "Enter three numbers:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << "The largest number is: " << largest(a,b,c) << endl; 
    return 0;
}
