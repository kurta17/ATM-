#include <gtk/gtk.h>
#include "main.h"

void loadUserData(struct User *user, int id); // Corrected declaration

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

void loadUserData(struct User *user, int id) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open data.txt\n");
        exit(EXIT_FAILURE);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int file_id;
        sscanf(line, "%d :[\"%[^\"]\", %d]", &file_id, user->name, &user->balance);
        if (file_id == id) {
            user->id = id;
            fclose(file);
            return;
        }
    }

    user->id = -1; // Indicate user does not exist
    fclose(file);
}
