#include <stdio.h>
#include "BookSystem.h"
int main() {
    setbuf(stdout, NULL);
    init();
    int flag = 1, op, op2;
    char * str = (char *) malloc(BUFFER_SIZE);
    while(flag){

        printf("1.Add\t2.Query\n"
               "3.Alter\t4.Delete\n"
               "5.count\t6.quit\n"
               "7.Show all books detail\n");
        scanf("%d", &op);
        switch (op) {
            case 1:
                AddBook();
                continue;
            case 2:
                printf("1.Query by name\t2.Query by isbn\n");
                scanf("%d", &op2);
                if (op2 == 1){
                    printf("Enter name :");
                    fflush(stdin);gets(str);
                    QueryByName(str);
                }
                else if (op2 == 2){
                    printf("Enter isbn :");
                    fflush(stdin);gets(str);
                    QueryByIsbn(str);
                }
                continue;
            case 3:
                printf("Enter the book isbn you want to alter.\n");
                fflush(stdin);gets(str);
                AlterByIsbn(str);
                continue;
            case 4:
                printf("1.Delete book by name\t2.Delete book by isbn\n");
                scanf("%d", &op2);
                if (op2 == 1){
                    printf("Enter name :");
                    fflush(stdin);gets(str);
                    DeleBookByName(str);
                }
                else if (op2 == 2){
                    printf("Enter isbn :");
                    fflush(stdin);gets(str);
                    DeleBookByIsbn(str);
                }
                continue;
            case 5:
                printf("1.Count by autor\t2.Count by studio\n3.Count a studio all books\n");
                scanf("%d", &op2);
                if (op2 == 1){
                    printf("Enter name :");
                    fflush(stdin);gets(str);
                    printf("%s released %d book(s)\n", str, GetNumsByAutor(str));
                }
                else if (op2 == 2){
                    printf("Enter studio :");
                    fflush(stdin);gets(str);
                    printf("%s released %d book(s)\n", str, GetNumsByStudio(str));
                }
                else if (op2 == 3){
                    printf("Enter studio :");
                    fflush(stdin);gets(str);
                    ShowAllTheBookByStudio(str);
                }

                continue;
            case 6:flag = 0;continue;
            case 7:
                ShowAllBooks();
                continue;
            default:continue;
        }

        if (flag)
            break;
    }

    free(str);
    return 0;
}
