#include <iostream.h>
#include <string.h>
#include "WordClass.h"
#include "LineClass.h"

Line::Line(char *const pWords)
{
    m_pWords = 0;
    SetLine(pWords);
}

void Line::SetLine(char *const pWords)
{
    char *pWordStart = pWords;
    unsigned short usCounter = 0;
    unsigned short usLinesNum;

    if (m_pWords)
    {
        delete[] m_pWords;
    }

    usLinesNum = 0;

    if (pWords)
    {
        unsigned short usLineLength = strlen(pWords);

        /* Counting the Words Number. */
        while (*pWordStart != '\0')
        {
            if (*pWordStart == '\t')
            {
                usLinesNum++;
                *pWordStart = '\0';
            }
            pWordStart++;
        }
        usLinesNum++; //Last Word Ended With '\0' (not '\t')

        /* Allocat the Place for the Words. */
        m_pWords = new Word[usLinesNum];
        pWordStart = pWords;
        for (; usCounter < usLinesNum; usCounter++)
        {
            /* Set Each Word to Its Object. */
            m_pWords[usCounter].SetWord(pWordStart);
            pWordStart += strlen(pWordStart) + 1;
        }
    }
}

/* Printing the Line, Using Words' Print Function. */
void Line::PrintData()
{
    unsigned short usCounter = 0;

    for (; usCounter < usLinesNum; usCounter++)
    {
        m_pWords[usCounter].PrintData();
        if (usCounter + 1 < usLinesNum)
        {
            cout << " ";
        }
    }
    cout << endl;
}
