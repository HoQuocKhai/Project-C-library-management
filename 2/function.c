#include <stdio.h>
#include "datatype.h"
#include "function.h"
void runMenu(){//nhap vao lua chon
    int size = 0;
    do {
    	printMenu();// in Menu quan ly sach.
    	int choice;
    	printf("\n\tEnter your choice: ");
    	scanf("%d", &choice);
    	
        switch (choice) {
            case 1://in danh sach sach
                printListBook(&size);
                break;
            case 2://them sach
                addBook(&size);
                break;
            case 3://chinh sua thong tin sach
            	editBook();
            case 9:
                return 0;
            default: {
                printf("\tInvalid Input.\n");
            }
        }
    }while (1);
}

void printMenu(){
	printf("\t+*****************MENU****************+\n");
 	printf("\t|1. Show list of books.%15s|\n"," ");
	printf("\t|2. Add book.%25s|\n"," ");
	printf("\t|3. Edit book information.%12s|\n"," ");
 	printf("\t|4. Delete books.%21s|\n"," ");
 	printf("\t|5. Search books by name.%13s|\n"," ");
  	printf("\t|6. Sort books by price.%14s|\n"," ");
  	printf("\t|7. Check the input data for the book.|\n");
  	printf("\t|8. Exit.%29s|\n"," ");
	printf("\t+*****************MENU****************+\n");
};

 void printListBook(int *size ) {//in danh sach sach
  	FILE *f = fopen("C:\\Users\\Admin\\CLionProjects\\2\\booklistdata.txt", "r");
    struct Book book;
    printf("\n\n\t+******************************************************+\n");
    printf("\t|BookID%2s|Title%7s|Author%6s|Quantity%2s|Price%3s|\n"," "," "," "," "," ");

    while (fscanf(f, "%s %s %s %d %f", book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        
        printf("\t|%-8s|%-12s|%-12s|%-10d|%-8.2f|\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }
    printf("\t+******************************************************+\n\n");

    fclose(f);
}


void addBook(int *size) {
	struct Book book;
    FILE *f = fopen("C:\\Users\\Admin\\CLionProjects\\2\\booklistdata.txt","a");
  	printf("\tEnter the ID: ");
    scanf("%s", book.bookID);

    printf("\tEnter the title: ");
    scanf("%s", book.title);

    printf("\tEnter the author: ");
    scanf("%s", book.author);

    printf("\tEnter the quantity: ");
    scanf("%d", &book.quantity);

    printf("\tEnter the price: ");
    scanf("%f", &book.price);

    fprintf(f, "%s %s %s %d %.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);

    fclose(f);
    
    printf("\tAdded book successfully.\n");
    (*size)++;
};

void editBook() {
    FILE *f = fopen("C:\\Users\\Admin\\CLionProjects\\2\\booklistdata.txt", "r");
    if (f == NULL) {
        printf("\tError opening file.\n");
        return;
    }

    struct Book books[100];
    int count = 0;
    
    while (fscanf(f, "%s %s %s %d %f", books[count].bookID, books[count].title, books[count].author, &books[count].quantity, &books[count].price) == 5) {
        count++;
    }
    fclose(f);

    char editBookID[10];
    int found = 0;

    printf("\tEnter the book ID you want to edit: ");
    scanf("%s", editBookID);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(books[i].bookID, editBookID) == 0) {
            found = 1;

            printf("\n\tCurrent book information:\n");
            printf("\tID: %s\n", books[i].bookID);
            printf("\tTitle: %s\n", books[i].title);
            printf("\tAuthor: %s\n", books[i].author);
            printf("\tQuantity: %d\n", books[i].quantity);
            printf("\tPrice: %.2f\n", books[i].price);

            printf("\n\tEnter a new title: ");
            scanf("%s", books[i].title);
            printf("\tEnter new author: ");
            scanf("%s", books[i].author);
            printf("\tEnter the new quantity: ");
            scanf("%d", &books[i].quantity);
            printf("\tEnter new price: ");
            scanf("%f", &books[i].price);

            printf("\n\tThe book information has been successfully edited.\n");
            break;
        }
    }

    if (!found) {
        printf("\tNo books found with ID %s. Please try again.\n", editBookID);
        return;
    }

    f = fopen("C:\\Users\\Admin\\CLionProjects\\2\\booklistdata.txt", "w");
    if (f == NULL) {
        printf("\tError opening file to save changes.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(f, "%s %s %s %d %.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }

    fclose(f);
	int choice;
	printf("\t1.Return to menu: ");
	printf("\t2.Exit the program: \n");
    printf("\tEnter your choice: ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		runMenu();
		break;
		case 2:
		exit(1);
		default:
		printf("\tInvalid Input please try again.\n");
	}
}
