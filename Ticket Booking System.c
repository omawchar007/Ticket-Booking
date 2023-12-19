#include <stdio.h>
#include <string.h>

typedef struct Customer {
    char destination[50];  
    char name[100];
    int mobile_number;
    char email[200];
    char gender[50];
    int age;
} Tk;

void bookTicket(int *index, Tk clients[], int destinationP) {
    if (*index < 500) {
        printf("Enter The Name: ");
        scanf("%99s", clients[*index].name);

        printf("Enter The Mobile Number: ");
        scanf("%d", &clients[*index].mobile_number);

        printf("Enter The Email: ");
        scanf("%199s", clients[*index].email);

        printf("Enter The Gender (1 for Male, 0 for Female): ");
        int genderInput;
        scanf("%d", &genderInput);
        if (genderInput == 1) {
            strcpy(clients[*index].gender, "Male");
        } else {
            strcpy(clients[*index].gender, "Female");
        }

       

        if (destinationP == 1) {
            strcpy(clients[*index].destination, "Panvel");
        } else if (destinationP == 2) {
            strcpy(clients[*index].destination, "Pune");
        } else if (destinationP == 3) {
            strcpy(clients[*index].destination, "Satara");
        } else if (destinationP == 4) {
            strcpy(clients[*index].destination, "Kolhapur");
        }

        (*index)++;
    } else {
        printf("Array is full. Cannot add more entries.\n");
    }
}

void displayBookingByMobile(int new_number, Tk clients[], int index) {
    for (int i = 0; i < index; i++) {
        if (new_number == clients[i].mobile_number) {
            printf("\n");
            printf("Your Booking Nagpur To %s\n", clients[i].destination);
            printf("\n");

            printf("Name: %s\n", clients[i].name);
            printf("Email: %s\n", clients[i].email);
            printf("Gender: %s\n", clients[i].gender);
            printf("Age: %d\n", clients[i].age);
        }
    }
}

void deleteBookingByMobile(int delete_number, Tk clients[], int *index) {
    for (int i = 0; i < *index; i++) {
        if (delete_number == clients[i].mobile_number) {
            for (int j = i; j < *index - 1; j++) {
                clients[j] = clients[j + 1];
            }
            (*index)--;
            printf("Booking with Mobile Number %d deleted.\n", delete_number);
            return;
        }
    }
    printf("Booking with Mobile Number %d not found.\n", delete_number);
}

int main() {
    int op;
    int new_number;
    int index = 0;
    int delete_number;
    Tk clients[500];

    do {
        printf("\n");
        printf("Ticket Booking\n");
        printf("\n");
        printf("Choice The Option- \n");
        printf("\n");
        printf("1 - Panvel\n");
        printf("2 - Pune\n");
        printf("3 - Satara\n");
        printf("4 - Kolhapur\n");
        printf("5 - My Booking\n");
        printf("6 - Cancel My Booking\n");  
        printf("7 - Exit The program\n");
        printf("Enter Right Option: ");
        scanf("%d", &op);

        if (op > 7) {
            printf("You Entered Wrong Option, Please Enter Right\n");
        } else {
            switch (op) {
                case 1:
                    printf("Nagpur -> Panvel\n");
                    bookTicket(&index, clients, 1);
                    break;
                case 2:
                    printf("Your Ticket Booked Nagpur -> Pune\n");
                    bookTicket(&index, clients, 2);
                    break;
                case 3:
                    printf("Your Ticket Booked Nagpur -> Satara\n");
                    bookTicket(&index, clients, 3);
                    break;
                case 4:
                    printf("Your Ticket Booked Nagpur -> Kolhapur\n");
                    bookTicket(&index, clients, 4);
                    break;
                case 5:
                    printf("Enter The Mobile Number: ");
                    scanf("%d", &new_number);
                    displayBookingByMobile(new_number, clients, index);
                    break;

                case 6:
                    printf("Enter The Mobile Number to Delete Booking: ");
                    scanf("%d", &delete_number);
                    deleteBookingByMobile(delete_number, clients, &index);
                    break;
            }
        }
    } while (op != 7);

    return 0;
}
