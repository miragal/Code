#include <iostream>
#include <string> 
using namespace std;

class Memento;

class Originator{
	private:
		string state;
	public:
		void setState(string s);
		Memento *CreateMemento();
		void RestoreMemento(Memento *m);
		void show();
}; 
 
class Memento{
	private:
		string state;
	 public:
	 	Memento(string s);
	 	string getState();
};

class CareTaker{
	private:
		Memento *memo;
	public:
		void setMemento(Memento *m);
		Memento *getMemento();
}; 
