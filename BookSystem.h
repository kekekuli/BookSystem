//
// Created by kekekuli on 2022/2/11.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <direct.h>
#ifndef BOOKSYSTEM_BOOKSYSTEM_H
#define BOOKSYSTEM_BOOKSYSTEM_H
#define BOOKS_PATH "./books"

#define N 1000
#define BUFFER_SIZE 100
typedef struct Book{
    char *isbn;
    char *name;
    char *autor;
    char *studio;

    int price;
} Book;
extern Book *  books[N];
extern int size;

//tool functions
void    quick_sort(int , int);
int     CheckIsbn(const char *);
int     FindBookByIsbn(const char *);
int     FindBookByName(const char *);
void    init();
void    DeleAllBooks();
void    DeleBookBuffer(Book *);
void    StoreBookFile(Book *);
void    ShowDetail(Book *);
void    NotFindError();
//Major functions
void    AddBook();
void    DeleBookByIsbn(const char *);
void    DeleBookByName(const char *);
void    AlterByIsbn(const char *);
int     GetNumsByStudio(const char *);
int     GetNumsByAutor(const char *);
void    QueryByIsbn(const char *);
void    QueryByName(const char *);
void    ShowAllTheBookByStudio(const char *);
void    ShowAllBooks();

#endif //BOOKSYSTEM_BOOKSYSTEM_H
