 ///
 /// @file    mapWorld.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-24 20:16:37
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <map>
using namespace std;
class World{
	public:
		World(){};
		~World(){};
		void read(string );
		void save(string );
	private:
		map <string,int> _world;
};

void World::read(string filename){
	ifstream ifs(filename);
	map<string,int>::iterator it;
	if(!ifs){
		cout<<filename<<"isn't opened!"<<endl;
		return;
	}
	string temp;
	while(ifs>>temp){
		it=_world.find(temp);
		if(it!=_world.end())
			++it->second;
		else
			_world.insert(make_pair(temp,1));
	}
	ifs.close();
}

void World::save(string filename){
	ofstream ofs(filename);
	for(auto &temp:_world){
		ofs<<temp.first<<"  "<<temp.second<<endl;
	}
	ofs.close();
}

int main(){
	World w;
	w.read("The_Holy_Bible.txt");
	w.save("world_count.dat");
	return 0;
}
