#include <gtk/gtk.h>
#include "main.h"

void loadUserData(struct User *user);

void displayMenu(struct User *user);


void loadUserData(struct User *user) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open data.txt\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    if (fgets(line, sizeof(line), file) != NULL) {
        int id;
        sscanf(line, "%d :[\"%[^\"]\", %d]", &id, user->name, &user->balance);
        user->id = id; // Assuming id is read from data.txt
    }

    fclose(file);
}


int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    struct User user;
    loadUserData(&user);

    displayMenu(&user);

    gtk_main();

    return 0;
}
