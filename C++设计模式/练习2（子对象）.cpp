#include <iostream>
using namespace std;
class Myclass{
	private:
		int x,y;
	public:
		Myclass(int x,int y)
		{
			this->x=x;
			this->y=y;
		}
		void Print()
		{
			cout<<"x="<<x<<endl;
			cout<<"y="<<y<<endl;	
		}
}; 

class Yourclass{
	private:
		Myclass *pmy;
	public:
		Yourclass(Myclass *t)
		{
			pmy=t;
		}
		void dofun()
		{
			pmy->Print();
		}
};
int main (void)
{
	Myclass my(3,5);
	Yourclass *pyour=new Yourclass(&my);
	pyour->dofun(); 
	delete pyour;
}
