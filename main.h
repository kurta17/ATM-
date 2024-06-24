#ifndef MAIN_H
#define MAIN_H

struct User {
    char name[50];
    int balance;
};

struct DialogData {
    GtkWidget *dialog;
    GtkWidget *entry;
    struct User *user;
};

extern struct User user;

#endif // MAIN_H
