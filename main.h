
struct User
{
    char name[50];
    int balance;
};

void displayMenu(struct User *user);
void withdraw(struct User *user);
void deposit(struct User *user);
void exitProgram();