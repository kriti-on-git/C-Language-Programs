#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LEN 50
#define PHONE_LEN 15

// Structure to store contact info
struct Contact {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
};

// Global array of contacts
struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

// Function to add a new contact
void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Contact list is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf(" %[^\n]s", contacts[contactCount].name); // Read full line
    printf("Enter phone number: ");
    scanf(" %[^\n]s", contacts[contactCount].phone);

    contactCount++;
    printf("Contact added successfully.\n");
}

// Function to view all contacts
void viewContacts() {
    if (contactCount == 0) {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Contact #%d:\n", i + 1);
        printf("Name : %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("---------------------\n");
    }
}

// Function to search for a contact by name
void searchContact() {
    char searchName[NAME_LEN];
    printf("Enter name to search: ");
    scanf(" %[^\n]s", searchName);

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Contact found!\n");
            printf("Name : %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

// Main menu
int main() {
    int choice;

    do {
        printf("\n=== Simple Contact Book ===\n");
        printf("1. Add Contact\n");
        printf("2. View All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
