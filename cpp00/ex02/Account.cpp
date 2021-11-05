#include "Account.hpp"

#include <ctime>
#include <iostream>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _totalAmount += _amount;  // checkAmount()?
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
}

int Account::getNbAccounts(void) {
  return _nbAccounts;
}

//  amountに変化があった時点でtotalamountを変更する
int Account::getTotalAmount(void) {
  return _totalAmount;
}

int Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

// "[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0"
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

// total~へ変化量格納
void Account::makeDeposit(int deposit) {
  (void)deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
  (void)withdrawal;
  return true;
}

int Account::checkAmount(void) const {
  return 0;
}

// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t res = std::time(NULL);
  char buf[40];
  std::strftime(buf, 40, "[%Y%m%d_%H%M%S] ", std::localtime(&res));
  std::cout << buf;
}
