#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an account
struct Account {
    int accountNumber;
    char accountName[100];
    float balance;
};


int main() {
    struct Account accounts[100]; // Assuming we can have up to 100 accounts
    int totalAccounts = 0;
    int choice;

    do {
        printf("\nBank Management System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Balance Inquiry\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &totalAccounts);
                break;
            case 2:
                deposit(accounts, totalAccounts);
                break;
            case 3:
                withdraw(accounts, totalAccounts);
                break;
            case 4:
                balanceInquiry(accounts, totalAccounts);
                break;
            case 0:
                printf("Exiting Bank Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

void createAccount(struct Account *accounts, int *totalAccounts) {
    if (*totalAccounts >= 100) {
        printf("Maximum account limit reached.\n");
        return;
    }

    struct Account newAccount;
    printf("\nEnter Account Number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter Account Name: ");
    scanf(" %[^\n]s", newAccount.accountName);
    printf("Enter Initial Balance: ");
    scanf("%f", &newAccount.balance);

    accounts[*totalAccounts] = newAccount;
    (*totalAccounts)++;

    printf("Account successfully created!\n");
}

void deposit(struct Account *accounts, int totalAccounts) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            accounts[i].balance += amount;
            found = 1;

            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void withdraw(struct Account *accounts, int totalAccounts) {
    int accountNumber;
    float amount;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                found = 1;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient balance.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

void balanceInquiry(struct Account *accounts, int totalAccounts) {
    int accountNumber;
    int found = 0;

    printf("\nEnter Account Number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            found = 1;
            printf("Account Name: %s\n", accounts[i].accountName);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account not found.\n");
    }
}

