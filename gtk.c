#include <gtk/gtk.h>
#include "main.h"

GtkWidget *window;
GtkWidget *label_name;
GtkWidget *label_balance;
GtkWidget *button_withdraw;
GtkWidget *button_deposit;
GtkWidget *button_exit;

struct User user = {"John Doe", 1000};

void displayMenu(struct User *user) 
{
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // Create a new window
    gtk_window_set_title(GTK_WINDOW(window), "Banking System"); // Set the window's title
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400); // Set the default size of the window
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); // Center the window

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    char *name_label_text = g_strdup_printf("Name: %s", user->name);
    label_name = gtk_label_new(name_label_text);
    gtk_box_pack_start(GTK_BOX(vbox), label_name, TRUE, TRUE, 0);
    g_free(name_label_text);

    char *balance_label_text = g_strdup_printf("Balance: %d", user->balance);
    label_balance = gtk_label_new(balance_label_text);
    gtk_box_pack_start(GTK_BOX(vbox), label_balance, TRUE, TRUE, 0);
    g_free(balance_label_text);

    button_withdraw = gtk_button_new_with_label("Withdraw");
    gtk_box_pack_start(GTK_BOX(vbox), button_withdraw, TRUE, TRUE, 0);

    button_deposit = gtk_button_new_with_label("Deposit");
    gtk_box_pack_start(GTK_BOX(vbox), button_deposit, TRUE, TRUE, 0);

    button_exit = gtk_button_new_with_label("Exit");
    gtk_box_pack_start(GTK_BOX(vbox), button_exit, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
}

int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv);

    struct User user = {"John Doe", 1000}; 
    displayMenu(&user);

    gtk_main();

    return 0;
}