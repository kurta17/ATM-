#include <gtk/gtk.h>
#include "main.h"

void loadUserData(struct User *user, int id); 

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    int id;

    printf("Enter your ID: ");
    scanf("%d", &id);

    struct User user;
    loadUserData(&user, id); // Load user data based on ID entered

    if (user.id == -1) {
        printf("User with ID %d does not exist.\n", id);
        return EXIT_FAILURE;
    }

    displayMenu(&user);

    gtk_main();

    return 0;
}
