 ///
 /// @file    vector.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-13 00:42:41
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main(void){
	vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	cout<<numbers.capacity()<<endl;;
	for(auto & number:numbers){
		cout<<number<<" ";
	}
	cout<<endl;
	vector<int>::iterator it;
	for(it=numbers.begin();it!=numbers.end();++it){
		cout<< *it<<" ";
	}
	cout<<endl;
	return 0;
}
