 ///
 /// @file    line.h
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-18 19:23:35
 ///
 
#ifndef _LINE_H_
#define _LINE_H_

class Line{
	public:
		Line(int x1,int y1,int x2,int y2);
		~Line();

		void display() const;
	private:
		//设计模式之pimpl
		//1.实现信息的隐藏
		//2.当库需要升级的时候，可以以最小的代价完成库的升级
		//3.减小编译依赖
	class LineImpl;//类的前向声明
	private:
		LineImpl *_pImpl;
};
#endif
