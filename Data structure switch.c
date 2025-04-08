/*
Project Name: Array Manipulation
Created By: Abdullah Al Mahdi
Student ID: 0182420012101256
GitHub ID:https://github.com/abdmahdi56
Course Instructor: Md. Jehadul Islam Mony
Batch: CSE 64F
Department: Computer Science and Engineering
Institution: Leading University, Sylhet
*/

#include <stdio.h>
#define Max 100

int main() {
    //int const Max = 100;
    int arr[Max];
    int n = 0;
    int c;

    printf("\nChoose your operation:\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Exit\n");

    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1: {// Insert
                printf("How many numbers do you want to insert (max %d)? ", Max);
                scanf("%d", &n);

                if (n > Max) {
                    printf("Error: Input size exceeds limit!\n");
                    continue;
                }

                printf("Enter %d numbers: ", n);
                for (int i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Insertion successful.\n");
                break;
            }

            case 2: { // Update
                int u, uv, found = 0;
                printf("Which number do you want to update: ");
                scanf("%d", &u);
                printf("Enter the updated value: ");
                scanf("%d", &uv);

                for (int i = 0; i < n; i++) {
                    if (arr[i] == u) {
                        arr[i] = uv;
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Updated successfully.\n");
                } else {
                    printf("Number not found!\n");
                }
                break;
            }

            case 3: { // Delete
                int d, count = 0;
                printf("Enter the number you want to delete: ");
                scanf("%d", &d);


                for (int i = 0; i < n; i++) {
                    if (arr[i] == d) {
                        count++;
                    }
                }


                if (count == 0) {
                    printf("Number not found!\n");
                    break;
                }
                if(count==1){
                        for(int i=0;i<n;i++){
                            if(arr[i]==d){
                                for(int j=i;j<n-1;j++){
                                    arr[j]=arr[j+1];

                                }

                            }
                        }
                        n--;

                }else if(count>1){
                    printf("The number %d appears %d times.\n", d, count);
                    printf("Enter the index (0 to %d) of the occurrence you want to delete: ", n - 1);

                    int di;
                    scanf("%d", &di);


                    if (di < 0 || di >= n || arr[di] != d) {
                        printf("Invalid index or the number at this index is not %d!\n", d);
                        break;
                    }


                    for (int i = di; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;

                }



                printf("Deleted successfully.\nUpdated list: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");

                break;
            }



            case 4: // Display
                if (n == 0) {
                    printf("No values inserted.\n");
                } else {
                    printf("Stored values: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 5: { // Search
                int s, found = 0;
                printf("Enter the value to search: ");
                scanf("%d", &s);

                for (int i = 0; i < n; i++) {
                    if (arr[i] == s) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Found!\n");
                } else {
                    printf("Not found!\n");
                }
                break;
            }

            case 6: // Exit
                printf("Thanks for using the program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

