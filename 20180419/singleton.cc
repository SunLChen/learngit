 ///
 /// @file    singleton.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-19 10:33:28
 ///
 
#include <iostream>
#include<stdlib.h>
#include <pthread.h>
using std::cout;
using std::endl;
class Singleton{
	public:
		static void init(void){
			_pInstance=new Singleton;
			atexit(destroy);
		}
		static Singleton * getInstance(){
			pthread_once(&_once,init);
			return _pInstance;
		}
		static void destroy(){
			if(_pInstance){
				delete _pInstance;
			}
		}
	private:
		Singleton(){
			cout<<"Singleton()"<<endl;
		};
		~Singleton(){
			cout<<"~Singleton()"<<endl;
		};
	private:
		static Singleton *_pInstance;
		static pthread_once_t _once;
};
Singleton * Singleton::_pInstance=NULL;
pthread_once_t Singleton::_once=PTHREAD_ONCE_INIT;

int main(){
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<"p1"<<p1<<endl;
	cout<<"p2"<<p2<<endl;
	return 0;
}
