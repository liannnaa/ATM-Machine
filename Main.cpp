#include <iostream>

int main() {
    std::cout << "Enter Your Account no: ";
    int accountNo;
    std::cin >> accountNo;

    std::cout << "Enter Your Password: ";
    std::string password;
    std::cin >> password;

    // authenticate user here...

    while(true) {
        std::cout << "Choose one of the following options:\n";
        std::cout << "(1) Show Balance\n";
        std::cout << "(2) Deposit\n";
        std::cout << "(3) Withdraw\n";
        std::cout << "(4) Show All Transactions\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                // show balance
                break;
            case 2:
                // deposit
                break;
            case 3:
                // withdraw
                break;
            case 4:
                // show all transactions
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
