
#ifndef ProductString_H
#define ProductString_H

class ProductString
{
	friend ostream &operator<<(ostream &,const ProductString &);
	public:
		ProductString(void);
		ProductString(const unsigned int,const unsigned char);
		ProductString(const ProductString &);
		ProductString(const ProductString &,const ProductString &);

		~ProductString(void);

		void PrintMinterms(ostream &) const;
		unsigned int GetMintermNumber(void) const;
		unsigned int GetMintermNumber(const ProductString &) const;
		unsigned int Get1sNumber(void) const;
		unsigned int Get1sNumber(const ProductString &) const;
		unsigned int GetMinterm(const unsigned int) const;

		ProductString &operator =(const ProductString &);
		const ProductString operator +(const ProductString &) const;
		const bool operator ^(const ProductString &) const;
		const bool operator ==(const ProductString &) const;

	private:
		char *pString;
		unsigned int *MintermArray;
		unsigned int MintermNumber;
		void ConvertNumber(unsigned int);
		void Convert2Binary(void);
		unsigned char VarNumber;
};

#endif ProductString_H