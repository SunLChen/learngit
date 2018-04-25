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

 #define DEBUGFMT  "%s(%d)-%s"
 #define DEBUGARG ((string)__FILE__+"("+to_string(__LINE__)+")  "+__func__+"()")

class MyLog{
	public:
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
		log4cpp::Category & getlogCate(){
			
			cate.addAppender(osAppender);
			cate.setPriority(log4cpp::Priority::DEBUG);
			return cate;
		}
	    void warn(const char * msg,string s);
		void error(const char * msg,string s);
		void debug(const char * msg,string s);
		void info(const char * msg,string s);
	private:
		MyLog()
		:osAppender(new log4cpp::OstreamAppender("osAppenderW",&cout))
		{
			playout=new log4cpp::PatternLayout();
			playout->setConversionPattern("%d: %p %c %x: %m%n");
			osAppender->setLayout(playout);
		};
		~MyLog(){
			log4cpp::Category::shutdown();
		};
	private:
		static MyLog *mylog;
		log4cpp::Category &root=log4cpp::Category::getRoot();
		log4cpp::OstreamAppender *osAppender;
		log4cpp::PatternLayout *playout;
		log4cpp::Category &cate=root.getInstance("cate");
};
 MyLog * MyLog::mylog=NULL;
 void MyLog::warn(const char * msg,string s){
	log4cpp::Category &cate=getlogCate();
	s=s+" "+msg;
	cate.warn(s.c_str());
};

void MyLog::error(const char *  msg,string s){
	
	log4cpp::Category &cate=getlogCate();
	s=s+" "+msg;
	cate.error(s);

};
void MyLog::debug(const char * msg,string s){
	log4cpp::Category &cate=getlogCate();
	s=s+" "+msg;
	cate.debug(s);

};
void MyLog::info(const char * msg,string s){
	log4cpp::Category &cate=getlogCate();
	s=s+" "+msg;
	cate.info(s);

};
int main(){
	MyLog *m1=MyLog::getInstance();
	m1->debug("this is a debug msg",DEBUGARG);
	m1->info("This is a info msg",DEBUGARG);
    m1->error("This is a error msg",DEBUGARG);
	m1->warn("This is a warn msg",DEBUGARG);
	m1->destroy();
	return 0;
}
