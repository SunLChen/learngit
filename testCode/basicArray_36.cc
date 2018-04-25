 ///
 /// @file    basicArray_36.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-12 05:09:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int GetSize(int data[]){
	return sizeof(data);
}
int main(void){
	int data1[]={1,2,3,4,5};
	int size1=sizeof(data1);

	int *data2=data1;
	int size2=sizeof(data2);

	int size3=GetSize(data1);
	cout<<size1<<"  "<<size2<<"  "<<size3<<endl; 
}
