#ifndef __HELPER_H_
#define __HELPER_H_

// Structure for date
typedef struct date{
    int year;
    int month;
    int day;
} date;
// Initializes date
date date_init(int year, int month, int day);

// Structure for book
typedef struct book{
    int id;
    char name[30];
    char author[30];
} book;
// Initializes book
book *book_init(int id, char name[], char author[]);
// Adds book to file
int add_book_to_file(book *book_ptr, char *file_name);

#endif