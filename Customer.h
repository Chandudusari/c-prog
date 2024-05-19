#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include <vector>
#include <string>

class Purchase {
private:
    string item;
    int quantity;
    double cost;

public:
    Purchase() = default;
    Purchase(const string& item, int quantity, double cost)
        : item(item), quantity(quantity), cost(cost) {}

    void display() const {
        cout << item << " " << cost << " " << quantity << " " << cost * quantity << endl;
    }

    void load(istream& in) {
        getline(in, item);
        in >> quantity >> cost;
        in.ignore(); // To consume the newline character after the cost
    }

    void save(ostream& out) const {
        out << item << endl;
        out << quantity << endl;
        out << cost << endl;
    }
};

class Customer : public Person {
private:
    vector<Purchase> purchases;

public:
    Customer() = default;
    Customer(const string& name, const string& email, const string& phone)
        : Person(name, email, phone) {}

    void addPurchase(const Purchase& purchase) {
        purchases.push_back(purchase);
    }

    void display() const override {
        Person::display();
        cout << endl;
    }

    void displayPurchases() const {
        cout << "Order History" << endl;
        for (const auto& purchase : purchases) {
            purchase.display();
        }
    }

    void load(istream& in) override {
        Person::load(in);
        int numPurchases;
        in >> numPurchases;
        in.ignore(); // To consume the newline character after the number of purchases
        for (int i = 0; i < numPurchases; ++i) {
            Purchase purchase;
            purchase.load(in);
            purchases.push_back(purchase);
        }
    }

    void save(ostream& out) const override {
        Person::save(out);
        out << purchases.size() << endl;
        for (const auto& purchase : purchases) {
            purchase.save(out);
        }
    }
};

#endif // CUSTOMER_H
