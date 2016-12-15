#include <iostream.h>
#include <string.h>
#include "LineClass.h"
#include "PageClass.h"

Page::Page(char *const pLines)
{
    char *pLineStart = pLines;
    unsigned short usCounter = 0;
    unsigned short usLinesNum;

    m_pLines = 0;
    usLinesNum = 0;

    if (pLines)
    {
        char *TmpStr = pLines;

        /* Counting the Lines Number. */
        while (*pLineStart != '\0')
        {
            if (*pLineStart == '\n')
            {
                usLinesNum++;
                *pLineStart = '\0';
            }
            pLineStart++;
        }
        usLinesNum++; //Last Line Ended With '\0' (not '\t')

        /* Allocat the Place for the Lines. */
        m_pLines = new Line[usLinesNum];
        for (; usCounter < usLinesNum; usCounter++)
        {
            pLineStart = new char[strlen(TmpStr) + 1];
            strcpy(pLineStart, TmpStr);

            /* Set Each Line to Its Object. */
            /* Each Line Object will Use Word Functions to Set the Words in the Line. */
            m_pLines[usCounter].SetLine(pLineStart);
            delete[] pLineStart;
            TmpStr += strlen(TmpStr) + 1;
        }
    }
}

/* Printing the Page, Using Lines' Print Function. */
void Page::PrintData()
{
    unsigned short usCounter = 0;

    for (; usCounter < usLinesNum; usCounter++)
    {
        m_pLines[usCounter].PrintData();
    }
}
