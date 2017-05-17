#include <iostream>
using namespace std;
class Myclass{
	private:
		int *px;
	public:
		Myclass(int *t)
		{
			px=t;
		}
		void Print()
		{
			cout<<*px<<endl;
		}
};
int main (void)
{
	int x=3;
	Myclass my(&x);
	my.Print();
}

