
#ifndef Date_H
#define Date_H
const daypermonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
class Date
{
	public:
		Date(char *);
		void SetDate(char *);
		void SetDay(int=1);
		void SetMonth(int=1);
		void SetYear(int=2001);
		void PrintDate(void);
		void GetDate(int &gDay,int &gMonth,int &gYear);
		int GetDay(void) const;
		int GetMonth(void) const;
		int GetYear(void) const;
		bool CheckDate(void);
		
	private:
		int Day;
		int Month;
		int Year;
};

#endif Date_H