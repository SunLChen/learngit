 ///
 /// @file    heapop.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-13 04:50:19
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class heapop{
	
	public:
		heapop(){};
		void destroy(){
			delete this;
		};
		void *operator new (size_t size){
			return malloc(size);
		};
	private:
		~heapop(){};
};
int main(){
	heapop *h=new heapop;
	h->destroy();
	return 0;
}

