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

void loadUserData(struct User *user);

extern GtkWidget *window;
extern GtkWidget *label_name;
extern GtkWidget *label_balance;
extern GtkWidget *button_withdraw;
extern GtkWidget *button_deposit;
extern GtkWidget *button_exit;

extern struct User user;

#endif // MAIN_H
