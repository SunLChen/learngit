 ///
 /// @file    Vector.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-26 19:41:31
 ///
 
#include <iostream>
#include <memory>
#include <string>
using namespace std;
template <typename T>
class Vector
{
	public:
		Vector();
		~Vector();

		void push_back(const T &);
		void pop_back();

		int size();
		int capacity();
	private:
		void reallocate();
	private:
		static std::allocator<T> _alloc;
		T * _start;
		T * _finish;
		T *_end_of_storage;
};
template <typename T>
std::allocator<T> Vector<T>::_alloc;
template<typename T>
Vector<T>::Vector()
:_start(_alloc.allocate(1))
,_finish(_start)
,_end_of_storage(_start+1)
{}
template <typename T>
Vector<T>::~Vector()
{
	_alloc.deallocate(_start,_end_of_storage-_start-1);
}

template <typename T>
void Vector<T>::push_back(const T & temp)
{
	if(++_finish!=_end_of_storage){
		*_finish=temp;	
	}else{
		reallocate();
		*(++_finish)=temp;
	}
}

template <typename T>
void Vector<T>::pop_back()
{

	if(_finish!=_start&&(_finish!=_end_of_storage)){
		cout<<"element:"<<*_finish<<endl;
		cout<<"size:"<<size()<<endl;
		cout<<"capacity"<<capacity()<<endl;
		_alloc.destroy(_finish);
		--_finish;
	}
	else if(_finish==_start&&(_finish!=_end_of_storage))
	{
		cout<<"element:"<<*_finish<<endl;
		_alloc.destroy(_finish);
		_alloc.deallocate(_start,_end_of_storage-_start-1);
		_end_of_storage=_start;		
	}
	else
	{
		cout<<"该容器中已经没有元素了"<<endl;
	}
}

template <typename T>
int Vector<T>::size()
{
	return _finish-_start;
}

template<typename T>
int Vector<T>::capacity()
{
	return _end_of_storage-_start;
}


template <typename T>
void Vector<T>::reallocate()
{
	int len=capacity();
	T * temp=_alloc.allocate(len*2);
//	T *start=temp;
//	T *start1=_start;
//	for(;_start<_end_of_storage;++_start,++temp){
//		*temp=*_start;
//	}
	uninitialized_copy(_start,_finish,temp);
	_alloc.deallocate(_start,len-1);
	_start=temp;
	_finish=_start+len-1;
	_end_of_storage=_start+len*2;
}

int main(){
	Vector<int> a;
	for(int i=0;i<10;i++){
		a.push_back(i);	
	}
	for(int i=0;i<10;i++){
		a.pop_back();
	}
	return 0;
}
