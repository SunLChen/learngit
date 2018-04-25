 ///
 /// @file    StrReplace46.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-12 06:14:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//length为字符数组string的总容量
void ReplaceBlank(char string[],int length){
	if(string==NULL &&length <=0)
		return;
	int originalLength=0;
	int numberOfBlank=0;
	int i=0;
	//获取字符串空格的个数，顺带获取长度，
	while(string[i]!='\0'){
		++originalLength;
		if(string[i]==' ')
			++numberOfBlank;
		++i;
	}
	int newLength=originalLength+numberOfBlank*2;//替换后的字符串的总长度
	if(newLength>length)
		return ;
	int indexOfOriginal=originalLength;
	int indexOfNew=newLength;
	while (indexOfOriginal>=0&&indexOfNew>indexOfOriginal){
		if(string[indexOfOriginal]>=0&&indexOfNew>indexOfOriginal){
			string[indexOfNew--]='0';
			string[indexOfNew--]='2';
			string[indexOfNew--]='%';
		}else{
			string[indexOfNew--]=string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

