#include <stdio.h>
#include <stdlib.h>

struct User
{
    char name[50];
    int balance;
};

void displayMenu(struct User *user);
void withdraw(struct User *user);
void deposit(struct User *user);
void exitProgram();

void displayMenu(struct User *user) 
{
    printf("Username: %s\n", user->name);
    printf("Balance: %d\n", user->balance);
    printf("1. Withdraw\n");
    printf("2. Deposit\n");
    printf("3. Exit\n");
}

void deposit(struct User *user)
{
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);

    if (amount < 0)
    {
        printf("Invalid amount\n");
    }
    else
    {
        user->balance += amount;
        printf("Deposit successful\n");
    }
}

void withdraw(struct User *user) 
{
    int amount;
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);

    if (amount > user->balance)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        user->balance -= amount;
        printf("Withdrawal successful\n");
    }
}

void exitProgram() 
{
    printf("Exiting program\n");
    exit(0);
}


int main()
{
    struct User user;

    scanf("%49s", user.name); 
    user.balance = 0;

    displayMenu(&user); 

    int choice;
    scanf("%d", &choice);

    while (choice != 3) 
    {
        switch (choice)
        {
        case 1:
            withdraw(&user);
            break;
        case 2:
            deposit(&user);
            break;
        case 3:
            exitProgram();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

        displayMenu(&user);
        
        scanf("%d", &choice);
    }

    return 0;
}