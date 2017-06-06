#include "gestor_header.h"

Gestor::Gestor( auto priority, int chanels, int TProcesamiento, int tasks ){
  this -> priority = priority;
  this -> chanels = chanels;
  this -> TProcesamiento = TProcesamiento;
  this -> tasks = tasks;
  this -> priority_cont = 1;

}

void Gestor::loadData( std::vector<Proceso> data ){
  //std::cout << "Size: " << int( data.size() ) <<  '\n';
  for ( auto item : data ){
     add( item );
  }
  //initProcess.show();
}

void Gestor::showInitProcess(){
  initProcess.show();
}
void Gestor::showLastProcess(){
   lastProcess.show();
}

void Gestor::add( auto data ){
  initProcess.appen( data );

}

Lista Gestor::getInitProcess(){
  return initProcess;
}
int Gestor::merge( std::vector<Proceso> buffer ){
  std::string* param;
  std::vector<Proceso> resultado = buffer;

  while( resultado.size() > 1 && priority_cont < 4  ){
    param = ( priority[ priority_cont ] );
    resultado = initProcess.group( param[ 0 ], param[ 1 ], resultado );
    priority_cont++;
  }
  priority_cont = 0;
  lastProcess.appen( resultado[ 0 ] );
  initProcess.rm( resultado[ 0 ] );

  //showLastProcess();
}
