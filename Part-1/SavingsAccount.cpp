#include "SavingsAccount.h"

using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate ) : Account( initialBalance )
{
	interestRate = (rate < 0) ? 0 : rate;
}

double SavingsAccount::calculateInterest() {
	return this->getBalance() * this->interestRate;
}

void SavingsAccount::display(ostream & os) const
{

	os << "Account type: Saving" << endl;
  os << "Balance: $ " << this->getBalance() << endl;

	os.setf(ios::fixed|ios::right);
	os.precision(2);

  os << "Interest Rate (%): " << interestRate*100 << endl;
}
