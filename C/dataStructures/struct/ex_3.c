#include <stdio.h>
#include <string.h>
/*
1. Be a defined structure to describe the cars of a given structure, containing
the following fields:
Brand: size 15 rope
year: whole
color: size 10 rope
price: real
a) Write the definition of the car structure.
b) Create a new type from the structure created with the typedef command.
c) Declare the vector vetcars of the type created in letter b, size 20;
d) Create a function to fill the list of cars with information provided by the
user;
e) Create a function that increases the list of cars, a price and prints the cars (brand,
color and year) which price is equal to or less than the price received.
f) Create a function that increases the list of cars, a make, year and color and inform if
whether or not there is a car with these characteristics.
*/

// redefine new struct to Car
typedef struct
{
    char brand[15];
    int year;
    char color[10];
    float price;
} Car;

void readCars(Car *cars)
{
    for (int i = 0; i < 2; i++)
    {
        scanf(" %[^\n] %i %[^\n] %f", cars[i].brand, &cars[i].year, cars[i].color, &cars[i].price);
    }
}

void printCars(Car *cars)
{
    for (int i = 0; i < 2; i++)
    {
        printf("\n\nCAR %d", i);
        printf("\n%s\n%i\n%s\n%f", cars[i].brand, cars[i].year, cars[i].color, cars[i].price);
    }
}

void priceUnder(float price, Car *cars)
{
    for (int i = 0; i < 2; i++)
    {
        if (cars[i].price < price)
        {
            printf("\n\n%s\n%f", cars[i].brand, cars[i].price);
        }
    }
}

void carMatch(Car *cars, char brand[], int year, char color[])
{
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(cars[i].brand, brand) == 0 && cars[i].year == year && strcmp(cars[i].color, color) == 0)
        {
            printf("\n\nCar Found");
            return;
        }
        printf("\n\nCar Wasn't Found");
    }
}

int main()
{
    Car cars[2];
    readCars(cars);
    printCars(cars);
    priceUnder(10, cars);
    carMatch(cars, "ford", 2022, "blue");
    return 0;
}