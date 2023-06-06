class Account {
private:
    float balance;
    std::vector<Transaction> transactions;  // log of all transactions

public:
    Account() : balance(0.0) {}

    float getBalance() { return balance; }
    void deposit(float amount) { 
        balance += amount; 
        // add transaction to log
    }
    void withdraw(float amount) { 
        if (balance >= amount) {
            balance -= amount; 
            // add transaction to log
        }
    }
    std::vector<Transaction> getTransactions() { return transactions; }
};
