 ///
 /// @file    TextQuery.cc
 /// @author  cgy(cgy@qq.com)
 /// @date    2018-04-25 14:39:51
 ///
 
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <set>
using namespace std;

class TextQuery
{
	public:
		void readFile(const string filename);
		void query(const string &world);
	private:
		map<string,map<int,string>> _wordLine;
};

void TextQuery::readFile(const string filename)
{
	ifstream ifs(filename);
	if(!ifs){
		cout<<"failed to open"<<filename<<endl;
	}
	int linenum=1;
	for(string line;getline(ifs,line);++linenum){
		string c=line;
		string world;
		istringstream input(line);
		while(input>>world){
			auto it=_wordLine.find(world);
			if(it!=_wordLine.end()){
				it->second.insert(make_pair(linenum,c));	
			}else{
				map<int,string>temp={{linenum,c}};
				_wordLine.insert(make_pair(world,temp));
			}
		}
	}
	ifs.close();
}

void TextQuery::query(const string &world)
{
	auto it=_wordLine.find(world);
	if(it!=_wordLine.end())
	{
		cout<<world<<" occurs "<<it->second.size()<<" times "<<endl;
		for(auto it2=it->second.begin();it2!=it->second.end();++it2)
		{
			cout<<'\t'<<"line("<<it2->first<<")  "<<it2->second<<endl;
		}
	}
	else
	{
		cout<<"本文没有你要找的"<<world<<endl;
	}
}
int main(void)
{
	string query("in");
	TextQuery tq;
	tq.readFile("china_daily.txt");
	tq.query(query);
	return 0;
}
