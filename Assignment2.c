#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100

// Structure to hold car details
struct Car {
    int carID;
    char model[50];
    union {
        float rentPerDay;
        float totalRent;
    } rent;
    int isDailyRent; 
};

// Function prototypes
void inputCars(struct Car cars[], int count);
void displayCars(const struct Car cars[], int count);
void saveCarsToFile(const struct Car cars[], int count);
void updateCarRent(struct Car cars[], int count);

int main() {
    struct Car cars[MAX_CARS];
    int count;

    // Input number of cars
    printf("Enter number of cars: ");
    scanf("%d", &count);
    getchar(); 

    // Input car details
    inputCars(cars, count);

    // Display available cars
    printf("\nCars Available:\n");
    displayCars(cars, count);

    // Save cars to file
    saveCarsToFile(cars, count);

    // Update rental information
    updateCarRent(cars, count);

    return 0;
}

// Function to input car details
void inputCars(struct Car cars[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Car %d: ", i + 1);
        scanf("%d, %49[^,], ₹%f/day", &cars[i].carID, cars[i].model, &cars[i].rent.rentPerDay);
        cars[i].isDailyRent = 1; 
        getchar(); 
    }
}

// Function to display cars
void displayCars(const struct Car cars[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s - ₹%.2f/day\n", cars[i].carID, cars[i].model, cars[i].rent.rentPerDay);
    }
}

// Function to save cars to a file
void saveCarsToFile(const struct Car cars[], int count) {
    FILE *file = fopen("car_rentals.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d, %s, ₹%.2f/day\n", cars[i].carID, cars[i].model, cars[i].rent.rentPerDay);
    }

    fclose(file);
    printf("\nData saved in \"car_rentals.txt\"\n");
}

// Function to update rental information
void updateCarRent(struct Car cars[], int count) {
    int carID;
    float newRent;

    printf("\nEnter Car ID to update rent: ");
    scanf("%d", &carID);

    for (int i = 0; i < count; i++) {
        if (cars[i].carID == carID) {
            printf("Current Rent for %s: ₹%.2f/day\n", cars[i].model, cars[i].rent.rentPerDay);
            printf("Enter new rent: ₹");
            scanf("%f", &newRent);
            cars[i].rent.rentPerDay = newRent; // Update the rent
            printf("Rent updated successfully!\n");
            break;
        }
    }
}

2nd que
