class Complex
{
private:
	float Real;
	float Image;

public:
	Complex& operator += ( const Complex C );
	Complex& operator =  ( const Complex C );

};

Complex & Complex::operator += ( const Complex C )
{
	Real  += C.Real;
	Image += C.Image;


	return ( *this );
}

Complex & Complex::operator = ( const Complex C )
{
	Real  = C.Real;
	Image = C.Image;

	return ( *this );
}