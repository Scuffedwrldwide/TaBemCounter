#include <stdio.h>
#include <stdlib.h>

#define KEYWORD1 "Tá bem?"
#define CHAR1 't'

#define KEYWORD2 "Ok?"
#define CHAR2 'o'

#define KEYWORD3 "Certo?"
#define CHAR3 'c'

#define KEYWORD4 "Não é?"
#define CHAR4 'n'

#define TITLE "TÁ BEM TIME\n"
#define WIDTH 20

int input();
void separator(char separator, int length);
void fileWrite(FILE *table, int C1, int C2, int C3, int C4, int total);

int main()
{
    FILE *table;
    table = fopen("table.txt", "a");
    printf(TITLE);
    separator('=', WIDTH);
    while (input(&table) != 1)
    {
        /*recieve input*/
    }
}

void separator(char separator, int length)
{
    int i;
    for (i = 0; i < length; i++)
        putchar(separator);
    putchar('\n');
}

int input(FILE *table)
{
    int C1 = 0, C2 = 0, C3 = 0, C4 = 0, total = 0;
    char c;

    for (c = getchar(); c != 'q' && c != 'Q' && c != EOF;){
        /*convert to lowercase*/
        if (c > 'A' && c < 'Z')
            c += 'a' - 'A';

        switch (c){
        case CHAR1:
            total++;
            C1++;
            break;
        case CHAR2:
            total++;
            C2++;
            break;
        case CHAR3:
            total++;
            C3++;
            break;
        
        case CHAR4:
            total++;
            C4++;
            break;
        /*
        case CHAR5:
            C5++;
            break;
        */
        default:
            break;
        }
        c = getchar();
    }
    separator('=', WIDTH);
    printf("%-10s\t%4d\n", KEYWORD1, C1);
    printf("%-10s\t%4d\n", KEYWORD2, C2);
    printf("%-10s\t%4d\n", KEYWORD3, C3);
    printf("%-10s\t%4d\n", KEYWORD4, C4);
/*  printf("%s: %d\n", KEYWORD4, C4); */
    separator('=', WIDTH);
    printf("Total: %d\n", total);
    fileWrite(table, C1, C2, C3, C4, total);
    return 1;
}

void fileWrite(FILE *table, int C1, int C2, int C3, int C4, int total)
{

    fprintf(table, "====================\n");
    fprintf(table, "%-10s\t%4d\n", KEYWORD1, C1);
    fprintf(table, "%-10s\t%4d\n", KEYWORD2, C2);
    fprintf(table, "%-10s\t%4d\n", KEYWORD3, C3);
    fprintf(table, "%-10s\t%4d\n", KEYWORD4, C4);
    fprintf(table, "Total: %d\n", total);
    fprintf(table, "====================\n");
/*  printf("%s: %d\n", KEYWORD4, C4); */
    
}
