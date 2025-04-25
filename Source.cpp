/*
 * Developer: Rebecca Scranton
 * Date: April 9, 2025
 * Purpose: To test different monthly deposit amounts, interest rates, and lengths of
 * time to see how increases and decreases impact investment growth.
 */

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

#include "investment.h"

// global variable
InvestmentDetails entry1;

// display menu to input information
void displayMenu() {
    double initial;
    double deposit;
    double interest;
    int years;

    // menu banner
    cout << string(34, '*') << endl;
    cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
    
    // Validate Initial Investment Amount
    while (true) {
        cout << "Initial Investment Amount: ";
        cin >> initial;

        if (cin.fail()) {
            cout << "Invalid entry. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (initial < 0) {
            cout << "Invalid entry. Please enter a positive number." << endl;
        }
        else {
            break;
        }  
    }

    // Validate Monthly Deposit
    while (true) {
        cout << "Monthly Deposit: ";
        cin >> deposit;

        if (cin.fail()) {
            cout << "Invalid entry. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (deposit < 0) {
            cout << "Invalid entry. Please enter a positive number." << endl;
        }
        else {
            break;
        }
    }

    //validate Annual Interest
    while (true) {
        cout << "Annual Interest: ";
        cin >> interest;

        if (cin.fail()) {
            cout << "Invalid entry. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (interest < 0) {
            cout << "Invalid entry. Please enter a positive number." << endl;
        }
        else {
            break;
        }
    }

    // validate number of years
    while (true) {
        cout << "Number of years: ";
        cin >> years;

        if (cin.fail()) {
            cout << "Invalid entry. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (years < 0) {
            cout << "Invalid entry. Please enter a positive number." << endl;
        }
        else {
            break;
        }
    }
    // set user inputs to class variables
    entry1.setInvestAmount(initial);
    entry1.setMonthlyDeposit(deposit);
    entry1.setAnnualInterest(interest);
    entry1.setNumOfYears(years);
}

// create vectors without monthly deposits
pair<vector<double>, vector<double>> totalsWithout() {
    vector<double> interestWithout = {};
    vector<double> balanceWithout = {};
    double currentInterest;
    double totalInterest = 0;
    double currentBalance = entry1.getInvestAmount();
    double annualInterest = entry1.getAnnualInterest();
    int years = entry1.getNumOfYears();

    // calculate interest and balance for every month 
    for (int i = 1; i <= (years * 12); ++i) {
        currentInterest = currentBalance * ((annualInterest/100)/12);
        currentBalance += currentInterest;
        totalInterest += currentInterest;
        // save totals every 12 months
        if (i % 12 == 0) {
            interestWithout.push_back(totalInterest);
            totalInterest = 0;
            balanceWithout.push_back(currentBalance);
        }
    }
    return make_pair(interestWithout, balanceWithout);
}

// create vectors with monthly deposits
pair<vector<double>, vector<double>> totalsWith() {
    vector<double> interestWith = {};
    vector<double> balanceWith = {};
    double currentInterest;
    double totalInterest = 0;
    double currentBalance = entry1.getInvestAmount();
    double deposit = entry1.getMonthlyDeposit();
    double annualInterest = entry1.getAnnualInterest();
    int years = entry1.getNumOfYears();

    // calculate interest and balance for every month 
    for (int i = 1; i <= (years * 12); ++i) {
        currentBalance += deposit;
        currentInterest = currentBalance * ((annualInterest / 100) / 12);
        totalInterest += currentInterest;
        currentBalance += currentInterest;
        // save totals every 12 months
        if (i % 12 == 0) {
            interestWith.push_back(totalInterest);
            totalInterest = 0;
            balanceWith.push_back(currentBalance);
        }
    }
    return make_pair(interestWith, balanceWith);
}

// print report of balances and interests for every year requested
void displayReports() {
    // call vectors from totalsWithout
    pair<vector<double>, vector<double>> result1 = totalsWithout();
    vector<double> interestWithout = result1.first;
    vector<double> balanceWithout = result1.second;

    // call vectors from totalsWith
    pair<vector<double>, vector<double>> result2 = totalsWith();
    vector<double> interestWith = result2.first;
    vector<double> balanceWith = result2.second;

    // without deposits Banner
    cout << endl; 
    cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << string(64, '=') << endl;
    cout << "  Year     " << "     Year End Balance" << "     Year End Earned Interest" << endl;
    cout << string(64, '-') << endl;

    // print without deposits data
    for (int i = 0; i < interestWithout.size(); ++i) {
        cout << string(3, ' ') << i + 1 << string(17, ' ') << "$";
        cout << fixed << setprecision(2) << balanceWithout[i]; 
        cout << string(22, ' ') << "$" << interestWithout[i] << endl;
        cout << endl;
    }

    // with deposits Banner
    cout << endl;
    cout << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << string(64, '=') << endl;
    cout << "  Year     " << "     Year End Balance" << "     Year End Earned Interest" << endl;
    cout << string(64, '-') << endl;

    // print with deposits data
    for (int i = 0; i < interestWith.size(); ++i) {
        cout << string(3, ' ') << i + 1 << string(17, ' ') << "$";
        cout << fixed << setprecision(2) << balanceWith[i];
        cout << string(22, ' ') << "$" << interestWith[i] << endl;
        cout << endl;
    }
}

// main function
int main() {

    // loop new reports until response of n
    while (true) {
        char response;
        displayMenu();
        system("Pause");
        displayReports();

        // validate y or n response to new report
        while (true) {
            cout << "Would you like to make another inquiry (y or n)? ";
            cin >> response;
            if ((response == 'y') || (response == 'n')) {
                cout << endl;
                break;
            }
            else {
                cout << "invalid response" << endl;
            }
        }
        
        // leave program
        if (response == 'n') {
            cout << "Goodbye!";
            break;
        }
    }
}

