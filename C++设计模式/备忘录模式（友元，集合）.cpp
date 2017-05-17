#include <iostream>
#include <string> 
#include <vector>
using namespace std;

#include "D:\C++\Memo2.h"

void Originator::setState(string s){
	this->state=s;
}

Memento * Originator::CreateMemento(){
	return new Memento(this->state);
}

void Originator::RestoreMemento(Memento *m){
	this->state=m->state;
}

void Originator::show(){
	cout<<"×´Ì¬£º"<<state<<endl;
}

Memento::Memento(string s){
	this->state=s;
}

void CareTaker::setMemento(Memento *m){
	vec.push_back(m); 
} 

Memento * CareTaker::getMemento(int i){
	return vec[i-1];
} 

int main (void)
{
	Originator *po=new Originator();
	CareTaker *pc=new CareTaker();
	po->setState("ON1");
	po->show();
	pc->setMemento(po->CreateMemento());
	
	po->setState("ON2");
	po->show();
	pc->setMemento(po->CreateMemento());
	
	po->setState("ON3");
	po->show();
	pc->setMemento(po->CreateMemento());
	
	po->RestoreMemento(pc->getMemento(2));
	po->show();
	delete pc;
	delete po;
}
