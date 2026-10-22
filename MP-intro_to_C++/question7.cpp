//Q.7. Construct a BankAccount class with private attributes accountNumber and balance, and
// public member functions deposit(), withdraw(), and display(). Prevent withdrawals that
// exceed the current balance.


#include <iostream>
using namespace std;

class BankAccount {
    private:
        long long accountNumber;
        long long balance = 0;
    public:
        void setAccountNumber(long long accNum) {
            accountNumber = accNum;
        }

        long long getBalance() const {
            return balance;
        }

        long long getAccountNumber() const {
            return accountNumber;
        }

        void deposit(int amount) {
            if(amount >= 0) {
                balance += amount;
                cout << "Amount Deposited \n";
            }    
            else {
                cout << "Invalid Entry \n";
            }

            
        }

        void withdraw(int amount) {
            if(balance >= amount) {
                balance -= amount;
                cout << "Amount Withdrawn \n";
            } else {
                cout << "Insufficient Balance\n";
            }
        }

        void display() {
            cout << "\n==============================\n";
            cout << "Account Number: " << accountNumber << endl;
            cout << "Bank Balance: " << balance << endl;
            cout << "==============================\n";
        }
};

int main() {

BankAccount holder1;
long long inputAccNum;

cout << "Account Number: ";
cin >> inputAccNum;

holder1.setAccountNumber(inputAccNum);

bool running = true;
int choice, amount;
do {

    cout << "\n--- Bank Account Menu ---\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance / Display Account Info\n";
        cout << "4. Exit System\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                holder1.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                holder1.withdraw(amount);
                break;

            case 3:
                holder1.display();
                break;

            case 4:
                cout << "Thank you for using our banking system. Goodbye!\n";
                running = false; 
                break;

            default:
                cout << "Invalid Choice! Please enter a number between 1 and 4.\n";
                break;

        }
 } while (running);



return 0;
}


