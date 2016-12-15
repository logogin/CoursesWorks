#include <iostream.h>
#include <string.h>
#include "WordClass.h"
#include "LineClass.h"
#include "PageClass.h"

void PrintAll(Word &rW);

int main(void)
{
    char PageLine[50] = {'M', 'y', '\t', 'N',
                         'a', 'm', 'e', '\t', 'i', 's', ':', '\n', 'D',
                         'a', 'n', 'n', 'y', '\n', 'O', 'v', 'a', 'd', 'i', 'a', '\0'};

    Word W("Itsik");
    PrintAll(W);
    cout << endl;

    Line L("My	Name	is	Itsik");
    PrintAll(L);
    cout << endl;

    Page P(PageLine);
    PrintAll(P);
    cout << endl;

    return 0;
}

/* Using Virtual Functions to Print the Data.  */
void PrintAll(Word &rW)
{
    rW.PrintData();
}
