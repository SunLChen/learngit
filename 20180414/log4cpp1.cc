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
using namespace std;
//添加文件名，与行号

 #define DEBUGFMT  "%s(%d)-%s"
 #define DEBUGARGS __FILE__,__LINE__,__FUNCTION__

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
		log4cpp::Category & getlogRoot(){
			return root;
		}
	    void warn(const char * msg);
		void error(const char * msg);
		void debug(const char * msg);
		void info(const char * msg);
	private:
		MyLog()
		:osAppenderW(new log4cpp::OstreamAppender("osAppenderW",&cout))
		,osAppenderE(new log4cpp::OstreamAppender("osAppenderE",&cout))
		,osAppenderI(new log4cpp::OstreamAppender("osAppenderI",&cout))
		,osAppenderD(new log4cpp::OstreamAppender("osAppenderD",&cout))
		{
			osAppenderW->setLayout(new log4cpp::BasicLayout());
			osAppenderD->setLayout(new log4cpp::BasicLayout());
			osAppenderE->setLayout(new log4cpp::BasicLayout());
			osAppenderI->setLayout(new log4cpp::BasicLayout());
		};
		~MyLog(){
			log4cpp::Category::shutdown();
		};
	private:
		static MyLog *mylog;
		log4cpp::Category &root=log4cpp::Category::getRoot();
	public:
		log4cpp::OstreamAppender *osAppenderW;
		log4cpp::OstreamAppender *osAppenderE;
		log4cpp::OstreamAppender *osAppenderI;
		log4cpp::OstreamAppender *osAppenderD;
		
};
 MyLog * MyLog::mylog=NULL;
inline void MyLog::warn(const char * msg){
	log4cpp::Category &root=getlogRoot();
	log4cpp::Category &w=root.getInstance("w");
	w.addAppender(osAppenderW);
	w.setPriority(log4cpp::Priority::WARN);
	w.warn(msg);


};
void MyLog::error(const char *  msg){
	

	log4cpp::Category &root=getlogRoot();
	log4cpp::Category &e=root.getInstance("e");
	
	e.addAppender(osAppenderE);
	e.setPriority(log4cpp::Priority::ERROR);
	e.error(msg);

};
void MyLog::debug(const char * msg){
	log4cpp::Category &root=getlogRoot();
	log4cpp::Category &d=root.getInstance("d");
	d.addAppender(osAppenderD);
	d.setPriority(log4cpp::Priority::DEBUG);
	d.debug(msg);

};
void MyLog::info(const char * msg){
	log4cpp::Category &root=getlogRoot();
	log4cpp::Category &i=root.getInstance("i");
	i.addAppender(osAppenderI);
	i.setPriority(log4cpp::Priority::INFO);
	i.info(msg);

};

int main(){
	MyLog *m1=MyLog::getInstance();
	m1->debug("this is a debug msg");
	m1->info("This is a info msg");
    m1->error("This is a error msg");
	m1->warn("This is a warn msg");
	m1->destroy();
	return 0;
}
