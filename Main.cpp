#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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
        cout << "Your current balance is: $" << balance << "\nPress enter to go back to the Main Window\n";
        cin.ignore();
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Well done. This was added to your balance successfully…Press enter to go back to the Main Window\n";
        cin.ignore();
    }

    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount));
            cout << "Please take your money then…Press enter to go back to the Main Window\n";
        } else {
            cout << "Insufficient balance! Press enter to go back to the Main Window\n";
        }
        cin.ignore();
    }

    void showAllTransactions() {
        cout << "Account no: " << account_no << "\n";
        cout << "Date                  | Type     | Amount\n";
        for(auto &t : transactions) {
            cout << t.date << " | " << t.type << " | " << t.amount << "\n";
        }
        cout << "Press enter to go back to the Main Window\n";
        cin.ignore();
    }
};

int Account::count = 0;
vector<Account> accounts(10);

int main() {
    int account_no, choice;
    string password;
    while(true) {
        cout << "Enter your account no: ";
        cin >> account_no;
        cout << "Enter your password: ";
        cin >> password;
        if(account_no <= 0 || account_no > 10 || accounts[account_no - 1].password != password) {
            cout << "Invalid credentials! Try again.\n";
            continue;
        }

        Account &acc = accounts[account_no - 1];
        while(true) {
            cout << "Choose one of the following options:\n(1) Show balance\n(2) Deposit\n(3) Withdraw\n(4) Show All Transactions\nEnter your choice: ";
            cin >> choice;
            if(choice == 1) {
                acc.showBalance();
            } else if(choice == 2) {
                double amount;
                cout << "The amount you want to deposit: ";
                cin >> amount;
                if(amount <= 0) {
                    cout << "Invalid amount! Try again.\n";
                    continue;
                }
                acc.deposit(amount);
            } else if(choice == 3) {
                double amount;
                cout << "The amount you want to withdraw: ";
                cin >> amount;
                if(amount <= 0) {
                    cout << "Invalid amount! Try again.\n";
                    continue;
                }
                acc.withdraw(amount);
            } else if(choice == 4) {
                acc.showAllTransactions();
            } else {
                cout << "Invalid choice! Try again.\n";
            }
        }
    }
}
