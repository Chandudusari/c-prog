#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h"
#include "Customer.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

class Company {
private:
    string name;
    vector<Employee> employees;
    vector<Customer> customers;

public:
    Company(const string& name) : name(name) {
        load();
    }

    void load() {
        ifstream inFile(name + ".dat");
        if (!inFile) {
            // File does not exist, create a new one later
            return;
        }

        int numEmployees;
        inFile >> numEmployees;
        inFile.ignore(); // To consume the newline character after the number of employees
        for (int i = 0; i < numEmployees; ++i) {
            Employee employee;
            employee.load(inFile);
            employees.push_back(employee);
        }

        int numCustomers;
        inFile >> numCustomers;
        inFile.ignore(); // To consume the newline character after the number of customers
        for (int i = 0; i < numCustomers; ++i) {
            Customer customer;
            customer.load(inFile);
            customers.push_back(customer);
        }
    }

    void save() const {
        ofstream outFile(name + ".dat");
        outFile << employees.size() << endl;
        for (const auto& employee : employees) {
            employee.save(outFile);
        }

        outFile << customers.size() << endl;
        for (const auto& customer : customers) {
            customer.save(outFile);
        }
    }

    void displayEmployees() const {
        for (const auto& employee : employees) {
            employee.display();
        }
    }

    void addEmployee(const Employee& employee) {
        employees.push_back(employee);
    }

    void displayCustomers() const {
        for (const auto& customer : customers) {
            customer.display();
        }
    }

    void addCustomer(const Customer& customer) {
        customers.push_back(customer);
    }

    void addSale(const string& customerName, const Purchase& purchase) {
        Customer* customer = findCustomer(customerName);
        if (customer) {
            customer->addPurchase(purchase);
        } else {
            cerr << "Customer not found." << endl;
        }
    }

    Customer* findCustomer(const string& customerName) {
        for (auto& customer : customers) {
            if (customerName == customer.name) {
                return &customer;
            }
        }
        return nullptr;
    }

    const vector<Customer>& getCustomers() const {
        return customers;
    }
};

#endif // COMPANY_H
