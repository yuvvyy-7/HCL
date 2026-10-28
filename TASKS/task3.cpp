    #include <iostream>
    using namespace std;

    class Customer {
    protected:
        string name;
        string address;
        long long income;
    public:
        Customer(string n, string a, long long i) : name(n), address(a), income(i) {
            cout << "Customer Base Class Constructed." << endl;
        }

        virtual void display() const {
            cout << "Customer Name: " << name << " | Address: " << address << " | Income: " << income << endl;
        }
    };

    class CustomerBankDetails : public Customer {
    private:
        long long accountNumber;
        string ifscCode;
        double currentBalance;
    public:
        CustomerBankDetails(string n, string a, long long i, long long acc, string ifsc, double bal) :
        Customer(n, a, i), accountNumber(acc), ifscCode(ifsc), currentBalance(bal) {
            cout << "Derived Class Constructed." << endl;
        }

        void display() const override {
        cout << "Customer Name: " << name << " | Address: " << address << " | Income: " << income << endl;
        cout << "Account No. " << accountNumber << " | IFSC code: " << ifscCode << " | Balance: " << currentBalance << endl;

        }
    };

    int main() {

    Customer c1("Rohan", "MUMBAI", 300000);
    c1.display();

    cout << endl;

    CustomerBankDetails c2("Sohan", "Kopargaon", 4000000, 1232324443, "KPG234", 24000.0);
    c2.display();


    return 0;
    }