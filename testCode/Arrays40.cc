 ///
 /// @file    Arrays40.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-12 05:23:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;
/*
 *题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序。每一列都按照从上到下递增的顺序排序。
 输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 *1.当遇到一个较为复杂的问题时，有时很有必要去构建一个例子，去一个特殊值，以便去找到对应的规律
 2.本题通常的思路是走对角线，而对角线并不能保证可以踢出元素
 3。对与找元素之类的题目，首要考虑剔除情况，并且选取元素时，要遵循单一变量原则，及在某种情况下，其可以唯一确定
	一种情况
 * */
bool find(int *matrix,int rows,int columns, int number){
	bool found=false;//初始值设为为false，代表没有找到
	if(matrix != NULL&&rows>0&&columns>0)//确保是一个二维数组，一般需要验证
	{
		int row=0;//行
		int column=columns-1;//列
		while(row<rows &&column>=0){//循环遍历对应的元素
			if(matrix[row*columns+column]==number){//若相等，则返回
				found=true;
				break;
			}
			else if(matrix[row*columns+column]>number)//若大于，则对应的列丢弃
				--column;
			else//若小于，则对应的行丢掉
				row++;
		}
	}
	return found;
};
