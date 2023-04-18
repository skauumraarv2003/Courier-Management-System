#include <stdio.h>

// structure to hold courier information
struct Courier {
    char tracking_number[20];
    char sender_name[50];
    char receiver_name[50];
    char status[20];
};

// function to insert a new courier entry
void insertCourier(struct Courier c[], int *count) {
    printf("Enter tracking number: ");
    scanf("%s", c[*count].tracking_number);
    printf("Enter sender name: ");
    scanf("%s", c[*count].sender_name);
    printf("Enter receiver name: ");
    scanf("%s", c[*count].receiver_name);
    printf("Enter status: ");
    scanf("%s", c[*count].status);
    (*count)++;
    printf("Courier added successfully!\n");
}

// function to display all courier entries
void displayCouriers(struct Courier c[],int count) {
	int i;
    if (count == 0) {
        printf("No couriers found!\n");
        return;
    }
    printf("Tracking Number\tSender Name\tReceiver Name\tStatus\n");
    printf("\n");
    for (i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\n", c[i].tracking_number, c[i].sender_name, c[i].receiver_name, c[i].status);
    }
}

// function to search for a courier entry by tracking number
void searchCourier(struct Courier c[], int count) {
	int i;
    if (count == 0) {
        printf("No couriers found!\n");
        return;
    }
    char search_num[20];
    printf("Enter tracking number to search: ");
    scanf("%s", search_num);
    for (i = 0; i < count; i++) {
        if (strcmp(search_num, c[i].tracking_number) == 0) {
            printf("Courier found!\n");
            printf("Tracking Number\tSender Name\tReceiver Name\tStatus\n");
            printf("---------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\t\t%s\n", c[i].tracking_number, c[i].sender_name, c[i].receiver_name, c[i].status);
            return;
        }
    }
    printf("Courier not found!\n");
}

// function to delete or update a courier entry by tracking number
void deleteOrUpdateCourier(struct Courier c[], int *count) {
	int i,j;
    if (*count == 0) {
        printf("No couriers found!\n");
        return;
    }
    char search_num[20];
    printf("Enter tracking number to delete/update: ");
    scanf("%s", search_num);
    for (i = 0; i < *count; i++) {
        if (strcmp(search_num, c[i].tracking_number) == 0) {
            printf("Courier found!\n");
            printf("Tracking Number\tSender Name\tReceiver Name\tStatus\n");
            printf("---------------------------------------------------------\n");
            printf("%s\t\t%s\t\t%s\t\t%s\n", c[i].tracking_number, c[i].sender_name, c[i].receiver_name, c[i].status);
            printf("Do you want to delete (D) or update (U) this courier? ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'D' || choice == 'd') {
                for (j = i; j < *count - 1; j++) {
                    c[j] = c[j+1];
                }
                (*count)--;
                printf("Courier deleted successfully!\n");
            }
           else if (choice == 'U' || choice == 'u') {
            printf("Enter new sender name (press enter to skip): \n");
            scanf("%s", c[i].sender_name);
            printf("Enter new receiver name (press enter to skip): \n");
            scanf("%s", c[i].receiver_name);
            printf("Enter new status (press enter to skip): \n");
            scanf("%s", c[i].status);
            printf("Courier updated successfully!\n");
        	}
        }
    }
}

// function to sort the Courier
void sortCouriers(struct Courier c[], int count) {
	int i,j;
if (count == 0) {
printf("No couriers found!\n");
return;
}
for (i = 0; i < count - 1; i++) {
for (j = i + 1; j < count; j++) {
if (strcmp(c[i].tracking_number, c[j].tracking_number) > 0) {
struct Courier temp = c[i];
c[i] = c[j];
c[j] = temp;
}
}
}
printf("Couriers sorted successfully!\n");
}

int main() {
struct Courier couriers[100];
int count = 0;
int choice;
do {
printf("\nCourier Management System\n");
printf("--------------------------\n");
printf("1. Insert new courier\n");
printf("2. Display all couriers\n");
printf("3. Search for a courier\n");
printf("4. Delete/Update a courier\n");
printf("5. Sort couriers by tracking number\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
	insertCourier(couriers, &count);
	break;
case 2:
	displayCouriers(couriers, count);
	break;
case 3:
    searchCourier(couriers, count);
    break;
case 4:
    deleteOrUpdateCourier(couriers, &count);
    break;
case 5:
    sortCouriers(couriers, count);
    break;
case 6:
    printf("Exiting...\n");
    break;
default:
printf("Invalid choice! Please try again.\n");
}

} while (choice != 6);
return 0;
}
