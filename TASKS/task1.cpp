#include <iostream>
using namespace std;

class BankAccount{
private:
    long long accountNumber;
    double balance = 0;
public:
    BankAccount(long long accNo, double bal) : accountNumber(accNo), balance(bal) {
        cout << "Account Created! Initial balance: " << bal << endl
        ;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit Positive Amount.\n";
        }
    }

    void withdraw(double amount) {
        if(amount < 0) {
            cout << "Invalid Entry\n";
        } else if(amount <= balance) {
            balance += amount;
        } else {
            cout << "Not Enough Balance\n";
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << " BALANCE: " << balance << endl;
    }
};
int main() {

BankAccount b1(232332323, 100);
b1.deposit(20);
b1.display();

b1.withdraw(50);
b1.display();


return 0;
}