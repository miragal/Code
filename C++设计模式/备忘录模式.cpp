#include <iostream>
#include <string>
#include "D:\C++\Memo.h"
using namespace std;

void Originator::setState(string s){
	this->state=s;
}

Memento * Originator::CreateMemento(){
	return new Memento(this->state);
}

void Originator::RestoreMemento(Memento *m){
	this->state=m->getState();
}

void Originator::show(){
	cout<<"×´Ì¬£º"<<state<<endl;
}

Memento::Memento(string s){
	this->state=s;
}

string Memento::getState(){
	return this->state;
}

void CareTaker::setMemento(Memento *m){
	this->memo=m; 
} 

Memento * CareTaker::getMemento(){
	return memo;
} 

int main (void)
{
	Originator *po=new Originator();
	po->setState("ON");
	po->show();
	CareTaker *pc=new CareTaker();
	pc->setMemento(po->CreateMemento());
	po->setState("OFF");
	po->show();
	po->RestoreMemento(pc->getMemento());
	po->show();
	delete pc;
	delete po;
}
