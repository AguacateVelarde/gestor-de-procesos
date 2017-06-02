#include "lista_header.h"

/*****************
*  Clase NODO    *
*****************/

NodoL::NodoL( ){
  next = NULL;
}
NodoL::NodoL ( Proceso data ){
  next = NULL;
  this -> data = data;
}
void NodoL::setNext( NodoL* next ){ this -> next = next; }
void NodoL::setData( Proceso data ){ this -> data = data; }

NodoL* NodoL::getNext( ){ return next; }
Proceso NodoL::getData( ) {return data; }

/*****************
*  Clase LISTA   *
*****************/

Lista::Lista( ){
    this -> root = NULL;
}
void Lista::appen( Proceso data ){

  if ( root == NULL ) root = new NodoL( data );
  else {
      auto buffer = root;
      while ( buffer -> getNext() != NULL ) buffer = buffer -> getNext();
      buffer -> setNext( new NodoL( data ) );
  }
}
NodoL* Lista::rm( Proceso data ){
  if( root == NULL ) return nullptr;
  else return this -> search( data );

}
NodoL* Lista::search( std::string _search ){
  auto buffer = root;
  while ( buffer -> getData().getName() != _search ) buffer = buffer -> getNext();
  return ( buffer == NULL ? nullptr : buffer );
}
NodoL* Lista::search( int _search ){
  auto buffer = root;
  while ( buffer -> getData().getPID() != _search ) buffer = buffer -> getNext();
  return ( buffer == NULL  ?  new NodoL(  ) :  buffer);
}

NodoL* Lista::search( Proceso _search ){
  auto buffer = root;
  while ( buffer ->  getData() != _search ) buffer = buffer -> getNext();

  return ( buffer );
}

void Lista::show( ){
    auto buffer = root;
        while( buffer != NULL ){
      buffer -> getData(). show();
      buffer = buffer -> getNext();
    }
      std::cout << std::endl;

}
