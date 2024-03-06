//
// Created b    y kekekuli on 2022/2/12.
//
#include "BookSystem.h"
Book *  books[N];
int     size;

void    init(){

}
void    NotFindError(){
    printf("This is not find.\n");
}
void    AddBook(){
    Book * book = malloc(sizeof (Book));
    //int len = 0;
    char * buffer = (char *) malloc(BUFFER_SIZE + 1);
    fflush(stdin);
    printf("Enter the isbn (only nums and '-' are allowed) :");
    while(1 != CheckIsbn(gets(buffer))){
        printf("Error input.\nInput again :");
    }
    book -> isbn = (char *) malloc(strlen(buffer) + 1);
    strcpy(book -> isbn, buffer);

    printf("Enter the book name :");
    gets(buffer);
    book -> name = (char *) malloc(strlen(buffer) + 1);
    strcpy(book -> name, buffer);

    printf("Enter the autor name :");
    gets(buffer);
    book -> autor = (char *) malloc(strlen(buffer) + 1);
    strcpy(book -> autor, buffer);

    printf("Enter the studio name :");
    gets(buffer);
    book -> studio = (char *) malloc(strlen(buffer) + 1);
    strcpy(book -> studio, buffer);

    printf("Enter the book price : ");
    scanf("%d", &(book -> price));

    int t = FindBookByIsbn(book -> isbn);
    if (t > 0 && t <= size){
        printf("This book is existing.\n");
        DeleBookBuffer(book);
    }
    else{
        //StoreBookFile(book);
        books[++size] = book;
    }
    free(buffer);
}
int     CheckIsbn(const char * isbn){
    if (isbn == NULL)
        return 0;

    int len = (int)strlen(isbn);
    for (int i = 0; i < len; i++){
        if (!((isbn[i] == '-') || (isbn[i] <= '9' && isbn[i] >= '0')))
            return 0;
    }
    return 1;
}
void    DeleBookBuffer(Book * book){
    if (book == NULL)
        return;
    free(book -> isbn);
    free(book -> name);
    free(book -> autor);
    free(book -> studio);

    free(book);
}
int     FindBookByIsbn(const char * isbn){
    if (isbn == NULL)
        return -1;

    int t = size;
    while(t > 0 && strcmp(isbn, books[t] -> isbn) != 0)
        t--;
    return t;
}
int     FindBookByName(const char * name){
    if (name == NULL)
        return -1;

    int t = size;
    while(t > 0 && strcmp(name, books[t] -> name) != 0)
        t--;
    return t;
}
void    StoreBookFile(Book * book){
}
void    DeleBookByIsbn(const char * isbn){
    int t = FindBookByIsbn(isbn);
    if (t > 0 && t <= size){
        DeleBookBuffer(books[t]);
        for (int i = t; i < size; i++){
            books[i] = books[i + 1];
        }
        size--;
    }
    else NotFindError();
}
void    DeleBookByName(const char * name){
    int t = FindBookByName(name);
    if (t > 0 && t <= size){
        DeleBookBuffer(books[t]);
        for (int i = t; i < size; i++){
            books[i] = books[i + 1];
        }
        size--;
    }
    else NotFindError();
}
void    DeleAllBooks(){
    for (int i = size; i >= 1; i--){
        DeleBookBuffer(books[i]);
    }
    size = 0;
}
void    AlterByIsbn(const char * isbn){
    char * str = (char *) malloc(BUFFER_SIZE);
    int t = FindBookByIsbn(isbn);
    if (t > 0 && t <= size){
        int op = 0;
        printf("1.name\t2.autor\n3.studio\t4.price\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Enter name :");
                fflush(stdin);gets(str);
                strcpy(books[t] -> name, str);
                break;
            case 2:
                printf("Enter autor :");

                fflush(stdin);gets(str);
                strcpy(books[t] -> autor, str);
                break;
            case 3:
                printf("Enter studio :");

                fflush(stdin);gets(str);
                strcpy(books[t] -> studio, str);
                break;
            case 4:
                printf("Enter price :");

                scanf("%d", &(books[t] -> price));
                break;
            default:break;
        }
    }
    else NotFindError();
    free(str);
}
int     GetNumsByStudio(const char * studio){
    if (studio == NULL)
        return 0;
    int ans = 0;
    for (int i = 1; i <= size; i++)
        if (strcmp(books[i] -> studio, studio) == 0)
            ans++;
    return ans;
}
int     GetNumsByAutor(const char * autor){
    if (autor == NULL)
        return 0;

    int ans = 0;
    for (int i = 1; i <= size; i++)
        if (strcmp(books[i] -> autor, autor) == 0)
            ans++;
    return ans;
}
void    QueryByIsbn(const char * isbn){
    int t = FindBookByIsbn(isbn);
    if (t > 0 && t <= size)
        ShowDetail(books[t]);
    else NotFindError();
}
void    QueryByName(const char * name){
    int t = FindBookByName(name);
    if (t > 0 && t <= size)
        ShowDetail(books[t]);
    else NotFindError();
}
void    ShowDetail(Book * book){
    if (book == NULL)
        return;
    printf("Book name :\t%s\n", book -> name);
    printf("Book isbn :\t%s\n", book -> isbn);
    printf("Book autor :\t%s\n", book -> autor);
    printf("Book studio :\t%s\n", book -> studio);
    printf("Book price :\t%d\n", book -> price);
}
void    ShowAllTheBookByStudio(const char * studio){
    quick_sort(1, size);
    for (int i = 1; i <= size; i++){
        if (strcmp(books[i] -> studio, studio) == 0)
            ShowDetail(books[i]);
    }
}
void    quick_sort(int l, int r){
    if (l >= r)
        return;

    int i = l - 1, j = r + 1;
    Book * mid = books[(l + r) / 2];
    while(i < j){
        do i++; while (books[i] -> price < mid -> price);
        do j--; while (books[j] -> price > mid -> price);
        if (i < j){
            Book * tmp = books[i];
            books[i] = books[j];
            books[j] = tmp;
        }
    }

    quick_sort(l, j);
    quick_sort(j + 1, r);
}
void    ShowAllBooks(){
    printf("This is %d books\n", size);
    for (int i = 1; i <= size; i++){
        printf("The %dth book\n", i);
        ShowDetail(books[i]);
    }

}
