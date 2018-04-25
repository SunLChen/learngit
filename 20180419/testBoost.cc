///
/// @file    testBoost.cc
/// @author  cgy(cgy@qq.com)
/// @date    2018-04-22 20:15:01
///

#include <iostream>
using std::cout;
using std::endl;


#include <iostream> 
#include <boost/version.hpp> 
#include <boost/timer.hpp> 
using namespace std; 
int main() 
{ 
	boost::timer t; 
	cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl; 
	cout << "min timespan: " << t.elapsed_min() << "s" << endl; 
	cout << "now time elapsed: " << t.elapsed() << "s" << endl; 
	cout << "boost version" << BOOST_VERSION <<endl; 
	cout << "boost lib version" << BOOST_LIB_VERSION <<endl; 
	return 0; 
} 
