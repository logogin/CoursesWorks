
#ifndef BinaryString_H
#define BinaryString_H

class BinaryString
{
	public: 
		BinaryString(const unsigned int,const unsigned int);
		void SetNewString(const unsigned int);
		unsigned int Get1sNumber(void) const;
		char *GetString(void) const;
		unsigned int GetSize(void) const;
		~BinaryString(void);

	private:
		void Convert(void);
		unsigned int Number;
		char *bString;
		unsigned int Size;
};

#endif BinaryString