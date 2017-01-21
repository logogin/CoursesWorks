#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
void structer(char *, FILE *, char **);
int def(char *);
void check(FILE *, char **);
int integer(char *);
int character(char *);
int floater(char *);
int longer(char *);
int doubler(char *);
int scopes(char *);
void Define(char *);

int SInt = 0, SChar = 0, SFloat = 0, SDouble = 0, SLong = 0, SStruct = 0; //

char cDef[10][10];
int iDef[10] = {NULL};
int Define_cntr = 0;

char StructName[5][10];
int StructSize[5] = {NULL};
int StructCounter = 0;
/////////////////////////////////
void main(void)
{
    clrscr();
    FILE *fptr;
    char pFilename[50] = {"a:\\ex.c"};
    //                0      1      2       3        4      5        6
    char *str[MAX] = {"int", "char", "float", "double", "long", "struct", "#define"};
    if ((fptr = fopen(pFilename, "r")) == NULL)
    {
        printf("\aCan't open file!");
        exit(1);
    }
    check(fptr, str);
    fclose(fptr);
}
///////////////////////////////////////////////////////////////////////////
void check(FILE *fptr, char **str)
{
    char word[20] = {NULL};
    int count = 0;
    char row[90];
    do
    {
        fgets(row, 80, fptr);
        row[strlen(row) - 1] = ' ';
        row[strlen(row)] = ';';
        sscanf(row, "%s", word);
        for (count = 0; count < MAX; count++)
        {
            if (!strcmpi(word, str[count]))
            {
                switch (count)
                {
                case 0:
                {
                    SInt += integer(row);
                    break;
                }
                case 1:
                {
                    SChar += character(row);
                    break;
                }
                case 2:
                {
                    SFloat += floater(row);
                    break;
                }
                case 3:
                {
                    SDouble += doubler(row);
                    break;
                }
                case 4:
                {
                    SLong += longer(row);
                    break;
                }
                case 5:
                {
                    structer(row, fptr, str);
                    break;
                }
                case 6:
                {
                    Define(row);
                    break;
                }
                default:
                {
                    printf("\a_ERROR!");
                    return;
                }
                }
            }
        }
    } while (!feof(fptr));
    printf("\n\t\t\tInteger    =    %d\n", SInt);
    printf("\t\t\tChar         =    %d\n", SChar);
    printf("\t\t\tFloat        =    %d\n", SFloat);
    printf("\t\t\tDouble       =    %d\n", SDouble);
    printf("\t\t\tLong         =    %d\n", SLong);
    printf("\t\t\tStructers    =    %d\n", SStruct);
    printf("\n\t\t\t*******************\n");
    printf("\t\t\tAll        =    %d\n", SInt + SChar + SFloat + SDouble + SLong + SStruct);
    getch();
}
////////////////////////////INT///////////////////////////
int integer(char *row)
{
    char word[20] = {NULL};
    int sum = 0;
    while (!isalpha(*row))
        row++;
    row = row + 4;
    do
    {
        sscanf(row, "%s", word);
        sum += 2 * scopes(word);
        row += strlen(word) + 1;
    } while (*row != '\n' && *row != ';');
    return sum;
}
//////////////////////////////char/////////////////////////////
int character(char *row)
{
    char word[20] = {NULL};
    int sum = 0;
    while (!isalpha(*row))
        row++;
    row = row + 5;
    do
    {
        sscanf(row, "%s", word);
        sum += 1 * scopes(word);
        row += strlen(word) + 1;
    } while (*row != '\n' && *row != ';');
    return sum;
}
///////////////////////float//////////////////////
int floater(char *row)
{
    char word[20] = {NULL};
    int sum = 0;
    while (!isalpha(*row))
        row++;
    row = row + 6;
    do
    {
        sscanf(row, "%s", word);
        sum += 4 * scopes(word);
        row += strlen(word) + 1;
    } while (*row != '\n' && *row != ';');
    return sum;
}
////////////////////////////////////////////////
int longer(char *row)
{
    char word[20] = {NULL};
    int sum = 0;
    while (!isalpha(*row))
        row++;
    row = row + 5;
    do
    {
        sscanf(row, "%s", word);
        sum += 4 * scopes(word);
        row += strlen(word) + 1;
    } while (*row != '\n' && *row != ';');
    return sum;
}
////////////////////////////////DOUBLE/////////////////////////////////////
int doubler(char *row)
{
    char word[20] = {NULL};
    int sum = 0;

    while (!isalpha(*row))
        row++;
    row = row + 7;
    do
    {
        sscanf(row, "%s", word);
        sum += 8 * scopes(word);
        row += strlen(word) + 1;
    } while (*row != '\n' && *row != ';');
    return sum;
}
////////////////////////////////SCOPE///////////////////////////////
int scopes(char *word)
{
    char DEF_NAME[10] = {NULL};
    int num = 1, Dcounter = 0, counter = 0;
    while (*word != '\0' && *word != ';' && *word != ',')
    {
        if (*word == '[')
        {
            word++;

            if (isalpha(*word))
            {
                while (*word != ']')
                {
                    DEF_NAME[Dcounter] = (*word);
                    word++;
                    Dcounter++;
                }
                DEF_NAME[Dcounter] = '\0';
                for (counter = 0; counter < MAX; counter++)
                {
                    if (!strcmpi(DEF_NAME, cDef[counter]))
                    {
                        switch (counter)
                        {
                        case 0:
                        {
                            num *= iDef[counter];
                            word++;
                            break;
                        }
                        case 1:
                        {
                            num *= iDef[counter];
                            word++;
                            break;
                        }
                        case 2:
                        {
                            num *= iDef[counter];
                            word++;
                            break;
                        }
                        case 3:
                        {
                            num *= iDef[counter];
                            word++;
                            break;
                        }
                        case 4:
                        {
                            num *= iDef[counter];
                            word++;
                            break;
                        }
                        default:
                        {
                            printf("\a__ERROR!");
                            return 0;
                        }
                        }
                        if (*word != '[')
                            return num;
                        if (*word == '[')
                        {

                            word++;
                            if (!isalpha(*word))
                            {
                                num *= atoi(word);
                                while (*word != ']')
                                    word++;
                                if (*(++word) == '[')
                                {
                                    num *= atoi(++word);
                                }
                                return num;
                            }

                            if (isalpha(*word))
                            {
                                Dcounter = 0;
                                while (*word != ']')
                                {
                                    DEF_NAME[Dcounter] = (*word);
                                    word++;
                                    Dcounter++;
                                }
                                DEF_NAME[Dcounter] = '\0';
                                for (counter = 0; counter < MAX; counter++)
                                {
                                    if (!strcmpi(DEF_NAME, cDef[counter]))
                                    {
                                        switch (counter)
                                        {
                                        case 0:
                                        {
                                            num *= iDef[counter];
                                            word++;
                                            return num;
                                        }
                                        case 1:
                                        {
                                            num *= iDef[counter];
                                            word++;
                                            return num;
                                        }
                                        case 2:
                                        {
                                            num *= iDef[counter];
                                            word++;
                                            return num;
                                        }
                                        case 3:
                                        {
                                            num *= iDef[counter];
                                            word++;
                                            return num;
                                        }
                                        case 4:
                                        {
                                            num *= iDef[counter];
                                            word++;
                                            return num;
                                        }
                                        default:
                                        {
                                            printf("\a__ERROR!");
                                            return 0;
                                        }
                                        }
                                    }
                                }
                            }
                        } //
                    }
                } //
            }     //

            if (!isalpha(*word))
            {
                num *= atoi(word);
                while (*word != ']')
                    word++;
                if (*(++word) == '[')
                {
                    word++;
                    if (isalpha(*word))
                    {
                        while (*word != ']')
                        {
                            DEF_NAME[Dcounter] = (*word);
                            word++;
                            Dcounter++;
                        }
                        DEF_NAME[Dcounter] = '\0';
                        for (counter = 0; counter < MAX; counter++)
                        {
                            if (!strcmpi(DEF_NAME, cDef[counter]))
                            {
                                switch (counter)
                                {
                                case 0:
                                {
                                    num *= iDef[counter];
                                    word++;
                                    return num;
                                }
                                case 1:
                                {
                                    num *= iDef[counter];
                                    word++;
                                    return num;
                                }
                                case 2:
                                {
                                    num *= iDef[counter];
                                    word++;
                                    return num;
                                }
                                case 3:
                                {
                                    num *= iDef[counter];
                                    word++;
                                    return num;
                                }
                                case 4:
                                {
                                    num *= iDef[counter];
                                    word++;
                                    return num;
                                }
                                default:
                                {
                                    printf("\a__ERROR!");
                                    return 0;
                                }
                                }
                            }
                        } //
                    }     //
                    if (!isalpha(*word))
                    {
                        num *= atoi(word);
                    }
                }
            }
        }
        word++;
    }
    return num;
}
///////////////////////////////////DEFINE/////////////////////////
void Define(char *row)
{
    char word[20] = {NULL};
    while (!isalpha(*row))
        row++;
    row = row + 7;
    sscanf(row, "%s", word);
    strcpy(cDef[Define_cntr], word);
    row += strlen(word) + 1;
    sscanf(row, "%s", word);
    iDef[Define_cntr] = atoi(word);
    Define_cntr++;
    return;
}
////////////////////////////STRUCTERS/////////////////////////////////
void structer(char *row, FILE *fptr, char **str)
{
    int size_of_struct = 0, counter = 0, flag = 0;
    char word[20] = {NULL}, strName[15] = {NULL};
    while (!isalpha(*row))
        row++;
    row = row + 7;
    sscanf(row, "%s", word);
    strcpy(strName, word);
    for (counter = 0; counter < StructCounter; counter++)
    {
        if (!strcmpi(word, StructName[counter]))
        {
            row += strlen(word) + 1;
            sscanf(row, "%s", word);
            SStruct += StructSize[counter] * scopes(word);
            flag = 1;
        }
        if (flag == 0)
        {
            do
            {
                fgets(row, 80, fptr);
                row[strlen(row) - 1] = ' ';
                row[strlen(row)] = ';';
                sscanf(row, "%s", word);
                for (counter = 0; counter < MAX; counter++)
                {
                    if (!strcmpi(word, str[counter]))
                    {
                        switch (counter)
                        {
                        case 0:
                        {
                            size_of_struct += integer(row);
                            break;
                        }
                        case 1:
                        {
                            size_of_struct += character(row);
                            break;
                        }
                        case 2:
                        {
                            size_of_struct += floater(row);
                            break;
                        }
                        case 3:
                        {
                            size_of_struct += doubler(row);
                            break;
                        }
                        case 4:
                        {
                            size_of_struct += longer(row);
                            break;
                        }
                        case 5:
                        {
                            structer(row, fptr, str);
                            break;
                        }
                        case 6:
                        {
                            Define(row);
                            break;
                        }
                        default:
                        {
                            printf("\a_ERROR!");
                            return;
                        }
                        }
                    }
                }
            } while (*row != '\n' && *row != ';' && *row != '}');
            strcpy(StructName[StructCounter], strName);
            StructSize[StructCounter] = size_of_struct;
            StructCounter++;
        }
    }
    return;
}
