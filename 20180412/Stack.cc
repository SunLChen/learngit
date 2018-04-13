 
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class Stack{
	public:
		Stack()
		:data(new int[10]())
		,empty(0)
		{};
		void push(int a){
			if(empty<10){
				data[empty]=a;
				empty++;
			}else{
				error();
			}
		};
		void pop(){
			if(empty>=0){
				empty--;
			}else{
				error();	
			}
		};
		int top(){
			int t=empty;
			t--;
			if(t<0){
				error();
			}
			return data[t];
		};
		bool emty(){
			return (empty==-1);
		};
		bool full(){
			return (empty==10);
		}
		~Stack(){
			delete [] data;
		}
	private:
		void error(){
			cout<<"stack over flow"<<endl;
			exit(0);
		};
	private:
		int *data;
		int empty;
};

int main(void){
	Stack s;
	s.push(10);
	s.push(12);
	s.push(14);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
	return 0;

}
