
#ifndef CVector_H
#define CVector_H

class ComplexVector
{
	friend ostream &operator<<(ostream &,const ComplexVector &);
	friend istream &operator>>(istream &,ComplexVector &);

	public:
		ComplexVector(unsigned short=1);
		ComplexVector(const ComplexVector &);
		void NewVector(unsigned short=1);
		~ComplexVector();

		const ComplexVector operator+(const ComplexVector &) const;
		const ComplexVector operator-(const ComplexVector &) const;
		const Complex operator*(const ComplexVector &) const;
		const Complex operator^(const ComplexVector &) const;
		const ComplexVector operator~() const;
		const ComplexVector operator&(const ComplexVector &) const;
		const ComplexVector operator|(const ComplexVector &) const;

		ComplexVector &operator=(const ComplexVector &);
		ComplexVector &operator+=(const ComplexVector &);
		ComplexVector &operator-=(const ComplexVector &);
		ComplexVector &operator&=(const ComplexVector &);
		ComplexVector &operator|=(const ComplexVector &);

		Complex &operator[](const unsigned short);
		const Complex &operator[](const unsigned short) const;

		const bool operator==(const ComplexVector &) const;
		const bool operator!=(const ComplexVector &) const;

	private:
		unsigned short VectorSize;
		Complex *Vector;
};

#endif CVector_H