// Exam 1 03.10.2000 - Ex. No. 1
// Relation Class Definition
#ifndef RELATION_CLASS
#define RELATION_CLASS
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>

typedef bool **ppBool;

class Relation
{
  friend ostream &operator<<(ostream &Output, const Relation &refRel);
  friend ofstream &operator<<(ofstream &FileOutput,
                              const Relation &refRel);

public:
  Relation(const short sXSize = 0,
           const short sYSize = 0,
           const ppBool ppRelation = 0);
  Relation(const Relation &refRel);
  Relation &SetRelation(const Relation &refRelation);
  ppBool GetRelation() const;
  Relation &Write(const char *strFileName);
  ~Relation();
  Relation &operator+=(const Relation &refRel);
  Relation operator+(const Relation &refRel) const;
  Relation operator!() const;

private:
  short m_sXSize;
  short m_sYSize;
  ppBool m_ppRelation;
  void EmptyRelation();
  void CopyReletion(const short sXSize,
                    const short sYSize,
                    const ppBool ppRelation);
};

#endif
