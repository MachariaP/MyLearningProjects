#ifndef MAIN_H
#define MAIN_H

/**
 * main - header file for prototypes
 * void prototypes (void)
 * int prototypes (int)
 */

// Function prototypes
void createAccount(struct Account *accounts, int *totalAccounts);
void deposit(struct Account *accounts, int totalAccounts);
void withdraw(struct Account *accounts, int totalAccounts);
void balanceInquiry(struct Account *accounts, int totalAccounts);

#endif /* MAIN_H */

