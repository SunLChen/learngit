#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class String{
	public :
		String()
			:_pstr(new char[1]())
		{};
		String(const char *pstr)
			:_pstr(new char[strlen(pstr)+1]())	
		{
			strcpy(_pstr,pstr);
		};
		String(const String &rhs)
		{
			if(rhs._pstr!=NULL){
				_pstr=new char[strlen(rhs._pstr)+1]();
				strcpy(_pstr,rhs._pstr);
			}
		};
		String &operator=(const String &rhs)	
		{
			if(rhs._pstr!=NULL){
				char *temp=new char[strlen(rhs._pstr)+1]();
				if(_pstr!=NULL){
					delete [] _pstr;
					_pstr=NULL;
				}
				strcpy(temp,rhs._pstr);
				this->_pstr=temp;
			}
				return *this;
		};
		~String(){
			if(_pstr!=NULL)
				delete[] _pstr;
		};
		void print(){
			if(_pstr!=NULL&&_pstr[0]!=0)
				cout << _pstr << endl;
		};
	private:
		char *_pstr;
};

int main(void){
	String str1;
	str1.print();
//	String str6=NULL;
	String str5=str1;
	str5.print();	
	String str2="Hello,world";
	String str3("wangdao");

	str2.print();
	str3.print();
	String str4=str3;
	str4.print();
	str4=str2;
	str4.print();
	return 0;
}
