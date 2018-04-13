 
#include <iostream>
using std::cout;
using std::endl;
class Singleton2{
	public:
		static Singleton2 * getInstance(){
			if(p==NULL){
				p=new Singleton2();
			}
			return p;
		};
		static void destroy(){
			if(p!=NULL){
				delete p;
			}
		};
	private:
		Singleton2();
		~Singleton2(){
			delete p;		
		}
	private:
		static Singleton2 *p;
};
Singleton2 * Singleton2::p=NULL;
int main(){

}
