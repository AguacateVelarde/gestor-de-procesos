#include "lista_header.h"
#include <algorithm>

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
  NodoL* buffer;
  NodoL* buffer_;

  if( root == NULL ) return nullptr;

  else{
    buffer = this -> search( data );
    buffer_ = this -> searchBefore( data );
    if( buffer == root )
      root = root -> getNext();
    else
    buffer_ -> setNext( buffer -> getNext() );

    return buffer;
  }
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

NodoL* Lista::searchBefore( Proceso _search ){
  auto buffer = root;
  if( buffer -> getData().getPID() == _search.getPID() ) {
      return NULL;
  }
  while ( buffer ->  getNext() -> getData() != _search )
    buffer = buffer -> getNext();

  return ( buffer );
}

NodoL* Lista::search( Proceso _search ){
  auto buffer = root;
  while ( buffer ->  getData() != _search )
    buffer = buffer -> getNext();

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

NodoL* Lista::getRoot(){ return root;}

int Lista::size(){
  auto buffer = root;
  int cont = 0;
  while( buffer != NULL ){
    buffer = buffer -> getNext();
    cont++;
  }
  return cont;
}

std::vector<Proceso> Lista::getToVector( Lista data ){
  std::vector<Proceso> _return;
  auto buffer = data.getRoot();
  while( buffer != NULL ){
    _return.push_back( buffer -> getData() );
    buffer = buffer -> getNext();
  }

  return _return;
}

std::vector<Proceso> Lista::group( std::string data, std::string comparison, std::vector<Proceso> show  ){
  std::vector<Proceso> _return;
  int cont = 0;
  int* sort_integer;
  std::vector<int> buffer;

  if ( data == "Llegada" ) {
    if( comparison =="Ascendente" )
      std::sort( show.begin(), show.end(), ascendenteArrival );
    else
      std::sort( show.begin(), show.end(), descendenteArrival );

    _return.push_back( show[ 0 ] );
    show.erase( show.begin() );
    for( auto item : show ){
      if( item.getArrival() == _return[ 0 ].getArrival() ){
        _return.push_back( item );
      }
    }
  }else if( data == "PID" ){
    if( comparison =="Ascendente" )
      std::sort( show.begin(), show.end(), ascendentePID );
    else
      std::sort( show.begin(), show.end(), descendentePID );

    _return.push_back( show[ 0 ] );
    show.erase( show.begin() );
    for( auto item : show ){
      if( item.getPID() == _return[ 0 ].getPID() ){
        _return.push_back( item );
      }
    }


  }else if( data == "Ejecucion" ){
    if( comparison =="Ascendente" )
      std::sort( show.begin(), show.end(), ascendenteTime );
    else
      std::sort( show.begin(), show.end(), descendenteTime );
    _return.push_back( show[ 0 ] );
    show.erase( show.begin() );
    for( auto item : show ){
      if( item.getTime() == _return[ 0 ].getTime() ){
        _return.push_back( item );
      }
    }
  }else if( data == "Prioridad" ){
    if( comparison =="Ascendente" )
      std::sort( show.begin(), show.end(), descendentePriority );
    else
      std::sort( show.begin(), show.end(), descendentePriority );
    _return.push_back( show[ 0 ] );
    show.erase( show.begin() );
    for( auto item : show ){
      if( item.getPriority() == _return[ 0 ].getPriority() ){
        _return.push_back( item );
      }
    }
  }else{
    std::cout << "Hay un bendito error en el código perro" << '\n';
  }

  return _return;
}
