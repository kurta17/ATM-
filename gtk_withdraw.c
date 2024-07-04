#include <gtk/gtk.h>
#include "main.h"

extern void on_withdraw_confirm_clicked(GtkWidget *widget, gpointer data);


// #ifndef USE_ASSEMBLY_WITHDRAW

// void on_withdraw_confirm_clicked(GtkWidget *widget, gpointer data) {
//     struct DialogData *dialog_data = (struct DialogData *)data;
//     const gchar *amount_str = gtk_entry_get_text(GTK_ENTRY(dialog_data->entry));
//     int amount = atoi(amount_str);

//     if (amount > 0 && amount <= dialog_data->user->balance) {
//         dialog_data->user->balance -= amount;
//         updateMainDisplay(dialog_data->user);
//         updateUserData(dialog_data->user); 
//     }

//     gtk_widget_destroy(dialog_data->dialog);
//     g_free(dialog_data);
// }

// #endif