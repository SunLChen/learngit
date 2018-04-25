 ///
 /// @file    freight_opreator.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-17 15:39:52
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex{
	public:
		Complex(int real=0,int imag=0)
		:_real(real)
		,_imag(imag)
		{}
		//重载加法运算符
		friend Complex operator+(const Complex &c1,const Complex &c2);
		//重载+=运算符
		Complex & operator+=(const Complex &c1);
		//重载前置++运算符
		Complex & operator++();
		//重载后置++运算符
		Complex operator++(int);
	private:
		double _real;
		double _imag;
};
