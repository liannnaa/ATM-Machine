#include <string>
#include <vector>

class User {
private:
    int accountNumber;
    std::string password;
    Account userAccount;  // assuming each user has a single account for simplicity

public:
    User(int accountNumber, std::string password, Account account) : 
    accountNumber(accountNumber), password(password), userAccount(account) {}

    int getAccountNumber() { return accountNumber; }
    std::string getPassword() { return password; }
    Account getAccount() { return userAccount; }
};
