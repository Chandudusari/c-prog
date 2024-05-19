#include "Company.h"
#include <iostream>
#include <string>
using namespace std;
void displayMainMenu() {
    cout << "    MAIN MENU\n"
         << "1.) Employees\n"
         << "2.) Sales\n"
         << "3.) Quit\n"
         << "\nChoice? ";
}

void handleEmployees(Company& company) {
    string choice;
    do {
        company.displayEmployees();
        cout << "(A)dd Employee or (M)ain Menu? ";
        getline(cin, choice);

        if (choice == "A" || choice == "a") {
            string name, email, phone, salaryStr;
            double salary;
            cout << "Name: ";
            getline(cin, name);
            cout << "Email: ";
            getline(cin, email);
            cout << "Phone: ";
            getline(cin, phone);
            cout << "Salary: ";
            getline(cin, salaryStr);
            salary = stod(salaryStr);

            company.addEmployee(Employee(name, email, phone, salary));
        }
    } while (choice != "M" && choice != "m");
}

void handleSales(Company& company) {
    string choice;
    do {
        cout << "(A)dd Customer, Enter a (S)ale, (V)iew Customer, or (M)ain Menu? ";
        getline(cin, choice);

        if (choice == "A" || choice == "a") {
            string name, email, phone;
            cout << "Name: ";
            getline(cin, name);
            cout << "Email: ";
            getline(cin, email);
            cout << "Phone: ";
            getline(cin, phone);

            company.addCustomer(Customer(name, email, phone));
        } else if (choice == "S" || choice == "s") {
            company.displayCustomers();
            cout << "Choice? ";
            getline(cin, choice);
            int customerIndex = stoi(choice) - 1;

            string item, quantityStr, costStr;
            int quantity;
            double cost;
            cout << "Item: ";
            getline(cin, item);
            cout << "Quantity: ";
            getline(cin, quantityStr);
            quantity = stoi(quantityStr);
            cout << "Cost: ";
            getline(cin, costStr);
            cost = stod(costStr);

            company.addSale(company.getCustomers()[customerIndex].name, Purchase(item, quantity, cost));
        } else if (choice == "V" || choice == "v") {
            company.displayCustomers();
            cout << "Choice? ";
            getline(cin, choice);
            int customerIndex = stoi(choice) - 1;

            company.getCustomers()[customerIndex].displayPurchases();
        }
    } while (choice != "M" && choice != "m");
}

int main() {
    cout << "Company Name: ";
    string companyName;
    getline(cin, companyName);

    Company company(companyName);

    string choice;
    do {
        displayMainMenu();
        getline(cin, choice);

        if (choice == "1") {
            handleEmployees(company);
        } else if (choice == "2") {
            handleSales(company);
        }
    } while (choice != "3");

    company.save();

    return 0;
}
