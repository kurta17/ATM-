#include <gtk/gtk.h>
#include "main.h"

void displayMenu(struct User *user);

struct User user = {"John Doe", 1000}; 

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    displayMenu(&user);

    gtk_main();

    return 0;
}
