 ///
 /// @file    MyString.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-19 17:12:25
 ///
#include "MyString.h"
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

//构造函数
MyString::MyString()
:_pstr(new char[5]())
{
	*(int *)_pstr=1;
	_pstr+=4;
}
//复制构造函数
MyString::MyString(const MyString &ctemp)
:_pstr(ctemp._pstr)
{
	increaseRef();
}
//重载构造函数
MyString::MyString(const char * ctemp)
	:_pstr(new char[strlen(ctemp)+5])
{
	_pstr+=4;
	strcpy(_pstr,ctemp);
	increaseRef();
}
//重载复制运算符
MyString & MyString::operator=(const char * ctemp)
{	
	cout<<"===="<<endl;
	char *p=new char[strlen(ctemp)+5]();
	releaseRef();
	_pstr=p;
	_pstr+=4;
	strcpy(_pstr,ctemp);
	increaseRef();
	return *this;
}

//重载赋值运算符char版本
 char & MyString::operator[](size_t idx){
	cout<<"[]"<<endl;
	if(idx<getSize()){
		if(getRef()>1){
			char *p=new char[strlen(_pstr)+5];
			strcpy(p+4,_pstr);
			releaseRef();
			_pstr=p+4;
			increaseRef();
		}
		return _pstr[idx];
	}
	return _pstr[getSize()+1];
}


//重载下标第一个版本
const char & MyString::operator[](const size_t idx)const
{	
	cout<<"const []"<<endl;
	if(idx<getSize()){
		return _pstr[idx];
	}else{
		return _pstr[getSize()+1];
	}
}

MyString & MyString::operator=(const MyString & ctemp){
	if(this!=&ctemp){
		releaseRef();
		_pstr=ctemp._pstr;
		increaseRef();
	}
	return *this;

}
//重载<<运算符
ostream & operator<<(ostream &os,const MyString &ctemp)
{
    os<<ctemp._pstr<<"  ";
	return os;
}
size_t MyString::getSize()const
{
	return strlen(_pstr);
}
//对引用计数加1
void MyString::increaseRef()
{
	++(*(int *)(_pstr-4));	
}
//对引用计数减1，若引用计数为0，则执行delete 操作
void MyString::releaseRef(){
	--(*(int *)(_pstr-4));
	cout<<"re"<<getRef()<<endl;
	if(getRef()==0){
		cout<<"releaseRef"<<endl;
		delete[] (_pstr-4);
	}
}
//获取引用计数
int MyString::getRef(){
	return *(int *)(_pstr-4);
}

char * MyString::c_str(){
	return _pstr;
}


