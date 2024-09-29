#include <stdio.h>
#include <stdlib.h>

struct User {
    char *name;
    char *surname;
    char *email;
};


struct User createUser(char *name, char *surname, char *email) {
    struct User temp;
    temp.name = name;
    temp.surname = surname;
    temp.email = email;
    return temp;
}

struct User printUserInfo(struct User user) {
    printf("Name: %s\n", user.name);
    printf("Surname: %s\n", user.surname);
    printf("Email: %s\n", user.email);
    return user;
}

void freeUserMemory(struct User *user) {
    free(user->name);
    free(user->surname);
    free(user->email);
}

int main(void) {
    struct User listOfUsers[30];
    bool isTrue = true;
    int userPos = 0;

    while (isTrue) {
        printf("What would you like to do?\n");
        printf("1. Add User\n");
        printf("2. Remove User\n");
        printf("3. List Users\n");
        printf("4. Exit\n");

        printf("Your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int lengthOfName;
                int lengthOfSurname;
                int lengthOfEmail;

                printf("Enter the length of your name: ");
                scanf("%d", &lengthOfName);

                char *name = malloc(lengthOfName * sizeof(char) + 1);
                printf("Enter your name: ");
                scanf("%s", name);

                printf("Enter the length of your surname: ");
                scanf("%d", &lengthOfSurname);

                char *surname = malloc(lengthOfSurname * sizeof(char) + 1);
                printf("Enter your surname: ");
                scanf("%s", surname);

                printf("Enter the length of your e-mail: ");
                scanf("%d", &lengthOfEmail);

                char *email = malloc(lengthOfEmail * sizeof(char) + 1);
                printf("Enter your email: ");
                scanf("%s", email);

                struct User user = createUser(name, surname, email);
                listOfUsers[userPos] = user;
                userPos++;

                break;

            case 2:
                int idOfUser;
                printf("Enter the ID of the user you wish to remove: ");
                scanf("%d", &idOfUser);

                if (idOfUser >= 0 && idOfUser < userPos) {
                    freeUserMemory(&listOfUsers[idOfUser]);

                    for (int i = idOfUser; i < userPos - 1; i++) {
                        listOfUsers[i] = listOfUsers[i + 1];
                    }
                    userPos--;
                    printf("User removed.\n");
                } else {
                    printf("Invalid ID.\n");
                }
                break;

            case 3:
                if (userPos == 0) {
                    printf("There are no users in this list.\n");
                } else {
                    for (int i = 0; i < userPos; i++) {
                        printUserInfo(listOfUsers[i]);
                        printf("\n");
                    }
                }
                break;

            case 4:
                printf("You've exited the program.\n");
                isTrue = false;

                for (int i = 0; i < userPos; i++) {
                    freeUserMemory(&listOfUsers[i]);
                }
                break;

            default:
                printf("Wrong choice.\n");
        }
    }
}
