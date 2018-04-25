 ///
 /// @file    HeapSort.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-24 17:33:48
 ///
 
#include <iostream>
#include <functional>
#include <algorithm>
using std::cout;
using std::endl;
using std::swap;
using namespace std;
template <typename T,typename Compare=std::less<T>>
class HeapSort
{
	public:
		HeapSort(T *arr,int size)
		:_arr(new T[size+1]())
		 ,_count(size+1)
		 ,_size(0)
		{
			for(;_size!=size;_size++){
				_arr[_size+1]=arr[_size];
			}
		};
		void heapAdjust();
		void shiftUp(int);
		void sort();
		void insert(T t);
		~HeapSort(){
			delete[] _arr;
		}
	private:
		T * _arr;
		int _count;
		int _size;
};

template <typename T ,typename Compare>
void HeapSort<T,Compare>::heapAdjust()
{
	Compare compare=Compare();
	int k=0;
	for(int i=_size/2;i>0;--i){	
		T temp=_arr[i];
		k=i;
		while(2*k<=_size){
			int j=2*k;
			if(j+1<=_size){
				if(compare(_arr[j],_arr[j+1])){
					++j;
				}
			}
			if(compare(_arr[j],_arr[k])){
				break;
			}
			swap(_arr[k],_arr[j]);
			k=j;
		}
	}
}


template <typename T,typename Compare>
void HeapSort<T,Compare>::insert(T t){
	if(_size+1<=_count){
		++_size;
		_arr[_size]=t;
		shiftUp(_size);
	}
}


template <typename T,typename Compare>
void  HeapSort<T,Compare>::shiftUp(int size){
	Compare compare=Compare();
	while(size>1&&compare(_arr[size/2],_arr[size]))
	{
		swap(_arr[size/2],_arr[size]);
		size/=2;
	}
}


template <typename T,typename Compare>
void HeapSort<T,Compare>::sort()
{
	while(_size){
		T temp=_arr[1];
		swap(_arr[1],_arr[_size]);
		--_size;
		heapAdjust();
		cout<<temp<<" ";
	}
	cout<<endl;

}

int main(){
	int arr[10]={0,455,78,12,4578,46,21,12,4587,5};
	HeapSort<int> h(arr,10);
	h.heapAdjust();
	h.sort();
	cout <<"double sort"<<endl;
	double brr[10]={1.1,5.2,8.8,4.7,65.6,52.5,452.2,10.0,54,0};
	HeapSort<double> h1(brr,10);
	h1.heapAdjust();
	h1.sort();
	return 0;
}
