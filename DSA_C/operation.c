// Q-1.Write menu-driven program in c to input 1D array and perform following operations:
// a.Linear search for an element.
// b.Inserting an element at specified position.
// c.Deleting an element from the specified position.
// d.Reversing the array.
// e.Updating the array , multiply the odd-indexed elements by 2 and adding 5 to all the elements at even index.

#include<stdio.h>
#include<stdlib.h>
// Function to display the array elements
void display(int arr[], int n)
{
    printf("The array elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function to update the array
void update(int arr[], int n)
{
    // multiply the odd-indexed elements by 2
    for (int i = 1; i < n; i += 2)
    {
        arr[i] *= 2;
    }
    // add 5 to all the elements at even index
    for (int i = 0; i < n; i += 2)
    {
        arr[i] += 5;
    }
}
// Function to reverse the array
void reverse(int arr[], int n)
{
    // swap the elements from both ends
    
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; // temporary variable 
    }
}

// Function to delete an element from a specified position
void delete (int arr[], int *n, int pos)
{
    if (*n == 0) // check if the array is empty
    {
        printf("Array is empty, cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) // check if the position is valid
    {
        printf("Invalid position, cannot delete.\n");
        return;
    }

    // shift the elements to the left from the position
    for (int i = pos; i < *n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    // decrement the size of the array
    (*n)--;
}

// Function to insert an element at a specified position
void insert(int arr[], int *n, int pos, int val)
{
    if (*n == 10) // check if the array is full
    {
        printf("Array is full, cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n) // check if the position is valid
    {
        printf("Invalid position, cannot insert.\n");
        return;
    }
    // shift the elements to the right from the position
    for (int i = *n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    // insert the value at the position
    arr[pos] = val;
    // increment the size of the array
    (*n)++;

}

// Function to perform linear search for an element
int linear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // return the index of the element if found
        }
    }
    return -1; // return -1 if not found
}

// Main function
int main()
{
    int arr[10]; // declare an array of size 10
    int n;        // declare a variable to store the size of the array
    int choice;   // declare a variable to store the user's choice
    int key, pos, val; // declare variables to store the input values


    printf("Enter the size of the array: ");
    scanf("%d", &n); // read the size of the array

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // read the elements of the array
    }
    do
    {
        // display the menu
        printf("\nMenu\n");
        printf("1. Linear search for an element\n");
        printf("2. Inserting an element at specified position\n");
        printf("3. Deleting an element from the specified position\n");
        printf("4. Reversing the array\n");
        printf("5. Updating the array\n");
        printf("6. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice); // read the user's choice

        switch (choice)
        {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &key); // read the element to search
            pos = linear_search(arr, n, key); // call the linear search function
            if (pos == -1) // check if the element is not found
            {
                printf("Element not found.\n");
            }
            else // otherwise
            {
                printf("Element found at index %d.\n", pos);
            }
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &val); // read the element to insert
            printf("Enter the position to insert: ");
            scanf("%d", &pos); // read the position to insert
            insert(arr, &n, pos, val); // call the insert function
            printf("Element inserted.\n");
            display(arr, n); // display the updated array
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &pos); // read the position to delete
            val = arr[pos]; // store the element to be deleted
            delete (arr, &n, pos); // call the delete function
            printf("Element %d deleted.\n", val);
            display(arr, n); // display the updated array
            break;
        case 4:
            reverse(arr, n); // call the reverse function
            printf("Array reversed.\n");
            display(arr, n); // display the reversed array
            break;
        case 5:
            update(arr, n); // call the update function
            printf("Array updated.\n");
            display(arr, n); // display the updated array
            break;
        case 6:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
            break;
        }
    } while (choice != 6); // repeat until the user chooses to exit
    return 0;
}