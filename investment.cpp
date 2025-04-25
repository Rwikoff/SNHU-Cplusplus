#include "investment.h"

InvestmentDetails::InvestmentDetails() {
    investAmount = 0.0;
    monthlyDeposit = 0.0;
    annualInterest = 0.0;
    numOfYears = 0;
}

// getter functions for user entered information
double InvestmentDetails::getInvestAmount() {
    return investAmount;
}

double InvestmentDetails::getMonthlyDeposit() {
    return monthlyDeposit;
}

double InvestmentDetails::getAnnualInterest() {
    return annualInterest;
}

int InvestmentDetails::getNumOfYears() {
    return numOfYears;
}

    //setter functions for user entered information
void InvestmentDetails::setInvestAmount(double value) {
    investAmount = value;
}

void InvestmentDetails::setMonthlyDeposit(double value) {
    monthlyDeposit = value;
}

void InvestmentDetails::setAnnualInterest(double value) {
    annualInterest = value;
}

void InvestmentDetails::setNumOfYears(int value) {
    numOfYears = value;
}

