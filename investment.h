#pragma once
#ifndef INVESTMENT_DETAILS_H
#define INVESTMENT_DETAILS_H

using namespace std;

class InvestmentDetails {
private:
    double investAmount;
    double monthlyDeposit;
    double annualInterest;
    int numOfYears;

public:
    // default Constructor
    InvestmentDetails(); 

    // getter functions for user entered information
    double getInvestAmount();
    double getMonthlyDeposit();
    double getAnnualInterest();
    int getNumOfYears();

    //setter functions for user entered information
    void setInvestAmount(double value);
    void setMonthlyDeposit(double value);
    void setAnnualInterest(double value);
    void setNumOfYears(int value);
};

#endif

