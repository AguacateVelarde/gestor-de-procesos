#include "gestor_header.h"

Gestor::Gestor( auto priority, int chanels, int TProcesamiento, int tasks ){
  this -> priority = priority;
  this -> chanels = chanels;
  this -> TProcesamiento = TProcesamiento;
  this -> tasks = tasks;
}

void Gestor::loadData( std::vector<Proceso> data ){
  //std::cout << "Size: " << int( data.size() ) <<  '\n';
  for ( auto item : data ){
     add( item );
  }
  //initProcess.show();
}

void Gestor::showInitProcess(){

}
void Gestor::showLastProcess(){
   initProcess.show();
}

void Gestor::add( auto data ){
  initProcess.appen( data );

}
