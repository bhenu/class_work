#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class account {
    string name;
    int acc_no;
    string type;
    float balance;
    
    public: 
        account() {
            acc_no = int(time(0));
            balance = 0.00;
        }
        void create(){
            cout << "Enter name of account holder:" << endl;
            gets(name);
            cout << "Type of account? " << endl;
            cin >> type;  
            cout << "account created." << endl << endl;           
        }
        void info() {
            cout <<endl << endl <<"Name of holder: " << name << endl;
            cout << "Account number: " << acc_no << endl;
            cout << "Account type: " << type << endl;
            cout << "Total balance: " << balance << endl <<endl << endl;
        }
        void credit() {
            float value;
            cout << "Enter sum to deposite." << endl;
            cin >> value;
            balance += value;
        }
        void debit() {
            float value;
            cout << "Enter sum to withdraw." << endl;            
            cin >> value;
            if (value < balance)
                balance -= value;
            else
                cout << "Sorry. Insufficient balance." << endl;
        }
};

int main() {
    account a1;
    int i = 20;
    cout << "Choose a option: " << endl;
    while(i) {
        cout << "[1] Create new account."
             << endl
             << "[2] Print account info."
             << endl
             << "[3] Deposite money."
             << endl
             << "[4] Cash withdrawl."
             << endl
             << "[0] Quit."
             << endl;
             
        cin >> i;
        switch(i) {
            case 1:
                a1.create();
                break;
            case 2:
                a1.info();
                break;
            case 3:
                a1.credit();
                break;
            case 4:
                a1.debit();
                break;
        }
            
    }
    return 0;
}
