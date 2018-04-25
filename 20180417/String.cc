 ///
 /// @file    String.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-17 17:08:08
 ///
#include "String.h" 
#include "stdlib.h"
#include <string.h>
using std::cout;
using std::endl;
//空构造函数
String::String()
:_pstr(new char[1]()){};
//常量型
String::String(const char * temp)
:_pstr(new char[strlen(temp)+1]()){
	if(temp!=NULL)
		strcpy(_pstr,temp);
};
//复制构造函数
String::String(const String & temp)
:_pstr(new char[temp.size()]()){
	strcpy(_pstr,temp._pstr);
}

String::~String(){
	delete[] _pstr;
}
//重载赋值运算符
String & String::operator=(const String & temp)
{
	//采用异常安全的机制
	if(this!=&temp){
		String strTemp(temp);
		char *pTemp=strTemp._pstr;
		strTemp._pstr=_pstr;
		_pstr=pTemp;
	}
	return *this;

}
//重载赋值运算符const char * 类型
String & String::operator=(const char * temp)
{
	String strTemp;
	if(temp!=NULL){
		String strTemp1(temp);
		char *p=strTemp._pstr;
		strTemp._pstr=strTemp1._pstr;
		strTemp1._pstr=p;
	}
	char *p=strTemp._pstr;
	strTemp._pstr=_pstr;
	_pstr=p;
	return *this;
}

//重载+=函数
String & String::operator+=(const String & temp){
	String cTemp((*this)+temp);
	char *p=cTemp._pstr;
	cTemp._pstr=_pstr;
	_pstr=p;
	return *this;
}

//重载const char * +=操作符
String & String::operator+=(const char * cTemp){
	String str1(cTemp);
	return ((*this)+=str1);
}

//重载const 下标运算符
const char & String::operator[](std::size_t index)const{
	if(index<size()){
		return *(_pstr+index);
	}else{
		return *(_pstr+size());
	}
}
//非const 下表运算符
char & String::operator[](std::size_t index){
	return const_cast<char &>(
			static_cast<const String &>(*this)[index]
			);
}

const char* String:: c_str()const{
	return _pstr;
}
//重载==号
bool operator==(const String & c1,const String & c2)
{
	return (strcmp(c1._pstr,c2._pstr)==0);
}
//重载！=号
bool operator!=(const String &c1,const String &c2)
{
	return (strcmp(c1._pstr,c2._pstr)!=0);
}
//重载<号
bool operator<(const String &c1,const String &c2)
{
	return (strcmp(c1._pstr,c2._pstr)<0);
}

//重载>号
bool operator>(const String &c1,const String &c2)
{
	return (strcmp(c1._pstr,c2._pstr)>0);
}

//重载<=号
bool operator<=(const String &c1,const String &c2)
{
	return (strcmp(c1._pstr,c2._pstr)<=0);
}

//重载>=号
bool operator>=(const String &c1,const String &c2)
{
	return (strcmp(c1._pstr,c2._pstr)>=0);
}

std::ostream &operator<<(std::ostream &os,const String &temp)
{
	os<<temp._pstr;
	return os;
}



std::istream &operator>>(std::istream &is,String &temp)
{
	int count=0;
	char *p=new char[10]();
	int tempnum=10;
	while(char c=is.get()){
		if(c=='\n')
			break;
		if(tempnum<=count){
			tempnum=tempnum*2+1;
			char *ctemp=new char[tempnum]();
			strcpy(ctemp,p);
			delete[] p;
			p=ctemp;
		}
		p[count]=c;
		++count;
	}
	temp._pstr=p;
	return is;
}
void String::set_pstr(char *p){
	_pstr=p;
}
String operator+(const String &c1,const String &c2){
	String s;
	char *p=new char[c1.size()+c2.size()+1]();
	strcpy(p,c1.c_str());
	strcpy(p+strlen(p),c2.c_str());
	s.set_pstr(p);
	return s;
}

String operator+(const String &c1,const char * p)
{
	String stemp(p);
	String s=stemp+c1;
	return s;
}

String operator+(const char *p1,const String &s1){
	String s=s1+p1;
	return s;
}

//求string的长度,估计会有问题：：？
std::size_t String::size()const{
	return strlen(_pstr);
}


