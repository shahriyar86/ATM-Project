#include <stdio.h>
int main() {
    char FirstName[50], LastName[50];
    int Balance = 0;
    int DepositAmount, WithdrawAmount;
    int Pin = 1234, AccountStatus = 0;
    int TransactionHistory[10];
    int BankingOperations, LoginPassword;
    int DeleteAccountAnswer;
    int TransactionCount;
    int Amount;

            while (1) {
        printf("Welcome To ATM Simulator:)\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Balance\n");
        printf("5. Transaction History\n");
        printf("6. Change Pin\n");
        printf("7. Delete Account\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &BankingOperations);

        switch (BankingOperations) {

        case 1:
            if (AccountStatus == 1) {
                printf("You already have an account.\n");
            } else {
                printf("Enter First Name: ");
                scanf("%s", FirstName);

                printf("Enter Last Name: ");
                scanf("%s", LastName);

                for (int i=1; i<=3; i++) {
                    printf("Enter the Pin (Default 1234): ");
                    scanf("%d", &LoginPassword);
                    if (LoginPassword == Pin) {
                        break;
                    }
                    else {
                        continue;
                    }
                }

                if (LoginPassword==Pin) {
                    printf("Enter initial deposit amount: ");
                    scanf("%d", &Balance);

                    AccountStatus = 1;

                    if (TransactionCount < 10) {
                        TransactionHistory[TransactionCount] = Balance;
                        TransactionCount++;
                    } else {
                        for (int i = 0; i < 9; i++) {
                            TransactionHistory[i] = TransactionHistory[i + 1];
                        }
                        TransactionHistory[9] = Balance;
                    }


                    printf("Account created successfully!\n");
                }
              else {
                  printf("The incorrect password has been repeated more than the allowed number of times!\n");
                  break;
              }
            }
            break;

        case 2:
            if (AccountStatus == 1) {
                printf("Enter deposit amount: ");
                scanf("%d", &DepositAmount);

                if (DepositAmount > 0) {
                    Balance += DepositAmount;
                    printf("Deposit successful.\n");

                    Amount = DepositAmount;

                    if (TransactionCount < 10) {
                        TransactionHistory[TransactionCount] = Amount;
                        TransactionCount++;
                    } else {
                        for (int i = 0; i < 9; i++) {
                            TransactionHistory[i] = TransactionHistory[i + 1];
                        }
                        TransactionHistory[9] = Amount;
                    }

                } else {
                    printf("Invalid deposit amount.\n");
                }
            } else {
                printf("You need to create an account first.\n");
            }

            break;

        case 3:
            if (AccountStatus == 1) {
                printf("Enter withdraw amount: ");
                scanf("%d", &WithdrawAmount);

                if (WithdrawAmount > 0 && WithdrawAmount <= Balance) {
                    Balance -= WithdrawAmount;
                    printf("Withdrawal successful.\n");

                    Amount = -WithdrawAmount;

                    if (TransactionCount < 10) {
                        TransactionHistory[TransactionCount] = Amount;
                        TransactionCount++;
                    } else {
                        for (int i = 0; i < 9; i++) {
                            TransactionHistory[i] = TransactionHistory[i + 1];
                        }
                        TransactionHistory[9] = Amount;
                    }

                } else {
                    printf("Invalid or insufficient Balance.\n");
                }
            } else {
                printf("You need to create an account first.\n");
            }

            break;

        case 4:
            if (AccountStatus == 1) {
                printf("Current Balance: %d\n", Balance);
            } else {
                printf("You need to create an account first.\n");
            }
            break;

        case 5:
                if (AccountStatus == 1) {

                    printf("Transaction History:\t");

                    for (int i = 0; i < TransactionCount; i++) {
                        if (TransactionHistory[i] >= 0) {
                            printf("+ %d\t", TransactionHistory[i]);
                        } else {
                            printf("- %d\t", -TransactionHistory[i]);
                        }
                    }

                    }

                    else {
                        printf("You need to create an account first.\n");
                }
            break;

        case 6:
            if (AccountStatus == 1) {
               for (int i=1; i<=3; i++) {
                   printf("Enter current Pin: ");
                   scanf("%d", &LoginPassword);
                   if (LoginPassword == Pin) {
                       break;
                   }
                   else {
                       continue;
                   }
               }
            if (LoginPassword==Pin) {
                printf("Enter new Pin: ");
                scanf("%d", &Pin);
                printf("Pin changed successfully.\n");
            }
              else {
                  printf("The incorrect password has been repeated more than the allowed number of times!\n");
                  break;
              }

            }
                else {
                printf("You need to create an account first.\n");
            }
            break;

        case 7:
            if (AccountStatus == 1) {
                printf("Are you sure you want to delete your account?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("Choose an option:");
                scanf("%d", &DeleteAccountAnswer);

                switch (DeleteAccountAnswer) {
                    case 1:
                        for (int i=1; i<=3; i++) {
                            printf("Enter the pin:");
                            scanf("%d",&LoginPassword);
                            if (LoginPassword == Pin) {
                                Pin = 1234;
                                AccountStatus = 0;
                                printf("Account successfully deleted.\n");
                                break;
                            }

                            else {
                                continue;
                            }
                        }
                }
            }

            else {
                printf("You need to create an account first.\n");
            }
            break;

        case 8:
            printf("Thank you for using ATM Simulator.\n");
            return 0;

        default:
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}