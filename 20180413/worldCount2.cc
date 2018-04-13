 ///
 /// @file    worldCount.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-13 02:06:14
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

class world{
	public:
		world(const string & str)
		:name(str)
		,count(1)
		{};
	public:
		string name;
		int count;
};
typedef struct Node{
	world *w;
	struct Node *next;
}node,*pnode;

int main(void){
	pnode phead=NULL;
	pnode pcur=NULL;
	pnode ptemp=NULL;
	string filename("The_Holy_Bible.txt");
//	string filename("file");
	ifstream ifs(filename);
	if(!ifs){
		cout<<filename<<"isn't opened!!"<<endl;
		return -1;
	}
	string temp;
	bool flag=false;
	int i=0;
	while(ifs>>temp){
//		cout<<temp<<endl;
		flag=false;
		i++;
	//	std::getline(temp,ifs," ");
		if(phead==NULL){
			phead=(pnode)malloc(sizeof(node));
            phead->w=new world(temp);
			pcur=phead;
			pcur->next=NULL;
//			i++;
		}else{
			ptemp=phead;
			for(;ptemp!=NULL;){
				if((temp.compare(ptemp->w->name))==0){
				//	cout<<temp<<"=="<<ptemp->w->name<<endl;
					ptemp->w->count++;
					flag=true;
					break;
				}
				ptemp=ptemp->next;
			}
			if(!flag){
			//	cout<<temp<<endl;
				pcur->next=(pnode)malloc(sizeof(node));
			    pcur->next->w=new world(temp);
		     	pcur=pcur->next;
	//	    	i++;
			    pcur->next=NULL;
		 //   	flag=false;
			}
	
		}
	}
	cout<<i<<endl;
	ptemp=phead;
	while(ptemp!=NULL){
		cout<<ptemp->w->name<<"  "<<ptemp->w->count<<endl;
		ptemp=ptemp->next;
	}
	ifs.close();
	return 0;
}
