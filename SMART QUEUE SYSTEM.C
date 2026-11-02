
#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;
int tokenNumber = 1;

void generateToken()
{
    if (rear == MAX - 1)
    {
        printf("\nQueue is Full!\n");
    }
    else
    {
        rear++;
        queue[rear] = tokenNumber;

        printf("\nToken Generated Successfully!\n");
        printf("Your Token Number is: %d\n", tokenNumber);

        tokenNumber++;
    }
}

void callNextCustomer()
{
    if (front > rear)
    {
        printf("\nNo Customers in Queue!\n");
    }
    else
    {
        printf("\nNow Serving Token Number: %d\n", queue[front]);
        front++;
    }
}

void displayQueue()
{
    int i;

    if (front > rear)
    {
        printf("\nQueue is Empty!\n");
    }
    else
    {
        printf("\n========== WAITING QUEUE ==========\n");

        for (i = front; i <= rear; i++)
        {
            printf("Customer Token: %d\n", queue[i]);
        }

        printf("===================================\n");
    }
}

void waitingCount()
{
    if (front > rear)
    {
        printf("\nTotal Waiting Customers: 0\n");
    }
    else
    {
        printf("\nTotal Waiting Customers: %d\n", rear - front + 1);
    }
}

void searchToken()
{
    int token, i, found = 0;

    printf("\nEnter Token Number to Search: ");
    scanf("%d", &token);

    for (i = front; i <= rear; i++)
    {
        if (queue[i] == token)
        {
            printf("\nToken Number %d is Waiting in Queue.\n", token);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nToken Not Found in Waiting Queue!\n");
    }
}

int main()
{
    int choice;

    printf("\n====================================");
    printf("\n        SMART QUEUE SYSTEM");
    printf("\n====================================");

    do
    {
        printf("\n\n----------- MAIN MENU -----------");
        printf("\n1. Generate New Token");
        printf("\n2. Call Next Customer");
        printf("\n3. Display Waiting Queue");
        printf("\n4. Check Waiting Customers");
        printf("\n5. Search Token Number");
        printf("\n6. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                generateToken();
                break;

            case 2:
                callNextCustomer();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                waitingCount();
                break;

            case 5:
                searchToken();
                break;

            case 6:
                printf("\nThank You for Using Smart Queue System!\n");
                break;

            default:
                printf("\nInvalid Choice! Please Try Again.\n");
        }

    } while (choice != 6);

    return 0;
}
