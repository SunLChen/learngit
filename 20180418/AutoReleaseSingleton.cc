 ///
 /// @file    AutoReleaseSingleton.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-18 19:54:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	private:
		class AutoRelease{
			public:
				AutoRelease(){cout<<"AutoRelease()"<<endl;}
				~AutoRelease(){
					if(_pInstance){
						delete _pInstance;
						cout<<"~AutoRelease()"<<endl;
					}
				}
		};
	public:
		static Singleton * getInstance()
		{
			if(NULL==_pInstance)
			{
				_pInstance=new Singleton;
			}
			return _pInstance;
		}
	private:
		Singleton(){cout<<"Singleton"<<endl;};
		~Singleton(){cout<<"~Singleton"<<endl;};
	private:
		static Singleton *_pInstance;
		static AutoRelease _auto;
};

Singleton * Singleton::_pInstance=getInstance();

Singleton::AutoRelease Singleton::_auto;

int main(void){
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<"p1="<<p1<<endl;
	cout<<"p2="<<p2<<endl;
	return 0;
}
