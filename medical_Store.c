#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for medical product
struct product {
    char name[100];
    int quantity;
    float price;
};

// Function prototypes
void add_product();
void modify_product();
void delete_product();
void view_products();

// Declare global variables
struct product products[100];
int count = 0;

// Main function
int main() {
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add product\n");
        printf("2. Modify product\n");
        printf("3. Delete product\n");
        printf("4. View products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                modify_product();
                break;
            case 3:
                delete_product();
                break;
            case 4:
                view_products();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add a product
void add_product() {
    struct product p;

    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);

    products[count++] = p;

    printf("Product added successfully!\n");
}

// Function to modify a product
void modify_product() {
    int index;
    char name[100];

    printf("Enter product name: ");
    scanf("%s", name);

    for (index = 0; index < count; index++) {
        if (strcmp(products[index].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &products[index].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[index].price);

            printf("Product modified successfully!\n");
            return;
        }
    }

    printf("Product not found! Please try again.\n");
}

// Function to delete a product
void delete_product() {
    int index, found = 0;
    char name[100];

    printf("Enter product name: ");
    scanf("%s", name);

    for (index = 0; index < count; index++) {
        if (strcmp(products[index].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int i = index; i < count - 1; i++) {
            products[i] = products[i + 1];
        }

        count--;
        printf("Product deleted successfully!\n");
    } else {
        printf("Product not found! Please try again.\n");
    }
}

// Function to view all products
void view_products() {
    if (count == 0) {
        printf("No products found!\n");
    } else {
        printf("\nProduct Name\tQuantity\tPrice\n");
        for (int i = 0; i < count; i++) {
            printf("%s\t\t%d\t\t%.2f\n", products[i].name, products[i].quantity, products[i].price);
        }
    }
}