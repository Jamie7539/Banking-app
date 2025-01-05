#include <iostream>
#include <fstream>
#include <string>

class Account {
private:
    std::string name;
    int pin;
    double balance;


public:
    Account(std::string accountName, int accountPin, double initialBalance = 0.0)
        : name(accountName), pin(accountPin), balance(initialBalance) {}

    bool verifyPin(int enteredPin) {
        return enteredPin == pin;
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit successful! Current balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid amount. Please enter a positive value.\n";
        }
    }
 
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful! Current balance: $" << balance << "\n";
        } else if (amount > balance) {
            std::cout << "Insufficient funds. Withdrawal failed.\n";
        } else {
            std::cout << "Invalid amount. Please enter a positive value.\n";
        }
    }

    void displayBalance() const {
        std::cout << "Current balance: $" << balance << "\n";
    }
};

int main() {
    Account userAccount("John Doe", 1234, 500.0);

    int userPin;
    std::cout << "Welcome to the Simple Banking System!\n";
    std::cout << "Please enter your PIN to access your account: ";
    std::cin >>userPin;

    if (!userAccount.verifyPin(userPin)) {
        std::cout << "Invalid PIN. Access denied.\n";
        return 1;
    }

    int choice;
    do {
        std::cout << "\nBanking Menu:\n";
        std::cout << "1. Deposit Money\n";
        std::cout << "2. Withdraw Money\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                userAccount.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                userAccount.withdraw(amount);
                break;
            }
            case 3:
                userAccount.displayBalance();
                break;
            case 4:
                std::cout << "Thank you for using the Simple Banking System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";

        }
    } while (choice != 4);

    return 0;

}