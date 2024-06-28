#include <gtk/gtk.h>
#include "main.h"  

GtkWidget *window;
GtkWidget *label_name;
GtkWidget *label_balance;
GtkWidget *button_withdraw;
GtkWidget *button_deposit;
GtkWidget *button_exit;

void updateUserData(struct User *user) {
    FILE *file = fopen("data.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open data.txt for writing\n");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "%d :[\"%s\", %d]\n", user->id, user->name, user->balance);

    fclose(file);
}

void updateMainDisplay(struct User *user) {
    char *balance_label_text = g_strdup_printf("Balance: %d", user->balance);
    gtk_label_set_text(GTK_LABEL(label_balance), balance_label_text);
    g_free(balance_label_text);
}

void on_deposit_confirm_clicked(GtkWidget *widget, gpointer data) {
    struct DialogData *dialog_data = (struct DialogData *)data;
    const gchar *amount_str = gtk_entry_get_text(GTK_ENTRY(dialog_data->entry));
    int amount = atoi(amount_str);

    if (amount > 0) {
        dialog_data->user->balance += amount;
        updateMainDisplay(dialog_data->user);
        updateUserData(dialog_data->user); // Update data.txt
    }

    gtk_widget_destroy(dialog_data->dialog);
    g_free(dialog_data);
}

void on_deposit_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_dialog_new_with_buttons("Deposit", GTK_WINDOW(window), GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);

    GtkWidget *amount_entry;
    amount_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(amount_entry), "Enter amount");

    GtkWidget *content_area;
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_add(GTK_CONTAINER(content_area), amount_entry);
    gtk_widget_show_all(dialog);

    struct DialogData *dialog_data = g_new(struct DialogData, 1);
    dialog_data->dialog = dialog;
    dialog_data->entry = amount_entry;
    dialog_data->user = (struct User *)data;

    int result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_OK) {
        on_deposit_confirm_clicked(NULL, dialog_data);
    } else {
        gtk_widget_destroy(dialog);
        g_free(dialog_data);
    }
}

void on_withdraw_confirm_clicked(GtkWidget *widget, gpointer data) {
    struct DialogData *dialog_data = (struct DialogData *)data;
    const gchar *amount_str = gtk_entry_get_text(GTK_ENTRY(dialog_data->entry));
    int amount = atoi(amount_str);

    if (amount > 0 && amount <= dialog_data->user->balance) {
        dialog_data->user->balance -= amount;
        updateMainDisplay(dialog_data->user);
        updateUserData(dialog_data->user); // Update data.txt
    }

    gtk_widget_destroy(dialog_data->dialog);
    g_free(dialog_data);
}

void on_withdraw_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    dialog = gtk_dialog_new_with_buttons("Withdraw", GTK_WINDOW(window), GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);

    GtkWidget *amount_entry;
    amount_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(amount_entry), "Enter amount");

    GtkWidget *content_area;
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_container_add(GTK_CONTAINER(content_area), amount_entry);
    gtk_widget_show_all(dialog);

    struct DialogData *dialog_data = g_new(struct DialogData, 1);
    dialog_data->dialog = dialog;
    dialog_data->entry = amount_entry;
    dialog_data->user = (struct User *)data;

    int result = gtk_dialog_run(GTK_DIALOG(dialog));
    if (result == GTK_RESPONSE_OK) {
        on_withdraw_confirm_clicked(NULL, dialog_data);
    } else {
        gtk_widget_destroy(dialog);
        g_free(dialog_data);
    }
}

void displayMenu(struct User *user) {
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ATM Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 100);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    label_name = gtk_label_new(NULL);
    gtk_label_set_text(GTK_LABEL(label_name), user->name);
    gtk_grid_attach(GTK_GRID(grid), label_name, 0, 0, 1, 1);
    gtk_widget_set_halign(label_name, GTK_ALIGN_CENTER);

    label_balance = gtk_label_new(NULL);
    updateMainDisplay(user);
    gtk_grid_attach(GTK_GRID(grid), label_balance, 0, 1, 1, 1);
    gtk_widget_set_halign(label_balance, GTK_ALIGN_CENTER);

    button_withdraw = gtk_button_new_with_label("Withdraw");
    g_signal_connect(button_withdraw, "clicked", G_CALLBACK(on_withdraw_button_clicked), user);
    gtk_grid_attach(GTK_GRID(grid), button_withdraw, 0, 2, 1, 1);
    gtk_widget_set_halign(button_withdraw, GTK_ALIGN_CENTER);

    button_deposit = gtk_button_new_with_label("Deposit");
    g_signal_connect(button_deposit, "clicked", G_CALLBACK(on_deposit_button_clicked), user);
    gtk_grid_attach(GTK_GRID(grid), button_deposit, 0, 3, 1, 1);
    gtk_widget_set_halign(button_deposit, GTK_ALIGN_CENTER);

    button_exit = gtk_button_new_with_label("Exit");
    g_signal_connect(button_exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);
    gtk_grid_attach(GTK_GRID(grid), button_exit, 0, 4, 1, 1);
    gtk_widget_set_halign(button_exit, GTK_ALIGN_CENTER);

    gtk_grid_set_row_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_container_set_border_width(GTK_CONTAINER(window), 40);

    gtk_widget_show_all(window);
}
