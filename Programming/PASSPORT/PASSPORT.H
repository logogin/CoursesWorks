
#ifndef Passport_H
#define Passport_h
#include "Date.h"
#include "Name.h"
#include "Sex.h"

class Passport
{
	public:
		Passport();
		bool Compare(Passport &) const;
		char *FirstName() const;
	private:
		const Name PersonName;
		const Date BirthDate;
		const Sex PersonSex;
		Date LastExit;
		Date LastReturn;
};

#endif Passport_H