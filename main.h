#ifndef MAIN_H
#define MAIN_H

#include <gtk/gtk.h>

struct User {
    int id;
    char name[50];
    int balance;
};

struct DialogData {
    GtkWidget *dialog;
    GtkWidget *entry;
    struct User *user;
};

void loadUserData(struct User *user, int id);
void displayMenu(struct User *user);
void updateMainDisplay(struct User *user);
void updateUserData(struct User *user);

#endif // MAIN_H
