
#ifndef Complex_H
#define Complex_H

class Complex
{
    friend ostream &operator<<(ostream &,const Complex &);
	friend istream &operator>>(istream &,Complex &);
	friend const Complex operator+(const float [],const Complex &);
	
	public :
		Complex(const float=0.0,const float=0.0);
		Complex(const Complex &);

		const Complex operator+(const Complex &) const;
		const Complex operator-(const Complex &) const;
		const Complex operator*(const Complex &) const;
		const Complex operator/(const Complex &) const;
		const Complex operator~() const;
		const Complex operator^(const Complex &) const;

		Complex &operator=(const Complex &);
		Complex &operator+=(const Complex &);
		Complex &operator-=(const Complex &);
		Complex &operator*=(const Complex &);
		Complex &operator/=(const Complex &);
		Complex &operator^=(const Complex &);

		const bool operator==(const Complex &) const;
		const bool operator!=(const Complex &) const;

		/************HomeWork 06****************/
		Complex &operator()(const float=0.0,const float=0.0);
		Complex &operator()(const float=0.0,const char='r');
		const Complex operator+(const float []) const;
		operator float *() const;

	private :
		float Real;
		float Imaginary;
};

#endif Comlex_H