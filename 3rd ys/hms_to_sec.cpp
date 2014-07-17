#include <iostream>
using namespace std;

class timeutil {
	int hrs, mins, secs, i;

	public:
		void get_data(){
			while(1) {
				cout << "Enter -1 to quit any time" << endl;
				cout << "Enter hrs: " << endl;
				cin >> i;
				if (i == -1) break;
				hrs = i;
				cout << "Enter mins: " << endl;
				cin >> i;
				if (i == -1) break;
				while ( (0 > i || i > 60) && i != -1 ){
					cout << "min must be within 0-60" << endl << "Enter mins again: " << endl; 
					cin >> i;
				}
				if (i==-1) break;
				mins = i;
				cout << "Enter secs: " << endl;
				cin >> i;
				if (i == -1) break;
				while ( 0 > i || i > 60 && i != -1) {
					 cout << "sec must be within 0-60" << endl << "Enter secs again: " << endl;
					 cin >> i;
				}
				if (i == -1) break;
				secs = i;
 			}
		}

		int hms_to_sec() {
	 		return (hrs*3600 + mins*60 + secs);
		}
};

int main() {
	timeutil mytime;
	mytime.get_data();
	cout << mytime.hms_to_sec() << " secs" << endl;
	return 0;
}
