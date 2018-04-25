 ///
 /// @file    Queue.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-20 16:06:08
 ///
 
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

template <typename T,size_t size=10>
class Queue{
	public:
		Queue();
		~Queue();
		void push(T t);
		void pop();
		bool empty();
		bool full();
		T top();
		T back();
	private:
		int _rear;
		int _front;
		T *_type;
};

template <typename T,size_t size>
Queue<T,size>::Queue()
:_rear(0)
,_front(0)
,_type(new T[size]())
{}

template <typename T,size_t size>
Queue<T,size>::~Queue()
{
	delete[] _type;
}

template <typename T,size_t size>
void Queue<T,size>::push(T t)
{
	if(!full()){
		_type[_rear]=t;
		_rear=(_rear+1)%size;
	}
	else
	{
		cout<<"队列已满，无法插入"<<endl;
	}
}
template <typename T,size_t size>
void Queue<T,size>::pop()
{
	if(!empty()){
		_front=(_front+1)%size;
	}else
	{
		cout<<"队列为空"<<endl;
	}
}
template <typename T,size_t size>
bool Queue<T,size>::empty()
{
	if(_front==_rear){
		return true;
	}
	return false;
}
template <typename T,size_t size>
bool Queue<T,size>::full()
{
	if((_rear+1)%size==_front)
	{
		return true;
	}
	return false;
}
template <typename T,size_t size>
T Queue<T,size>::top()
{
	if(!empty())
		return _type[_front];
	cout<<"队列为空！"<<endl;
	T t(-1);
	return t;
}

template <typename T,size_t size>
T Queue<T,size>::back()
{
	if(!empty())
		return _type[(_rear-1+size)%size];
	cout<<"队列为空！"<<endl;
	T t(-1);
	return t;
}
int main(){
	Queue<int> q;
	for(int i=0;i<11;i++)
	{
		q.push(i);
	}
	for(int i=0;i<11;i++)
	{
		cout<<q.top()<<endl;
		q.pop();
	}

	return 0;
}
