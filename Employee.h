#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
private:
    double salary;

public:
    Employee() = default;
    Employee(const string& name, const string& email, const string& phone, double salary)
        : Person(name, email, phone), salary(salary) {}

    void display() const override {
        Person::display();
        cout << " Salary: $" << salary << endl;
    }

    void load(istream& in) override {
        Person::load(in);
        in >> salary;
        in.ignore();
    }

    void save(ostream& out) const override {
        Person::save(out);
        out << salary << endl;
    }
};

#endif
