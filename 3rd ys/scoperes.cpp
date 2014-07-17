#include <iostream>

using namespace std;

int a = 20;

int main(void) {
	int a = 30;
	{
		int k = a;
		int a = 10;
		cout << "k-> " << k << endl;
		cout << "a-> " << a << endl;
		cout << "::a-> " << ::a << endl;	
	}
	cout << "a-> " << a << endl;
	cout << "::a-> " << ::a << endl;
	return 0;
}
