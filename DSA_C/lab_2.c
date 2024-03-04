#include <stdio.h>
#include <stdlib.h>

// Function to input an array dynamically
int* input_array(int *n) {
    printf("Enter the size of the array: ");
    scanf("%d", n);
    int *arr = (int*)malloc(*n * sizeof(int)); // Allocate memory for the array
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter the elements of the array: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

// Function to print an array
void print_array(int *arr, int n) {
    printf("The array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform linear search for an element
void linear_search(int *arr, int n) {
    int key, found = 0;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Element not found in the array.\n");
    }
}

// Function to insert an element at a specified position
int* insert_element(int *arr, int *n) {
    int pos, val;
    printf("Enter the position and value to insert: ");
    scanf("%d %d", &pos, &val);
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return arr;
    }
    int *new_arr = (int*)realloc(arr, (*n + 1) * sizeof(int)); // Reallocate memory for the new array
    if (new_arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = *n; i > pos; i--) {
        new_arr[i] = new_arr[i - 1]; // Shift the elements to the right
    }
    new_arr[pos] = val; // Insert the value at the position
    (*n)++; // Increment the size of the array
    printf("Element inserted successfully.\n");
    return new_arr;
}

// Function to delete an element from a specified position
int* delete_element(int *arr, int *n) {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return arr;
    }
    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift the elements to the left
    }
    int *new_arr = (int*)realloc(arr, (*n - 1) * sizeof(int)); // Reallocate memory for the new array
    if (new_arr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    (*n)--; // Decrement the size of the array
    printf("Element deleted successfully.\n");
    return new_arr;
}

// Function to reverse an array
void reverse_array(int *arr, int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i]; // Swap the elements at the opposite ends
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    printf("Array reversed successfully.\n");
}

// Function to update the array
void update_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { // Even index
            arr[i] += 5; // Add 5 to the element
        }
        else { // Odd index
            arr[i] *= 2; // Multiply the element by 2
        }
    }
    printf("Array updated successfully.\n");
}

// Function to display the menu
void display_menu() {
    printf("Choose an option from the following:\n");
    printf("a. Linear search for an element.\n");
    printf("b. Inserting an element at specified position.\n");
    printf("c. Deleting an element from the specified position.\n");
    printf("d. Reversing the array.\n");
    printf("e. Updating the array.\n");
    printf("f. Exit the program.\n");
}

// Main function
int main() {
    int *arr, n;
    char choice;
    arr = input_array(&n); // Input the array
    print_array(arr, n); // Print the array
    do {
        display_menu(); // Display the menu
        printf("Enter your choice: ");
        scanf(" %c", &choice); // Input the choice
        switch (choice) {
            case 'a':
                linear_search(arr, n); // Perform linear search
                break;
            case 'b':
                arr = insert_element(arr, &n); // Insert an element
                print_array(arr, n); // Print the array
                break;
            case 'c':
                arr = delete_element(arr, &n); // Delete an element
                print_array(arr, n); // Print the array
                break;
            case 'd':
                reverse_array(arr, n); // Reverse the array
                print_array(arr, n); // Print the array
                break;
            case 'e':
                update_array(arr, n); // Update the array
                print_array(arr, n); // Print the array
                break;
            case 'f':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 'f');
    free(arr); // Free the memory allocated for the array
    return 0;
}