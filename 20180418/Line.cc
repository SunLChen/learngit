 ///
 /// @file    Line.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-18 19:29:01
 ///
#include "line.h" 
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
{
	class Point
	{
		public:
			Point(int x,int y)
			:_ix(x)
			 ,_iy(y){
				cout<<"Point(int ,int)"<<endl;
			 }

			void print()const
			{
				cout<<"("<<_ix
					<<","<<_iy
					<<")";
			}
			~Point(){
				cout<<"~Point()"<<endl;
			}
		private:
			int _ix;
			int _iy;
	};
	public:
		LineImpl(int x1,int y1,int x2,int y2)
		:_pt1(x1,y1)
		 ,_pt2(x2,y2)
		{
	
			cout<<"LineImpl(int int int int )"<<endl;
		}
		
		void display()const
		{
			_pt1.print();
			cout<<"---->";
			_pt2.print();
			cout<<endl;
		}
		~LineImpl(){
			cout<<"~LineImpl()"<<endl;
		}
	private:
			Point _pt1;
			Point _pt2;
};
Line::Line(int x1,int y1,int x2,int y2)
	:_pImpl(new LineImpl(x1,y1,x2,y2))
	{
		cout<<"Line (int int int int )"<<endl;
	}
Line::~Line(){
	cout<<"~Line()"<<endl;
	if(_pImpl){
		delete _pImpl;
	}
}
void Line::display()const{
	_pImpl->display();	
}
