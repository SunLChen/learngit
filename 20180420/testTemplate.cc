///
/// @file    testTemplate.cc
/// @author  cgy(cgy@qq.com)
/// @date    2018-04-20 19:10:44
///

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
template <typename... Args> 
void display(Args... args)
{

	cout << "sizeof(Args) = " << sizeof...(Args) << endl;
	cout << "sizeof(args) = " << sizeof...(args) << endl;

}
int test0(void)
{
	display(1);
	display(1, 'a');
	display(1, 'a', string("hell"));
	display(1, 'a', "hell", 1.1);
	return 0;
}

void print()
{	cout <<endl;	}

	template <typename T, typename... Args>
void print(T t, Args... args)
{
	cout << t << endl;
	print(args...);
}

void test1(void)
{
	print(1, 2, 3 ,"cccc");

}


	template <typename T>
T sum(T t)
{
	return t;
}

	template <typename T, typename... Args>
T sum(T t, Args... args)
{
	return t + sum(args...);
}

void test2(void)
{
	int ret = sum(1, 2, 3, 4);

	cout << ret << endl;
}

int main(void)
{
	test1();
	return 0;
}

