#include <iostream>
#include <vector>
using namespace std;

class Vehicle {
protected:
    int regNo;
    int parkedHours;
public:
    Vehicle(int reg, int hours) : regNo(reg), parkedHours(hours) {}

    virtual double calculateFee() = 0;

    virtual ~Vehicle() = default;

    int getHours() const {
        return parkedHours;
    }

    int getRegNo() const {
        return regNo;
    }
};

class StudentBike : public Vehicle {
public:
    StudentBike(int reg, int hours) : Vehicle(reg, hours) {}

    virtual double calculateFee() override {
        return 5 * parkedHours;
    }
};

class StaffCar : public Vehicle {
public:
    StaffCar(int reg, int hours) : Vehicle(reg, hours) {} 

    virtual double calculateFee() override {
        return 10 * parkedHours;
    }
};

int main() {

vector<Vehicle*> vehicles;

Vehicle* v1 = new StudentBike(101, 3); //one way of putting into vector
vehicles.push_back(v1);

vehicles.push_back(new StudentBike(102, 5)); // another way
vehicles.push_back(new StaffCar(201, 7));
vehicles.push_back(new StaffCar(202, 6));

cout << "=====Parking Receipts=====\n";
for(Vehicle* v : vehicles) {
    cout << "Registeration No: " << v->getRegNo() << endl;
    cout << "Parked Hours: " << v->getHours() << endl;
    cout << "Parking Fee: Rs." << v->calculateFee() << endl << endl;
}

for(Vehicle* v : vehicles) {
    delete v;
}

vehicles.clear();

return 0;
}