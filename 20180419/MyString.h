 ///
 /// @file    MyString.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-19 15:47:18
 ///
#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<stdlib.h>
#include<iostream>
using std::ostream;
class MyString{
	public:
		MyString();
		MyString (const MyString & c);
		MyString (const char *);
		MyString & operator=(const char *);
		MyString & operator=(const MyString &);
	    const char & operator[](size_t idx)const;

		char * c_str();
		friend ostream & operator<<(ostream &os,const MyString &);
		char & operator[](size_t idx);
		int getRef();
		~MyString()	{
			releaseRef();
			std::cout<<"~MyString()"<<std::endl;
		}
	private:
		void increaseRef();
		void releaseRef();
	    size_t getSize() const;
	private:
		char * _pstr;
};

#endif
