// Exercise 1
	// “Create a Budget class that can instantiate objects based on different budget categories like food, 
	// clothing, and entertainment.These objects should allow for depositingand withdrawing funds from each 
	// category, as well computing category balancesand transferring balance amounts between categories”

#include "Budget.h"

Budget::Budget(double initialFound, std::string initialName)
{
	m_Found = initialFound;
	m_Name = initialName;
}

Budget::~Budget() {}

void Budget::SetName(std::string name)
{
	m_Name = name;
}

std::string Budget::GetName()
{
	return m_Name;
}

void Budget::Deposit(double deposit)
{
	m_Found += deposit;
}

void Budget::Withdraw(double withdraw)
{
	double finalFound = m_Found;
	finalFound -= withdraw;
	if (finalFound >= 0)
	{
		m_Found = finalFound;
	}
}

double Budget::Balance()
{
	return m_Found;
}