#include <stdio.h>
#include "datatype.h"
#include "function.h"

void returnMenu(){
	do{
		int choice;
		printf("\n\t1.Return to menu: \n");
		printf("\t2.Exit the program: \n");
    	printf("\tEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice){
		case 1:
			runMenu();
		case 2:
			exit(1);
		default:
			printf("\tInvalid Input please try again.\n");
		}
	}while(1);
}

void runMenu(){//nhap vao lua chon
    do {
    	printMenu();// in Menu quan ly sach.
    	int choice,choice2;
    	printf("\n\tEnter your choice: ");
    	scanf("%d", &choice);
    	
        switch (choice) {
            case 1://in danh sach sach
                printListBook();
                break;
            case 2://them sach
                addBook();
                break;
            case 3://chinh sua thong tin sach
            	editBook();
            case 4://xoa sach theo id
            	deleteBook();
            case 5://xap sep sach theo gia
            	arrangeBook();
            case 6://tim sach theo ten
				searchBook();
            case 8://thoat chuong trình
            	exit(1);
            default: {
                printf("\tInvalid Input.\n");
            }
        }
    }while (1);
}

void printMenu(){
	printf("\t\t\t\t\t+********** BOOK MANAGEMENT **********+\n");
 	printf("\t\t\t\t\t|1. Show list of books.%15s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t\t|2. Add book.%25s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t\t|3. Edit book information.%12s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
 	printf("\t\t\t\t\t|4. Delete books.%21s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
 	printf("\t\t\t\t\t|5. Sort books by price.%14s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
  	printf("\t\t\t\t\t|6. Search books by name.%13s|\n"," ");
    printf("\t\t\t\t\t|-------------------------------------|\n");
  	printf("\t\t\t\t\t|7. Check the input data for the book.|\n");
    printf("\t\t\t\t\t|-------------------------------------|\n");
  	printf("\t\t\t\t\t|8. Exit.%29s|\n"," ");
	printf("\t\t\t\t\t+*************************************+\n");
};
//in danh sach sach
 void printListBook() {
  	FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");
    struct Book book;
    printf("\n\n\t\t\t\t+******************************************************+\n");
    printf("\t\t\t\t|BookID%2s|Title%7s|Author%6s|Quantity%2s|Price%3s|\n"," "," "," "," "," ");
    printf("\t\t\t\t+------------------------------------------------------+\n");
    while (fscanf(f, "%s %s %s %d %f", book.bookID, book.title, book.author, &book.quantity, &book.price) == 5) {
        
        printf("\t\t\t\t|%-8s|%-12s|%-12s|%-10d|%-8.2f|\n", book.bookID, book.title, book.author, book.quantity, book.price);
    }
    printf("\t\t\t\t+******************************************************+\n\n");
    fclose(f);
    
    returnMenu();
}

//them sach
void addBook() {
    struct Book book;
    struct Book books[max_book];
    int i, duplicate, count = 0;

    FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");

    if (f != NULL) { 
        while (fscanf(f, "%s %s %s %d %f", books[count].bookID, books[count].title, books[count].author, &books[count].quantity, &books[count].price) == 5) {
            count++;
        }
        fclose(f);
    }

    f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "a");
    if (f == NULL) {
        printf("\tError opening file.\n");
        return;
    }
	//nhap id
    do {
        duplicate = 0;
        printf("\tEnter the Book ID: ");
        scanf("%s", book.bookID);

        if (strlen(book.bookID) == 0) {
            printf("\tBook ID cannot be empty! Please enter again.\n");
            duplicate = 1;
        }

        for (i = 0; i < count; i++) {
            if (strcmp(books[i].bookID, book.bookID) == 0) {
                printf("\tBook ID already exists! Please try again.\n");
                duplicate = 1;
                break;
            }
        }
    } while (duplicate);
	//nhap ten sach
    do {
        duplicate = 0;
        printf("\tEnter the Title: ");
        scanf(" %s", book.title); 

        if (strlen(book.title) == 0) {
            printf("\tTitle cannot be empty! Please enter again.\n");
            duplicate = 1;
        }

        for (i = 0; i < count; i++) {
            if (strcmp(books[i].title, book.title) == 0) {
                printf("\tBook title already exists! Please try again.\n");
                duplicate = 1;
                break;
            }
        }
    } while (duplicate);
	//nhap tac gia
    printf("\tEnter the Author: ");
    scanf(" %s", book.author);
	//nhap so luong
      do {
        printf("\tEnter the Quantity: ");
        if (scanf("%d", &book.quantity) != 1 || book.quantity <= 0) {
            printf("\tInvalid input! Quantity must be a positive integer. Please enter again.\n");
            while (getchar() != '\n');  
        } else {
            break;
        }
    } while (1);
	//nhap gia sach
    do {
        printf("\tEnter the Price: ");
        if (scanf("%f", &book.price) != 1 || book.price <= 0) {
            printf("\tInvalid input! Price must be a positive number. Please enter again.\n");
            while (getchar() != '\n');  
        } else {
            break;
        }
    } while (1);

    fprintf(f, "%s %s %s %d %.2f\n", book.bookID, book.title, book.author, book.quantity, book.price);
    fclose(f);

    printf("\tBook added successfully!\n");
    returnMenu();
}

void editBook() {
    FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");
    if (f == NULL) {
        printf("\tError opening file.\n");
        return;
    }

    struct Book books[max_book];
    int count = 0;
    
    while (fscanf(f, "%s %s %s %d %f", books[count].bookID, books[count].title, books[count].author, &books[count].quantity, &books[count].price) == 5) {
        count++;
    }
    fclose(f);

    char editBookID[10];
    int found = 0;

    printf("\tEnter the book ID you want to edit: ");
    scanf("%s", editBookID);

    int i, duplicate;
    for (i = 0; i < count; i++) {
        if (strcmp(books[i].bookID, editBookID) == 0) {
            found=1;
            printf("\n\tCurrent book information:\n");
            printf("\tID: %s\n", books[i].bookID);
            printf("\tTitle: %s\n", books[i].title);
            printf("\tAuthor: %s\n", books[i].author);
            printf("\tQuantity: %d\n", books[i].quantity);
            printf("\tPrice: %.2f\n", books[i].price);
    	}
    }
//nhap ten sach
    		do {
        		duplicate = 0;
            	printf("\n\tEnter a new title: ");
        		scanf("%s", books[i].title); 
        		if (strlen(books[i].title) == 0) {
        	  	  	printf("\tTitle cannot be empty! Please enter again.\n");
        	    	duplicate = 1;
        		}
				int j;
        		for (j = 0; j < count; j++) {
        	 	   	if (strcmp(books[j].title, books[i].title) == 0) {
        	       		printf("\tBook title already exists! Please try again.\n");
        	        	duplicate = 1;
        	        	break;
        	    	}
        		}
    		} while (duplicate);
//nhap tac gia
   			printf("\tEnter new author: ");
    		scanf("%s", books[i].author);
//nhap so luong
      		do {
       			printf("\tEnter the new quantity: ");
       			scanf("%d", &books[i].quantity);
        		if (books[i].quantity != 1 || books[i].quantity <= 0) {
            		printf("\tInvalid input! Quantity must be a positive integer. Please enter again.\n");
            		while (getchar() != '\n');  
        		}else{
            		break;
        		}
    		} while (1);
//nhap gia sach
    		do {
        		printf("\tEnter new price: ");
        		scanf("%f", &books[i].price);
        		if (books[i].price != 1 || books[i].price <= 0) {
            		printf("\tInvalid input! Price must be a positive number. Please enter again.\n");
            		while (getchar() != '\n');  
        		}else{
            		break;
        		}
    		} while (1);
            printf("\n\tThe book information has been successfully edited.\n");
    if (!found) {
        printf("\tNo books found with ID %s.\n", editBookID);
        returnMenu();
    }
    f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "w");
    if (f == NULL) {
        printf("\tError opening file to save changes.\n");
        return;
    }
    for (i = 0; i < count; i++) {
        fprintf(f, "%s %s %s %d %.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }
    fclose(f);
    
	returnMenu();
}

//xoa sách theo id
void deleteBook(){
	FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");
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

    if (count == 0) {
        printf("\tNo books available to delete.\n");
        return;
    }

    char deleteID[10];
    int found;

        found = -1; 
        printf("\tEnter the book ID you want to delete: ");
        scanf("%s", deleteID);

        int i;
        for (i = 0; i < count; i++) {
            if (strcmp(books[i].bookID, deleteID) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("\tNo book found with ID %s.\n", deleteID);
            returnMenu();
        }

    printf("\n\tBook found: \n");
    printf("\tID: %s\n", books[found].bookID);
    printf("\tTitle: %s\n", books[found].title);
    printf("\tAuthor: %s\n", books[found].author);
    printf("\tQuantity: %d\n", books[found].quantity);
    printf("\tPrice: %.2f\n", books[found].price);
    char confirm;
    printf("\n\tAre you sure you want to delete this book? (y/n): ");
    scanf(" %c", &confirm);

    if (confirm != 'y' && confirm != 'Y') {
        printf("\tDeletion canceled.\n");
        returnMenu();
    }

    f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "w");
    if (f == NULL) {
        printf("\tError opening file to save changes.\n");
        return;
    }
    
    for (i = 0; i < count; i++) {
        if (i != found) { 
            fprintf(f, "%s %s %s %d %.2f\n", books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
        }
    }
    fclose(f);
    printf("\n\tBook with ID %s has been successfully deleted.\n", deleteID);
    returnMenu();
}

//xap sep danh sach sach
void arrangeBook() {
    struct Book books[max_book];  
    int i, j, choice;
    do {
    	int count = 0;
    	FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");
    	
    	if (f == NULL) {
        	printf("\tError opening file.\n");
        	return;
    	}
    	
    	while (fscanf(f, "%s %s %s %d %f", books[count].bookID, books[count].title, books[count].author, &books[count].quantity, &books[count].price) == 5) {
        count++;
    	}
    	fclose(f);
    	
    	if (count == 0) {
        	printf("\tNo books available to sort.\n");
        	return;
    	}
    	//Menu con
        printf("\n\t\t\t\t\t******** SORT BOOKS MENU ********\n");
        printf("\t\t\t\t\t|1. Arrange in ascending order%2s|\n"," ");
    	printf("\t\t\t\t\t|-------------------------------|\n");
        printf("\t\t\t\t\t|2. Arrange in descending order%s|\n"," ");
    	printf("\t\t\t\t\t|-------------------------------|\n");
        printf("\t\t\t\t\t|3. Return to Main Menu%9s|"," ");
        printf("\n\t\t\t\t\t*********************************\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            runMenu();
        }

        if (choice < 1 || choice > 3) {
            printf("\tInvalid Input! Please enter 1, 2, or 3.\n");
            continue;
        }

        for (i = 0; i < count - 1; i++) {
            for (j = 0; j < count - i - 1; j++) {
                if ((choice == 1 && books[j].price > books[j + 1].price) ||
                    (choice == 2 && books[j].price < books[j + 1].price)) {
                    struct Book temp = books[j];
    						books[j] = books[j + 1];
    						books[j + 1] = temp;
                }
            }
        }
        printf("\tBooks sorted successfully!\n");
        
        f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "w");
    	if (f == NULL) {
        	printf("\tError opening file to save sorted books.\n");
        	return;
    	}

    	for (i = 0; i < count; i++) {
        	fprintf(f, "%s %s %s %d %.2f\n", 
			books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    	}
    	fclose(f);

    	printf("\n\t\t\t\t\tSorted book list:\n");
    	printf("\t\t\t\t\t+******************************************************+\n");
    	printf("\t\t\t\t\t|BookID%2s|Title%7s|Author%6s|Quantity%2s|Price%3s|\n"," "," "," "," "," ");
    	printf("\t\t\t\t\t+------------------------------------------------------+\n");
    	for (i = 0; i < count; i++) {
        	printf("\t\t\t\t\t|%-8s|%-12s|%-12s|%-10d|%-8.2f|\n", 
			books[i].bookID, books[i].title, books[i].author, books[i].quantity, books[i].price);
    	}
    	printf("\t\t\t\t\t+******************************************************+\n\n");
    } while (1);

    
}
//tim sach theo ten
void searchBook(){
	FILE *f = fopen("C:\\Users\\Admin\\Documents\\HCM_KS24A_HOQUOCKHAI_03\\booklistdata.txt", "r");
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

    if (count == 0) {
        printf("\tNo books available.\n");
        return;
    }

    char searchName[50];  
	int found = 0, arrFound[count], i, flag = 0;  

	printf("\tEnter the title of the book you want to search for: ");
	scanf(" %s", searchName);  

	for (i = 0; i < count; i++) {
    	if (strstr(books[i].title, searchName) != NULL) {  
        	arrFound[flag] = i;  
       		flag++;
        	found = 1;
    	}
	}
    
	if (found) {
    printf("\t\t\t\t+**********************BOOKS FOUND*********************+\n");
    printf("\t\t\t\t|BookID%2s|Title%7s|Author%6s|Quantity%2s|Price%3s|\n"," "," "," "," "," ");
    printf("\t\t\t\t+------------------------------------------------------+\n");
    for (i = 0; i < flag; i++) {
    	int index = arrFound[i];
        printf("\t\t\t\t|%-8s|%-12s|%-12s|%-10d|%-8.2f|\n", 
        books[index].bookID, books[index].title, books[index].author, books[index].quantity, books[index].price);
    }
    printf("\t\t\t\t+******************************************************+\n\n");
	}else {
    	printf("\tNo books found matching your search.\n");
	}
    returnMenu();
}
