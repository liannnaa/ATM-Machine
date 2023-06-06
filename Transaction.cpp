class Transaction {
private:
    std::string type;  // Deposit, Withdraw
    float amount;

public:
    Transaction(std::string type, float amount) : type(type), amount(amount) {}

    std::string getType() { return type; }
    float getAmount() { return amount; }
};
