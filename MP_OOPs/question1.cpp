//Q.1. Explain with a concrete code example how encapsulation and abstraction satisfy the
//design goals of robustness and adaptability in modern software systems.


#include <iostream>

class BankAccount {
private:
    double balance = 0.0; 

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount myAccount;
    myAccount.deposit(150.00);
    std::cout << "Account Balance: $" << myAccount.getBalance() << "\n";
    return 0;
}
