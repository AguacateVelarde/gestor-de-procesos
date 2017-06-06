#include "proceso_class.cpp"
class NodoL{
  private:
    NodoL *next;
    Proceso data;
  public:
    NodoL( void );
    NodoL ( Proceso );
    void setNext( NodoL* );
    void setData( Proceso );

    NodoL* getNext( void );
    Proceso getData( void );
};

class Lista{
  public:
    Lista( void );
    void appen( Proceso );
    NodoL* rm( Proceso );
    NodoL* getRoot( void );

    void show( void );
    int size( void );

    std::vector<Proceso> group( std::string, std::string, std::vector<Proceso> );
    std::vector<Proceso> getToVector( Lista );


    NodoL* search( Proceso );

  private:
    NodoL* root;

    NodoL* search( std::string ); // Busca con el nombre
    NodoL* search( int ); // Busca con el PID


    NodoL* searchBefore( Proceso );

};
