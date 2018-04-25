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
#include<stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <regex>

using namespace tinyxml2;
using namespace std;
typedef struct RssItem
{
	string title;
	string link;
	string description;
	string content;
}R;

class RssReader
{
	public:
		RssReader()
		{
			_rss.reserve(1000);
		};
		void parseRss();//解析
		void dump();//输出
	private:
		vector<R> _rss;
};
void RssReader::dump(){
	XMLDocument doc;
	int i=1;
	char num[10]={0};
	for(R r:_rss){
	sprintf(num,"%d",i);
	XMLElement *el_doc=doc.NewElement("doc");
	doc.InsertEndChild(el_doc);

//	root->InsertEndChild(el_doc);
	//docid
	XMLElement * el_docid=doc.NewElement("docid");
	XMLText * genderText=doc.NewText(num);
	el_docid->InsertEndChild(genderText);
	el_doc->InsertEndChild(el_docid);
	
	//title
	XMLElement *el_title=doc.NewElement("title");
	genderText=doc.NewText(r.title.c_str());
	el_title->InsertEndChild(genderText);
	el_doc->InsertEndChild(el_title);
	
	//link
	XMLElement *el_link=doc.NewElement("link");
	genderText=doc.NewText(r.link.c_str());
	el_link->InsertEndChild(genderText);
	el_doc->InsertEndChild(el_link);
	
	//content
	XMLElement *el_content=doc.NewElement("content");
	genderText=doc.NewText(r.description.c_str());
	el_content->InsertEndChild(genderText);
	el_doc->InsertEndChild(el_content);	
	++i;
	}
	doc.SaveFile("pagelib.dat");
}

void RssReader::parseRss(){
	XMLDocument doc;
	string title;
	if(!doc.LoadFile("36kr.xml")){
		XMLElement *el_root=doc.FirstChildElement("rss");
		cout<<"el_root"<<el_root<<endl;
		if(el_root){
			XMLElement *el_channel=el_root->FirstChildElement();
			cout<<"el_channel"<<el_channel<<endl;
			if(el_channel){
				XMLElement *el_title=el_channel->FirstChildElement("title");
				XMLElement *el_item=el_channel->FirstChildElement("item");
				cout<<"item"<<el_item<<endl;
				while(el_item){
					R r;
					el_title=el_item->FirstChildElement("title");
					if(el_title){
						r.title=title+el_title->GetText();
					}
					XMLElement * el_link=el_title->NextSiblingElement("link");
					if(el_link){
						r.link=el_link->GetText();
					}
					XMLElement * el_description=el_title->NextSiblingElement("description");
					if(el_description){
						string s=el_description->GetText();
						std::regex e("(&amp;nbsp;)|<(\\S*?)[^>]*>.*?|<.*? />");

						std::regex_replace(std::back_inserter(r.description),s.begin(),s.end(),e,"");		
					}
					XMLElement * el_content=el_title->NextSiblingElement("content");
					if(el_content){
						r.content=el_content->GetText();
					}
					el_item=el_item->NextSiblingElement("item");
					_rss.push_back(r);
				}
			}

		}
	}
	
}
int main(){
//	test0();
	RssReader r;
	r.parseRss();
	r.dump();
	return 0;

}
