#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>

using namespace std;

class Transaction {
public:
    string date;
    string type;
    double amount;
    Transaction(string t, double a) {
        time_t now = time(0);
        date = ctime(&now);
        type = t;
        amount = a;
    }
};

class Account {
public:
    static int count;
    int account_no;
    string password;
    double balance;
    vector<Transaction> transactions;

    Account() {
        account_no = ++count;
        password = "123";
        balance = 5000;
    }

    void showBalance() {
        cout << "\nMain Window -> Show Balance\n========================\nYour current balance is: $" << balance << "\n—————————————————\nPress enter to go back to the Main Window\n";
        cin.ignore();
        cin.get();
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "———————————————————————————————\nWell done. This was added to your balance successfully…Press enter to go back to the Main Window\n";
        cin.ignore();
        cin.get();
    }

    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount));
            cout << "————————————————————————————————\nPlease take your money then…Press enter to go back to the Main Window\n";
        } else {
            cout << "————————————————————————————————\nInsufficient balance! Press enter to go back to the Main Window\n";
        }
        cin.ignore();
        cin.get();
    }

    void showAllTransactions() {
        cout << "\nMain Window -> Show All Transactions\n=====================================\nAccount no: " << account_no << "\n——————————————————————————-\n";
        cout << "Date | Type | Amount\n";
        for(int i = 0; i < transactions.size(); i++) {
            cout << transactions[i].date << " | " << transactions[i].type << " | " << transactions[i].amount << "\n——————————————————————————-\n";
        }
        cout << "Press enter to go back to the Main Window\n";
        cin.ignore();
        cin.get();
    }
};

int Account::count = 0;
vector<Account> accounts(10);

bool isValidInput() {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    int account_no, choice;
    string password;
    while(true) {
        cout << "\nLogin Window\n===========\nEnter your account no: ";
        cin >> account_no;
        if(!isValidInput() || account_no <= 0 || account_no > 10) {
            cout << "\nInvalid account number! Try again.\n";
            continue;
        }

        cout << "Enter your password: ";
        cin >> password;
        if(accounts[account_no - 1].password != password) {
            cout << "\nInvalid password! Try again.\n";
            continue;
        }

        Account &acc = accounts[account_no - 1];
        while(true) {
            cout << "\nMain Window:\n==========\nChoose one of the following options:\n(1) Show balance\n(2) Deposit\n(3) Withdraw\n(4) Show All Transactions\nEnter your choice: ";
            cin >> choice;
            if(!isValidInput() || choice <= 0 || choice > 4) {
                cout << "\nInvalid choice! Try again.\n";
                continue;
            }

            if(choice == 1) {
                acc.showBalance();
            } else if(choice == 2) {
                double amount;
                cout << "\nMain Window -> Deposit (Enter the following information)\n===========================================\nThe amount you want to deposit: ";
                cin >> amount;
                if(!isValidInput() || amount <= 0) {
                    cout << "\nInvalid amount! Try again.\n";
                    continue;
                }
                acc.deposit(amount);
            } else if(choice == 3) {
                double amount;
                cout << "\nMain Window -> Withdraw (Enter the following information)\n============================================\nThe amount you want to withdraw: ";
                cin >> amount;
                if(!isValidInput() || amount <= 0) {
                    cout << "\nInvalid amount! Try again.\n";
                    continue;
                }
                acc.withdraw(amount);
            } else if(choice == 4) {
                acc.showAllTransactions();
            }
        }
    }
    return 0;
}
