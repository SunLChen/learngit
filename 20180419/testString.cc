 ///
 /// @file    testString.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-19 19:15:30
 ///
#include "MyString.h" 
#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
int main()
{

	MyString m1="hello world";
	cout<<"m1:"<<m1<<"  "<<m1.getRef()<<endl;
	cout<<endl;
	printf("m1=%p\n",m1.c_str());
	
	MyString m2(m1);
	cout<<"m2:"<<m2<<m2.getRef()<<endl;
	cout<<"m1:"<<m1<<"  "<<m1.getRef()<<endl;
	cout<<endl;
	printf("m2=%p\n",m2.c_str());
	
	m2[1]='H';	
	cout<<"m2:"<<m2<<m2.getRef()<<endl;
	
	cout<<endl;
	printf("m2=%p\n",m2.c_str());
	printf("m1=%p\n",m1.c_str());
//	char c=m2[0];

	cout<<endl;
	MyString m3(m2);
	cout<<"m2:"<<m1<<"  "<<m2.getRef()<<endl;
	cout<<"m3:"<<m1<<"  "<<m3.getRef()<<endl;
	MyString m4(m2);
	cout<<"m2:"<<m2<<"  "<<m2.getRef()<<endl;
	cout<<"m3:"<<m3<<"  "<<m3.getRef()<<endl;
	cout<<"m4:"<<m4<<"  "<<m4.getRef()<<endl;
    const char c=m2[0];
	printf("c=%c\n",c);
	printf("m2=%p\n",m2.c_str());
	MyString m6(m2);
	cout<<"m2[0]="<<m2[0];
	cout<<"m2:"<<m2<<"  "<<m2.getRef();
	cout<<endl;
	printf("m2=%p\n",m2.c_str());
	return 0;
}
