//Q.4. Design a pure abstract interface Serializable containing a pure virtual function virtual
// std::string serialize() const = 0;. Implement this interface across two distinct classes:
// User and Product.

#include <iostream>
#include <string>
using namespace std;


class Serializable {
public:
    virtual string serialize() const = 0;
    virtual ~Serializable() = default;
};

class User : public Serializable {
private:
    string name;
    int age;
public:
    User(string n, int a) : name(n), age(a) {}
    string serialize() const override {
        return "User: " + name + ", Age: " + to_string(age);
    }
};

class Product : public Serializable {
private:
    string name;
    double price;
public:
    Product(string n, double p) : name(n), price(p) {}
    string serialize() const override {
        return "Product: " + name + ", Price: $" + to_string(price);
    }
};

int main() {
    User u("Vincent" , 19);
    Product p("Butter", 15);

    cout << u.serialize();
    cout << "\n";
    cout << p.serialize();

return 0;
}