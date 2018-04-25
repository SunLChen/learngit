 ///
 /// @file    SingletonTemplate.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-20 17:04:46
 ///
 
#include <iostream>
#include<string>
#include <stdio.h>
using std::cout;
using std::endl;
using std::string;
class point;
class computer;
template <typename T>
class Singleton{
	template<typename T1>
	class AutoRelease{
		public:
			AutoRelease();
			~AutoRelease(){
				if(_temp!=NULL)
					delete _temp;
			}
	};
	public:
		template <typename T1,typename T2>
		static  T * getInstance(T1 t1,T2 t2){
			
			if(_temp==NULL)

				_temp=new T(t1,t2);
			return _temp;
		}
	private:
		Singleton();
		~Singleton();
	private:
		static T * _temp;
		static AutoRelease<T> *_auto;
};
class point{
	public:
		point(int x,int y)
		:_ix(x)
		,_iy(y)
		{}
	private:
		int _ix;
		int _iy;
};

class computer{
	public:
		computer(string name,int price)
			:_name(name)
			 ,_price(price){}
		~computer(){}
	private:
		string _name;
		int _price;
};
template <typename T>
T *Singleton<T>::_temp=NULL;
template<typename T>
Singleton<T>::AutoRelease<T> * Singleton<T>::_auto;

int main(){
	computer * p1=Singleton<computer>::getInstance("xiaomi",6666);
	computer * p2=Singleton<computer>::getInstance("xiaomi",6666);
	cout<<"p1:"<<p1<<endl;
	cout<<"p2:"<<p2<<endl;

	point * p3=Singleton<point>::getInstance(1,2);
	point * p4=Singleton<point>::getInstance(1,2);
	cout<<"p3:"<<p3<<endl;
	cout<<"p4:"<<p4<<endl;

}

