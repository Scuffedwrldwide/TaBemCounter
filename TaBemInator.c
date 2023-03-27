#include <stdio.h>
#include <stdlib.h>

#define KEYWORD1 "Tá bem?"
#define CHAR1 't'
#define C1 counter[0]

#define KEYWORD2 "Ok?"
#define CHAR2 'o'
#define C2 counter[1]

#define KEYWORD3 "Certo?"
#define CHAR3 'c'
#define C3 counter[2]

#define KEYWORD4 "Não é?"
#define CHAR4 'n'
#define C4 counter[3]

#define KEYWORD5 "Epá!"
#define CHAR5 'e'
#define C5 counter[4]

#define KEYWORD6 "Sasha vôr!"
#define CHAR6 's'
#define C6 counter[5]

#define TITLE "TÁ BEM TIME\n"
#define WIDTH 20

int input();
void separator(char separator, int length);
void fileWrite(int counter[], int total);

int main()
{
    int total, counter[6] = {0, 0, 0, 0, 0, 0};

    printf(TITLE);
    separator('=', WIDTH);
    while (input(counter) != 1)
    {
        /*recieve input*/
    }
    total = C1 + C2 + C3 + C4 + C5;
    separator('=', WIDTH);
    printf("%-10s\t%4d\n", KEYWORD1, C1);
    printf("%-10s\t%4d\n", KEYWORD2, C2);
    printf("%-10s\t%4d\n", KEYWORD3, C3);
    printf("%-10s\t%4d\n", KEYWORD4, C4);
    printf("%-10s\t%4d\n", KEYWORD5, C5);
    printf("%-10s\t%4d\n", KEYWORD6, C6);
    separator('=', WIDTH);
    printf("Total: %d\n", total);
    fileWrite(counter, total);

    return 0;
}

void separator(char separator, int length)
{
    int i;
    for (i = 0; i < length; i++)
        putchar(separator);
    putchar('\n');
    
}

int input(int counter[])
{
    
    char c;

    for (c = getchar(); c != 'q' && c != 'Q' && c != EOF;){
        /*convert to lowercase*/
        if (c > 'A' && c < 'Z')
            c += 'a' - 'A';

        switch (c){
        case CHAR1:
            C1++;
            break;
        case CHAR2:
            C2++;
            break;
        case CHAR3:
            C3++;
            break;
        
        case CHAR4:
            C4++;
            break;
        
        case CHAR5:
            C5++;
            break;

        case CHAR6:
            C6++;
            break;
        
        default:
            break;
        }
        c = getchar();
    }
    return 1;
}

void fileWrite(int counter[], int total)
{
    FILE *table;
    table = fopen("table.txt", "w");

    fprintf(table, "====================\n");
    fprintf(table, "%-10s\t%4d\n", KEYWORD1, C1);
    fprintf(table, "%-10s\t%4d\n", KEYWORD2, C2);
    fprintf(table, "%-10s\t%4d\n", KEYWORD3, C3);
    fprintf(table, "%-10s\t%4d\n", KEYWORD4, C4);
    fprintf(table, "%-10s\t%4d\n", KEYWORD5, C5);
    fprintf(table, "%-10s\t%4d\n", KEYWORD6, C6);
    fprintf(table, "Total: %d\n", total);
    fprintf(table, "====================\n");
    fclose(table);
    
    puts("\nEpá, já me corrias outra vez, não é? Sasha vor. Ok? Certo.");
}
