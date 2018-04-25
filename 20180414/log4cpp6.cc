 ///
 /// @file    log4cpp.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-14 01:39:22
 ///
 
#include <iostream>
#include<stdio.h>
#include<sstream>
#include<string.h>
#include<log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
using namespace std;
//添加文件名，与行号
//对于只有函数名的情况，一般需要使用宏定义，注意宏属于简单的字符串的替换
//不要用宏定义常量：一般使用的是const的关键字
//对于实现函数的功能：一般同样使用inline关键字，使其成为内联函数
//而对于限制取地址操作时，一般使用enum替待define，因为define仅仅时简单的字符串替换
//程序会在预处理阶段把define的内容移除，这样很有肯能导致define定义的元素无法记录到程序的（symbol Table）中，导致编译错误
//define无法创建所属类的专属对象，因为预处理，注定其时被共享的 
#define DEBUGARG ((string)__FILE__+"("+to_string(__LINE__)+")  "+__func__+"()  ")
 #define logwarn(msg) MyLog::getInstance()->warn(DEBUGARG.append(msg).c_str())
 #define logerror(msg) MyLog::getInstance()->error(DEBUGARG.append(msg).c_str())
 #define loginfo(msg) MyLog::getInstance()->info(DEBUGARG.append(msg).c_str())
 #define logdebug(msg) MyLog::getInstance()->debug(DEBUGARG.append(msg).c_str())
class MyLog{
	public:
		//使用singleton模式的常规操作
		static MyLog * getInstance(){
			if(mylog==NULL){
				mylog=new MyLog();
			}
			return mylog;
		}
		static void destroy(){
			if(mylog!=NULL){
				delete mylog;
			}
		}
	    void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char * msg);
	private:
		MyLog()
		:root(log4cpp::Category::getRoot())
		{
			//设置流的目的地
			log4cpp::OstreamAppender *osAppender=new log4cpp::OstreamAppender("os",&cout);
			log4cpp::FileAppender *fileAppender=new log4cpp::FileAppender("fileAppender","cLog.log");
			//设置流的样式
			log4cpp::PatternLayout *playout=new log4cpp::PatternLayout();
			log4cpp::PatternLayout *playoutf=new log4cpp::PatternLayout();
			playout->setConversionPattern("[%d] [%p]  %m%n");
			playoutf->setConversionPattern("[%d] [%p]  %m%n");
			osAppender->setLayout(playout);
			fileAppender->setLayout(playoutf);
			//把目的地添加到对应的Catagory中
			root.addAppender(osAppender);
			root.setAppender(fileAppender);
			root.setPriority(log4cpp::Priority::DEBUG);
		};
		~MyLog(){
			log4cpp::Category::shutdown();
		};
	private:
		static MyLog *mylog;
		//对于设计类的成员属性时，一定要遵守一个原则：
		//该属性是否会直接被使用到，如果该属性不需要直接被使用，则在
		//一般情况下时不允许把其定义到类的成员属性的。因为无谓的定义会感觉很low
		log4cpp::Category &root;
};
 MyLog * MyLog::mylog=NULL;
 void MyLog::warn(const char * msg){
	root.warn(msg);
};

void MyLog::error(const char *  msg){
	root.error(msg);

};
void MyLog::debug(const char * msg){
	root.debug(msg);
};
void MyLog::info(const char * msg){
	root.info(msg);

};
int main(){
	logwarn("this is a warn msg");
	logerror("this is a warn msg");
	logdebug("this is a warn msg");
	loginfo("this is a warn msg");
	MyLog::destroy();
	return 0;
}
