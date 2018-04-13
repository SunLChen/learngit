 ///
 /// @file    worldCount.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-13 02:06:14
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int main(){
	map<string,int> world;
	map<string,int>::iterator it;
	string filename("The_Holy_Bible.txt");
	ifstream ifs(filename);
	if(!ifs){
		cout<<filename<<"isn't opened!!"<<endl;
		return -1;
	}
	string temp;
	while(ifs>>temp){
		if(world.size()==0){
			world.insert(pair<string,int>(temp,1));
		}else{
			it=world.find(temp);
			if(it!=world.end()){
				it->second++;
			}else{
				world.insert(pair<string,int>(temp,1));
			}
		}
	}
	for(it=world.begin();it!=world.end();it++){
		cout<<it->first<<"  "<<it->second<<endl;
	}
	return 0;
}
