#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

class Queue{
	public:
		Queue()
		:_data(new int[10]())
		,_head(0)
		,_tail(0)
		{};
		void push(int a){
			if(_head<10){
				_data[_head]=a;
				_head++;
			}else{
				error();
			}		
		};
		void pop(){
			if(_tail<=_head){
				_tail++;
			}else{
				error();
			}
		};
		int front(){
			if(_tail<=_head){
				return _data[_tail];
			}else{
				error();
				return -1;
			}
		}
		int back(){
			int temp=_head;
			return _data[--temp];
		}
		bool emty(){
			return (_tail>_head);
		}
		bool full(){
			return (_head-_tail==9);
		}
		~Queue(){
			delete [] _data;
		}
	private:
		void error(){
			delete [] _data;
			cout<<"Queue over flow"<<endl;
			exit(0);
		}
	private:
		int * _data;
		int _head;
		int _tail;
};
int main(){
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
	cout<<"empty:"<<q.emty()<<endl;
	cout<<"full:"<<q.full()<<endl;
	return 0;
}
