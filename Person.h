#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
public:
    string name;
    string email;
    string phone;

public:
    Person() = default;
    Person(const string& name, const string& email, const string& phone)
        : name(name), email(email), phone(phone) {}
    virtual ~Person() = default;

    virtual void display() const {
        cout << name << " <" << email << ">  Phone: " << phone;
    }

    virtual void load(istream& in) {
        getline(in, name);
        getline(in, email);
        getline(in, phone);
    }

    virtual void save(ostream& out) const {
        out << name << endl;
        out << email << endl;
        out << phone << endl;
    }
};

#endif // PERSON_H
