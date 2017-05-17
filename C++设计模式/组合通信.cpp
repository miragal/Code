#include <iostream>
#include <vector>
using namespace std;

class My{
	private:
		vector <int> vec;
	public:
		void add(int x){
			vec.push_back(x);
		}
		void show(){
			vector <int>:: iterator it;
			for(it=vec.begin();it!=vec.end();it++)
				cout<<(*it)<<endl;
		}
}; 

int main (void)
{
	My my;
	my.add(1);
	my.add(2);
	my.add(3);
	my.add(4);
	my.show();
	return 0;
}
