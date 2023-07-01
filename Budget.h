#pragma once
#include <string>

// Exercise 1
	// “Create a Budget class that can instantiate objects based on different budget categories like food, 
	// clothing, and entertainment.These objects should allow for depositingand withdrawing funds from each 
	// category, as well computing category balancesand transferring balance amounts between categories”

class Budget {
public:
	Budget(double initialFound, std::string initialName);
	~Budget();

	std::string GetName();
	void SetName(std::string name);

	void Deposit(double deposit);
	void Withdraw(double withdraw);
	double Balance();
private:
	std::string m_Name;
	double m_Found = 0;
};