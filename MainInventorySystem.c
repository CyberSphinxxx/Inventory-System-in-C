#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

int addItem(struct Item inventory[], int count);
int removeItem(struct Item inventory[], int count);
void searchItem(struct Item inventory[], int count);
void listItems(struct Item inventory[], int count);


void separator(){
    printf("===================================\n");
}

int main() {
    struct Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
    separator();
    printf("Inventory System Menu:\n");
    separator();
    printf("What do you want to do?\n");
    printf("1.\tAdd Item\n");
    printf("2.\tRemove Item\n");
    printf("3.\tSearch Item\n");
    printf("4.\tList All Items\n");
    printf("5.\tExit\n");
    separator();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            itemCount = addItem(inventory, itemCount);
            break;
        case 2:
            itemCount = removeItem(inventory, itemCount);
            break;
        case 3:
            searchItem(inventory, itemCount);
            break;
        case 4:
            listItems(inventory, itemCount);
            break;
        case 5:
            separator();
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            separator();
            printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 5);
    return 0;
}

int addItem(struct Item inventory[], int count) {
    if (count < MAX_ITEMS) {

        printf("Enter item name: ");
        scanf("%s", inventory[count].name);

        printf("Enter quantity: ");
        scanf("%d", &inventory[count].quantity);

        printf("Enter price: ");
        scanf("%f", &inventory[count].price);

        count++;
        separator();
        printf("Item Name:\t%s\nItem Quantity:\t%d\nItem Price:\t%0.2f\n",
        inventory[count - 1].name, inventory[count - 1].quantity, inventory[count - 1].price);
        printf("Has been added successfully!\n");
    }
    
    else {
        printf("Inventory is full. Cannot add more items.\n");
    }

    return count;
}

int removeItem(struct Item inventory[], int count) {
    if (count > 0) {
        char itemName[50];
        separator();
        printf("Enter the name of the item to remove: ");
        scanf("%s", itemName);

        int index = -1;
        for (int i = 0; i < count; i++) {
            if (strcmp(inventory[i].name, itemName) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            for (int i = index; i < count - 1; i++) {
                inventory[i] = inventory[i + 1];
            }

            count--;
            separator();
            printf("Item removed successfully.\n");  
        }
        
        else {
            separator();
            printf("Item not found in the inventory.\n");
        }   
    }
    
        else {
            separator();
            printf("Inventory is empty. Nothing to remove.\n");
        }

    return count;
}

void searchItem(struct Item inventory[], int count) {
    if (count > 0) {
        char itemName[50];

        separator();
        printf("Enter the name of the item to search\n");
        printf("Enter item name: ");
        scanf("%s", itemName);

    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, itemName) == 0) {
            separator();
            printf("Item found:\n");
            separator();
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            return;
        }
    }
    separator();
    printf("Item not found in the inventory.\n");
    }
    
    else {
        separator();
        printf("Inventory is empty. Nothing to search.\n");
    }
}

void listItems(struct Item inventory[], int count) {
    if (count > 0) {
        separator();
        printf("Inventory Items:\n");
        for (int i = 0; i < count; i++) {
            separator();
            printf("%d. %s:\nQuantity: %d\nPrice:    %.2f\n",
            i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
    
    else {
        separator();
        printf("Inventory is empty. Nothing to list.\n");
    }
}
