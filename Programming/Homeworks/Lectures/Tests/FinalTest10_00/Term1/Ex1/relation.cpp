// Exam 1 03.10.2000 - Ex. No. 1
// Relation Class Functions and Operators
#include "relation.h"
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>

// Overloading << for STD Output
ostream &operator<<(ostream &Output, const Relation &refRel)
{
    short sXCount = 0;
    short sYCount;
    bool *pRelation;

    if (refRel.m_ppRelation == 0)
    {
        return (Output << endl);
    }

    pRelation = *(refRel.m_ppRelation);
    for (; sXCount < refRel.m_sXSize; sXCount++)
    {
        for (sYCount = 0; sYCount < refRel.m_sYSize; sYCount++, pRelation++)
        {
            Output << *pRelation
                   << "\t";
        }
        Output << endl;
    }
    return Output;
}

// Overloading << for Output File
ofstream &operator<<(ofstream &FileOutput,
                     const Relation &refRel)
{
    short sXCount = 0;
    short sYCount;
    bool *pRelation;

    if (refRel.m_ppRelation == 0)
    {
        FileOutput << endl;
        return FileOutput;
    }

    pRelation = *(refRel.m_ppRelation);
    for (sXCount; sXCount < refRel.m_sXSize; sXCount++)
    {
        for (sYCount = 0; sYCount < refRel.m_sYSize; sYCount++, pRelation++)
        {
            FileOutput << dec << *pRelation
                       << "\t";
        }
        FileOutput << endl;
    }
    return FileOutput;
}

// Defoult Constructor
Relation::Relation(const short sXSize,
                   const short sYSize,
                   const ppBool ppRelation)
{
    m_ppRelation = 0;
    CopyReletion(sXSize,
                 sYSize,
                 ppRelation);
}

// Copy Constructor
Relation::Relation(const Relation &refRel)
{
    m_ppRelation = 0;
    CopyReletion(refRel.m_sXSize,
                 refRel.m_sYSize,
                 (const ppBool)refRel.m_ppRelation);
}

// Seting New Relation Parameters
Relation &Relation::SetRelation(const Relation &refRelation)
{
    CopyReletion(refRelation.m_sXSize,
                 refRelation.m_sYSize,
                 (const ppBool)refRelation.m_ppRelation);
    return (*this);
}

bool **Relation::GetRelation() const
{
    bool **ppRelation = 0;
    short sCount = 1;
    short sElementsNum;
    bool *pHelp;
    bool *pClassRel;

    if (!m_ppRelation)
    {
        sElementsNum = (short)(m_sYSize * m_sYSize);
        ppRelation = new bool *[m_sXSize];
        pHelp = *m_ppRelation;
        pHelp = new bool[sElementsNum];
        for (; sCount < m_sXSize; sCount++)
        {
            pHelp += m_sXSize;
            ppRelation[sCount] = pHelp;
        }
        pHelp = ppRelation[0];
        pClassRel = m_ppRelation[0];
        for (sCount = 0; sCount < sElementsNum; sCount++,
            pHelp++,
            pClassRel)
        {
            *pHelp = *pClassRel;
        }
    }
    return ppRelation;
}

// Destructor
Relation::~Relation()
{
    EmptyRelation();
}

// Writing the Class in BIN Format
Relation &Relation::Write(const char *strFileName)
{
    ofstream FileOutput(strFileName, ios::app);

    if (m_ppRelation)
    {
        FileOutput.write(reinterpret_cast<const char *>(&m_sXSize),
                         sizeof(short));
        FileOutput.write(reinterpret_cast<const char *>(&m_sYSize),
                         sizeof(short));
        FileOutput.write(reinterpret_cast<const char *>(*m_ppRelation),
                         sizeof(bool) * m_sXSize * m_sYSize);
    }
    return (*this);
}

// Boolean AND= Overloading
Relation &Relation::operator+=(const Relation &refRel)
{
    if (m_sXSize == refRel.m_sXSize &&
        m_sYSize == refRel.m_sYSize &&
        m_ppRelation != 0 &&
        refRel.m_ppRelation != 0)
    {
        short sCount = 0;
        bool *pFirst = *m_ppRelation;
        bool *pSecond = *(refRel.m_ppRelation);
        for (; sCount < m_sXSize * m_sYSize; sCount++,
                                             pFirst++,
                                             pSecond++)
        {
            *pFirst &= *pSecond;
        }
    }
    return *this;
}

// Boolean AND Overloading
Relation Relation::operator+(const Relation &refRel) const
{
    Relation TempRel(*this);
    return (TempRel += refRel);
}

// Boolean NOT Overloading
Relation Relation::operator!() const
{
    Relation TempRel(*this);
    if (TempRel.m_ppRelation)
    {
        short sCount = 0;
        bool *pFirst = *TempRel.m_ppRelation;
        for (; sCount < m_sXSize * m_sYSize; sCount++, pFirst++)
        {
            *pFirst = !(*pFirst);
        }
    }
    return TempRel;
}

// Delete Relations Allocation and Set the Sizes to Zero
void Relation::EmptyRelation()
{
    if (m_ppRelation)
    {
        delete m_ppRelation[0];
        delete m_ppRelation;
        m_sXSize = 0;
        m_sYSize = 0;
    }
}

// Help Function to Copy a Relation
void Relation::CopyReletion(const short sXSize,
                            const short sYSize,
                            const ppBool ppRelation)
{
    short sCount = 1;
    short sElementsNum;
    bool *pRelation;
    bool *pHelp;

    EmptyRelation();
    m_sXSize = sXSize;
    m_sYSize = sYSize;

    if (ppRelation == 0)
    {
        m_ppRelation = 0;
    }
    else
    {
        sElementsNum = (short)(m_sXSize * m_sYSize);
        m_ppRelation = new bool *[m_sXSize];
        *m_ppRelation = new bool[sElementsNum];
        pRelation = *m_ppRelation;
        for (; sCount < sXSize; sCount++)
        {
            pRelation += m_sYSize;
            m_ppRelation[sCount] = pRelation;
        }
        pRelation = *m_ppRelation;
        pHelp = *ppRelation;
        for (sCount = 0; sCount < sElementsNum; sCount++,
            pRelation++,
            pHelp++)
        {
            *pRelation = *pHelp;
        }
    }
};
