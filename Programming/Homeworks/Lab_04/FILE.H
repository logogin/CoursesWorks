#ifndef Fi_H
#define Fi_H

class File{
	public:
		void Print();

		File(int a=1, int b=1);	// constructor

		File Add( const File&);
	private:
		int x;
		int y;
};

#endif