 ///
 /// @file    stackop.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-13 04:45:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class stackop{
	
	public:
		stackop(){};
		~stackop(){};
	private:
		void * operator new(size_t sz);
		void operator delete(void *);
};
int main(){
	stackop();
	return 0;
}
