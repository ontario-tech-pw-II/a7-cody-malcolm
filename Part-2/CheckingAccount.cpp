#include "CheckingAccount.h"

using namespace std;


// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee ) : Account( initialBalance )
{
	transactionFee = (fee < 0) ? 0 : fee;
}

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit( double amount )
{
	Account::credit(amount);
	chargeFee();
}

// debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit( double amount )
{
	bool success = Account::debit(amount);
	if (success) {
		chargeFee();
	}
	return success;
}

// subtract transaction fee
void CheckingAccount::chargeFee()
{
	setBalance(getBalance()-transactionFee);
}

void CheckingAccount::display(ostream & os) const
{
	os << "Account type: Checking" << endl;
  os << "Balance: $ " << this->getBalance() << endl;

	os.setf(ios::fixed|ios::right);
	os.precision(2);

  os << "Transaction Fee: " << transactionFee << endl;
}
