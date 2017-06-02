#include <queue>
#include "gestor_class.cpp"

int main(int argc, char const *argv[]) {
  Proceso proceso;
  std::vector<std::string*> prioridad;
  std::string args = "1234";
  int ascendente_descendente = 0;
  std::string* data_pila;
  int chanels = 1;
  int TProcesamiento, Tareas;



  std::cout << "Tipo de procesamiento\n"
            << "1. Monoproceso\n"
            << "2. Multiproceso\n"
  << std::endl;
  std::cin >> TProcesamiento;
  while (TProcesamiento != 1 && TProcesamiento !=2) {
    std::cout << "No existe su opción, introduzca otra: " << std::endl;
    std::cin >> TProcesamiento;
  }
if ( TProcesamiento == 2) {
  std::cout << "Número de canales: " << std::endl;
  std::cin >> chanels;
  while( chanels < 1 ){
    std::cout << "Opción inválida, ingrese otro número: " << std::endl;
    std::cin >> chanels;
  }
}

std::cout << "\nTareas\n"
          << "1. Monotarea\n"
          << "2. Multitarea\n"
<< std::endl;
std::cin >> Tareas;
while ( Tareas != 1 && Tareas != 2 ) {
  std::cout << "Su opción es inválida, intente otra vez" << std::endl;
  std::cin >> Tareas;
}
  std::cout << "     Menu  \n"
            << " Selecciona el orden de prioridad: \n"
            << " 1. PID \n"
            << " 2. Tiempo de llegada \n"
            << " 3. Tiempo de ejecución\n"
            << " 4. Prioridad "
  << std::endl;
  std::cout << "( 1, 2, 3, 4 ): ";
  std::cin >> args;


  for( auto item : args ){
    data_pila = new std::string[2];
    switch ( item ) {
      case ( '1' ):
        data_pila[ 0 ] = "PID";
      break;
      case ( '2' ):
        data_pila[ 0 ] = "Llegada";
      break;
      case ( '3' ):
        data_pila[ 0 ] = "Ejecucion";
      break;
      case ( '4' ):
        data_pila[ 0 ] = "Prioridad";
      break;
    }
    std::cout << "¿Cuál es la prioridad de " << data_pila[ 0 ] <<  "?" << std::endl;
    std::cout << "1. Ascendente\n"
              << "2. Descendente"
    << std::endl;
    std::cin >> ascendente_descendente;
    while( ascendente_descendente != 1 && ascendente_descendente != 2 ){
      std::cout << "No existe esa opción, inserte otra" << std::endl;
      std::cin >> ascendente_descendente;
    }
    if ( ascendente_descendente == 1 ) {
      data_pila[ 1 ] = "Ascendente";
    }else{
      data_pila[ 1 ] = "Descendente";
    }
    //  std::cout << "Data: "<< data_pila[ 0 ] << " Ascendente/descendente: "<< data_pila[ 1 ]<< '\n';
    prioridad.push_back( data_pila );
  }

  //prioridad.push(new std::string[2] { "fg", "sdfgs" });


  Gestor miGestorEspecial( prioridad, chanels, TProcesamiento, Tareas );

  std::vector<Proceso> dataLoad;
  Proceso buffer[] = {
    Proceso( ),
    Proceso( ),
    Proceso( ),
    Proceso( 2, 4, 1 ),
    Proceso( 3, 2, 1 )
  };
  dataLoad.assign( buffer, buffer+(std::size(buffer)) );
  miGestorEspecial.loadData( dataLoad );
  return 0;
}
