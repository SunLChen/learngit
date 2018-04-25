 ///
 /// @file    cowString.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-22 19:43:01
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cout;
using std::endl;

class String{
	private:
		class CharProxy
		{
			public:
				CharProxy(size_t idx,String &self)
				:_idx(idx)
				 ,_self(self){}
				operator char(){
					return _self._pstr[_idx];
				}
				char &operator=(const char &ch);
			private:
					size_t _idx;
					String & _self;
		};
	public:
		String();
		String(const char *);
		String(const String &);
		String &operator=(const String & );
		~String();

		const char & operator[](size_t idx) const
		{
			return _pstr[idx];
		}
		CharProxy operator[](size_t idx);
		size_t size(){return strlen(_pstr);}
		const char * c_str() const {return _pstr;}

		size_t refcount()const
		{
			return ((int *)(_pstr-4))[0];
		}
		friend std::ostream & operator<<(std::ostream &os,const String &rhs);
	private:
		void initRefcount()
		{
			((int *)(_pstr-4))[0]=1;
		}

		void increaseRefcount(){
			++((int *)(_pstr-4))[0];
		}

		void decreaseRefcount()
		{
			--((int *)(_pstr-4))[0];
		}

		void release()
		{
			decreaseRefcount();
			if(refcount()==0)
			{
				delete[] (_pstr-4);
				cout<<"release data"<<endl;
			}
		}
	private:
		char *_pstr;
};

std::ostream &operator<<(std::ostream &os,const String &rhs)
{
	os<<rhs._pstr;
	return os;
}

String::String()
:_pstr(new char[5]())
{
	cout<<"String()"<<endl;
	_pstr+=4;
	initRefcount();
}

String::String(const char * pstr)
:_pstr(new char[strlen(pstr)+5]())
{
	cout<<"String(const char *)"<<endl;
	_pstr+=4;
	initRefcount();
	strcpy(_pstr,pstr);
}
String::String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String & String::operator=(const String &rhs)
{
	if(this!=&rhs)
	{
		release();
		_pstr=rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	release();
	cout<<"~String()"<<endl;
}

String::CharProxy String::operator[](size_t idx)
{
	return CharProxy(idx,*this);
}

char & String::CharProxy::operator=(const char &ch)
{
	if(_self.refcount()>1){
		_self.decreaseRefcount();
		char *ptmp=new char[_self.size()+5]();
		strcpy(ptmp+4,_self._pstr);
		_self._pstr=ptmp+4;
		_self.initRefcount();
	}
	_self._pstr[_idx]=ch;
	return _self._pstr[_idx];
}

