#include "proceso_header.h"

Proceso::Proceso( ): Proceso( -1, 0, 0, "" ){ }

Proceso::Proceso( int PID, int arrival, int time, std::string name ){
  this -> PID = PID;
  this -> name = name;
  priority = 0;
  father = NULL;
  user = "";
  this -> arrival = arrival;
  this -> time = time;
  this -> time_cont = time;
}

void Proceso::setPID( int PID ){ this -> PID = PID; }
void Proceso::setName( std::string name ){ this -> name = name; }
void Proceso::setPriority( int priority ){ this -> priority = priority; }
void Proceso::setFather( Proceso * father ){ this -> father = father; }
void Proceso::setUser( std::string user ){ this -> user = user; }
void Proceso::setTime( int time ){ this -> time = time; }
void Proceso::setArrival( int arrival ){ this -> arrival = arrival; }

int Proceso::getPID(  ){return PID;}
std::string Proceso::getName(  ){return name;}
int Proceso::getPriority(  ){return priority;}
Proceso* Proceso::getFather(  ){return father;}
std::string Proceso::getUser(  ){return user;}
int Proceso::getTime( ){ return time; }
int Proceso::getArrival( ){ return arrival;}
void Proceso::minusTime( ){ time_cont--; }

bool Proceso::operator!=( Proceso data ){
  return this -> getPID( ) != data.getPID();
}

std::ostream& operator<<(std::ostream& os, Proceso& obj){
    os << obj.getPID() << " "<< obj.getName() << " "<< obj.getArrival() << " "<< obj.getTime() << " "<<obj.getPriority() << " "<< obj.getFather() << " " << obj.getUser() << std::endl;
    return os;
}

void Proceso::show( ){
  std::cout << this -> getPID() << " "<< this -> getName() << " "<< this -> getArrival() << " "<< this -> getTime() << " "<<this -> getPriority() << " "<< this -> getFather() << " " << this -> getUser() << std::endl;
}

 bool ascendentePID( const Proceso& lhs, const Proceso& rhs ){
   return lhs.PID < rhs.PID ;
 }
 bool ascendentePriority( const Proceso& lhs, const Proceso& rhs ){
   return lhs.priority < rhs.priority ;
 }
 bool ascendenteArrival( const Proceso& lhs, const Proceso& rhs ){
   return lhs.arrival < rhs.arrival ;
 }
 bool ascendenteTime( const Proceso& lhs, const Proceso& rhs ){
   return lhs.time < rhs.time ;
 }

 bool descendentePID( const Proceso& lhs, const Proceso& rhs ){
   return lhs.PID > rhs.PID ;
 }
 bool descendentePriority( const Proceso& lhs, const Proceso& rhs ){
   return lhs.priority > rhs.priority ;
 }
 bool descendenteArrival( const Proceso& lhs, const Proceso& rhs ){
   return lhs.arrival > rhs.arrival ;
 }
 bool descendenteTime( const Proceso& lhs, const Proceso& rhs ){
   return lhs.time > rhs.time ;
 }
