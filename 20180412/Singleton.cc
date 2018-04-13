 
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	public:
		static Singleton * getInstance(){
			if(p==NULL){
				p=new Singleton;
			}
			return p;
		}
		static void destroy(){
			if(p!=NULL){
				delete p;
			}
		}
	private:
		Singleton(){};
		~Singleton(){
			delete p;
		}
	private:
		static Singleton * p;
};
Singleton * Singleton::p=NULL;
int main(void){
	Singleton * p1=Singleton::getInstance();
	Singleton * p2=Singleton::getInstance();
	cout<<p1<<endl;
	cout<<p2<<endl;
	return 0;
}
