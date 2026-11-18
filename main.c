#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 10

// Structure to store product details
struct Product {
    int id;
    char name[30];
    float price;
    int stock;
};

// Structure to store cart details
struct CartItem {
    int productId;
    char name[30];
    float price;
    int quantity;
};

// Function to display product catalogue
void displayProducts(struct Product p[], int n) {
    int i;

    printf("\n========== PRODUCT CATALOGUE ==========\n");
    printf("ID\tProduct\t\tPrice\tStock\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%-15s Rs.%.2f\t%d\n",
               p[i].id, p[i].name,
               p[i].price, p[i].stock);
    }
}

// Function to add products to cart
void addToCart(struct Product p[], int n,
               struct CartItem **cart, int *count) {

    int id, quantity, i, found = 0;

    printf("\nEnter Product ID: ");
    scanf("%d", &id);

    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Invalid quantity!\n");
        return;
    }

    for (i = 0; i < n; i++) {
        if (p[i].id == id) {
            found = 1;

            if (quantity > p[i].stock) {
                printf("Insufficient stock!\n");
                return;
            }

            // Allocate memory dynamically
            struct CartItem *temp =
                realloc(*cart, (*count + 1) * sizeof(struct CartItem));

            if (temp == NULL) {
                printf("Memory allocation failed!\n");
                return;
            }

            *cart = temp;

            (*cart)[*count].productId = p[i].id;

            snprintf((*cart)[*count].name,
                     sizeof((*cart)[*count].name),
                     "%s", p[i].name);

            (*cart)[*count].price = p[i].price;
            (*cart)[*count].quantity = quantity;

            (*count)++;
            p[i].stock -= quantity;

            printf("Product added to cart successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Invalid Product ID!\n");
    }
}

// Function to display cart and calculate bill
void displayCart(struct CartItem *cart, int count) {

    int i;
    float total = 0, discount = 0, finalAmount;

    if (count == 0) {
        printf("\nYour cart is empty!\n");
        return;
    }

    printf("\n========== SHOPPING CART ==========\n");
    printf("Product\t\tPrice\tQuantity\tAmount\n");

    for (i = 0; i < count; i++) {
        float amount = cart[i].price * cart[i].quantity;

        printf("%-15s Rs.%.2f\t%d\t\tRs.%.2f\n",
               cart[i].name,
               cart[i].price,
               cart[i].quantity,
               amount);

        total += amount;
    }

    // Apply discount
    if (total >= 5000) {
        discount = total * 0.20;
    }
    else if (total >= 2000) {
        discount = total * 0.10;
    }
    else if (total >= 1000) {
        discount = total * 0.05;
    }

    finalAmount = total - discount;

    printf("\n-----------------------------------\n");
    printf("Total Amount : Rs.%.2f\n", total);
    printf("Discount     : Rs.%.2f\n", discount);
    printf("Final Amount : Rs.%.2f\n", finalAmount);
    printf("-----------------------------------\n");
}

// Main function
int main() {

    struct Product products[MAX_PRODUCTS] = {
        {1, "Laptop", 45000, 5},
        {2, "Mobile", 15000, 10},
        {3, "Headphones", 1500, 15},
        {4, "Keyboard", 800, 20},
        {5, "Mouse", 500, 25}
    };

    struct CartItem *cart = NULL;

    int count = 0;
    int choice;

    do {
        printf("\n======= E-COMMERCE SHOPPING CART =======\n");
        printf("1. Display Product Catalogue\n");
        printf("2. Add Item to Cart\n");
        printf("3. View Cart and Bill\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayProducts(products, 5);
                break;

            case 2:
                displayProducts(products, 5);
                addToCart(products, 5, &cart, &count);
                break;

            case 3:
                displayCart(cart, count);
                break;

            case 4:
                if (count == 0) {
                    printf("\nYour cart is empty!\n");
                } else {
                    printf("\n========== ORDER CONFIRMED ==========\n");
                    displayCart(cart, count);
                    printf("\nThank you for shopping with us!\n");

                    free(cart);
                    cart = NULL;
                    count = 0;

                    for (int i = 0; i < 5; i++) {
                        products[i].stock =
                            (int[]){5, 10, 15, 20, 25}[i];
                    }
                }
                break;

            case 5:
                printf("\nThank you for visiting our store!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    free(cart);

    return 0;
}
