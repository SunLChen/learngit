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
struct Node{
	world *w;
	struct Node *next;
}node,*pnode;

int main(){
	vector<world *> wld;
	wld.reserve(80000);
	cout<<wld.capacity()<<endl;
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
		i++;
		if(wld.size()==0){
			wld.push_back(new world(temp));
		}else{
			for(world* &w:wld){
				if((temp.compare(w->name))==0){
					w->count++;
					flag=true;
					break;
				}
			}
			if(!flag){
			//	cout<<temp<<endl;
				wld.push_back(new world(temp));
			}
				flag=false;
		}
	}
	cout<<i<<endl;
	cout<<wld.size()<<endl;
	i=0;
	for(world *w:wld){
		i++;
		cout<<w->name<<"  "<<w->count<<endl;
	}
	cout<<i<<endl;
	return 0;
}
