#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

// Structure to hold medicine details
struct Medicine {
    int id;
    char name[50];
    char expiryDate[11]; // Format: YYYY-MM-DD
    float price;
};

// Function prototypes
void inputMedicines(struct Medicine medicines[], int count);
void sortMedicinesByExpiry(struct Medicine medicines[], int count);
void saveMedicinesToFile(struct Medicine medicines[], int count);
void displayMedicines(const struct Medicine medicines[], int count);

int main() {
    struct Medicine medicines[MAX_MEDICINES];
    int count;

    // Input number of medicines
    printf("Enter number of medicines: ");
    scanf("%d", &count);
    getchar(); // To consume the newline character after the number input

    // Input medicine details
    inputMedicines(medicines, count);

    // Sort medicines by expiry date
    sortMedicinesByExpiry(medicines, count);

    // Display sorted medicines
    printf("\nSorted Medicines (by Expiry Date):\n");
    displayMedicines(medicines, count);

    // Save medicines to file
    saveMedicinesToFile(medicines, count);

    return 0;
}

// Function to input medicine details
void inputMedicines(struct Medicine medicines[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Medicine %d: ", i + 1);
        scanf("%d, %49[^,], %10[^,], %f", &medicines[i].id, medicines[i].name, medicines[i].expiryDate, &medicines[i].price);
        getchar(); // To consume the newline character
    }
}

// Function to sort medicines by expiry date
void sortMedicinesByExpiry(struct Medicine medicines[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(medicines[j].expiryDate, medicines[j + 1].expiryDate) > 0) {
                struct Medicine temp = medicines[j];
                medicines[j] = medicines[j + 1];
                medicines[j + 1] = temp;
            }
        }
    }
}

// Function to save medicines to a file
void saveMedicinesToFile(struct Medicine medicines[], int count) {
    FILE *file = fopen("medicine_inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, %s, ₹%.2f\n", medicines[i].id, medicines[i].name, medicines[i].expiryDate, medicines[i].price);
    }

    fclose(file);
    printf("\nRecords saved in \"medicine_inventory.txt\"\n");
}

// Function to display medicines
void displayMedicines(const struct Medicine medicines[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %s\n", i + 1, medicines[i].name, medicines[i].expiryDate);
    }
}*
