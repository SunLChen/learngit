 ///
 /// @file    testxml.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-22 12:26:48
 ///
#include "tinyxml2.h"
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

using namespace tinyxml2;
using namespace std;
struct RssItem
{
	string title;
	string link;
	string description;
	string content;
};

class RssReader
{
	public:
		RssReader();
		void parseRss();//解析
		void dump();//输出
	private:
		vector<RssItem> _rss;
};

void test0(){
	XMLDocument doc;
	string title;
	if(!doc.LoadFile("36kr.xml")){
		XMLPrinter streamer(0,false);
	//	doc.Print(&streamer);
		//-----------------------解析
		XMLElement *el_root=doc.FirstChildElement("rss");
		cout<<"el_root"<<el_root<<endl;
		if(el_root){
			XMLElement *el_channel=el_root->FirstChildElement();
			cout<<"el_channel"<<el_channel<<endl;
			if(el_channel){
				XMLElement *el_title=el_channel->FirstChildElement("title");
				while(el_title){
					title=title+el_title->GetText();
					title+='\n';	
					el_title=el_title->NextSiblingElement("title");
				}
				XMLElement *el_item=el_channel->FirstChildElement("item");
				cout<<"item"<<el_item<<endl;
				while(el_item){
					el_title=el_item->FirstChildElement("title");
					while(el_title){
						title=title+el_title->GetText();
						title+='\n';	
						el_title=el_title->NextSiblingElement("title");
					}
					el_item=el_item->NextSiblingElement("item");
				}
			}

		}
		cout<<title<<endl;
	}
	
}
int main(){
	test0();
	return 0;

}
