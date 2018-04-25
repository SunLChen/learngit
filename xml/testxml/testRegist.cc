///
/// @file    testRegist.cc
/// @author  cgy(cgy@qq.com)
/// @date    2018-04-22 16:41:42
///

#include <iostream>
#include <regex>
using std::cout;
using namespace std;

int test_regex_replace2()  
{  
	// reference: http://www.cplusplus.com/reference/regex/regex_replace/  
	string s("there is a &amp;nbsp;&amp;nbsp;&amp;nbsp;subseq<asdf>uence<12345678656565665\\><fsadfasgasdfg/> in th<sadfas>e string\n");  
	std::regex e("(&amp;nbsp;)|<(\\S*?)[^>]*>.*?|<.*? />");
//	std::regex e("(&amp;nbsp;)");
	// using string/c-string (3) version:  
	std::cout << std::regex_replace(s, e, "sub-$2");  

	// using range/c-string (6) version:  
	std::string result;  
	std::regex_replace(std::back_inserter(result), s.begin(), s.end(), e, "");  
	std::cout << result;  

	// with flags:  
	std::cout << std::regex_replace(s, e, "$1 and $2", std::regex_constants::format_no_copy);  
	std::cout << std::endl;  

	return 0;  
} 
int main(){
	 test_regex_replace2();
	return 0;
}
