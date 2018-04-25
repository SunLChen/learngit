 ///
 /// @file    testString.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-17 20:12:24
 ///
#include"String.h" 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){
	//第一个函数
	String s;
	cout<<s<<endl;

	String s1("hello world");
	cout<<"s1:"<<s1<<endl;
	
	String s2(s1);
	cout<<"s2:"<<s2<<endl;
	
	String s3=s2;
	cout<<"s3:"<<s3<<endl;

	String s4="how are you";
	cout<<"s4:"<<s4<<endl;
	
	s4+=s3;
	cout<<"s4+=s3:"<<s4<<endl;
	
	s4+=" fine, And You?";
	cout<<"s4+const char *:"<<s4<<endl;

	char c=s4[1];
	cout<<"s4[1]: "<<c<<endl;
	
	cout<<"s4.size: "<<s4.size()<<endl;

	cout<<"s4==s3:  "<<(s4==s3)<<endl;
	cout<<"s4!=s3:  "<<(s4!=s3)<<endl;
	cout<<"s4>s3:  "<<(s4>s3)<<endl;
	cout<<"s4>=s3:  "<<(s4>=s3)<<endl;
	cout<<"s4<s3:  "<<(s4<s3)<<endl;
	cout<<"s4<=s3:  "<<(s4<=s3)<<endl;
	
	String s6;
	cin>>s6;
	cout<<"cin>>s6::  "<<s6<<endl;

	String s7=s6+s4;
	cout<<"s7=s6+s4: "<<s7<<endl;

	String s8=s4+" My String";
	cout<<"s8=s4+const char * :"<<s8<<endl;

	String s9="Your String"+s8;
	cout<<"s9=const char *+s8:  "<<s9<<endl;

	return 0;
}
