
#ifndef CMatrix_H
#define CMatrix_H

class ComplexMatrix
{
	friend ostream &operator<<(ostream &,const ComplexMatrix &);
	friend istream &operator>>(istream &,ComplexMatrix &);

	public:
		ComplexMatrix(const unsigned short=1,const unsigned short=1);
		ComplexMatrix(const ComplexMatrix &);
		~ComplexMatrix();

		const ComplexMatrix operator+(const ComplexMatrix &) const;
		const ComplexMatrix operator-(const ComplexMatrix &) const;
		const ComplexMatrix operator*(const ComplexMatrix &) const;
		const ComplexMatrix operator&(const ComplexMatrix &) const;
		const ComplexMatrix operator|(const ComplexMatrix &) const;
		const ComplexMatrix operator~() const;
		const ComplexMatrix operator!() const;
		const ComplexMatrix operator^(const ComplexMatrix &) const;

		ComplexMatrix &operator=(const ComplexMatrix &);
		ComplexMatrix &operator+=(const ComplexMatrix &);
		ComplexMatrix &operator-=(const ComplexMatrix &);
		ComplexMatrix &operator*=(const ComplexMatrix &);
		ComplexMatrix &operator&=(const ComplexMatrix &);
		ComplexMatrix &operator|=(const ComplexMatrix &);
		ComplexMatrix &operator^=(const ComplexMatrix &);

		const ComplexVector &operator[](const unsigned short) const;
		ComplexVector &operator[](const unsigned short);

		const bool operator==(const ComplexMatrix &) const;
		const bool operator!=(const ComplexMatrix &) const;

	private:
		unsigned short ColumnSize;
		unsigned short RowSize;
		ComplexVector *Matrix;
};

#endif CMatrix_H