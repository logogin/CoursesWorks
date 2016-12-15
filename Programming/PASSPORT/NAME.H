#ifndef Name_H
#define Name_H

class Name
{
	public:
		Name();
		~Name();
		void SetFirstName(char *);
		void SetLastName(char *);
		void PrintFullName(void);
		void GetFullName(char *,char *);
		char *GetFirstName() const;
		char *GetLastName() const;
	private:
		char *FirstName;
		char *LastName;
};

#endif Name_H 