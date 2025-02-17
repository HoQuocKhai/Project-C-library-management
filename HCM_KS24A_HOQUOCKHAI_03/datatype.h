#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define max_book 100

//date
struct Date {
  int month,day,year;
};

//book
struct Book {
  char bookID[10];// id sach
  char title[30];// tieu de
  char author[20];// tac gia
  int quantity;// so luong
  float  price;// gia
//  struct Date publication;
};

//member
struct member{
  char memberId[10];
  char name[20];
  char phone[10];
  bool status;
  struct Book BorrowerdBooks[];
};


struct Book book[max_book];
