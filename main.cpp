#include <queue>
#include "gestor_class.cpp"

int main(int argc, char const *argv[]) {
  Proceso proceso;
  std::vector<std::string*> prioridad;
  std::string args = "1234";
  int ascendente_descendente = 0;
  std::string* data_pila;
  int chanels = 1;
  int TProcesamiento, Tareas = 1;



  std::cout << "Tipo de procesamiento\n"
            << "1. Monoproceso\n"
            << "2. Multiproceso"
  << std::endl;
  std::cin >> TProcesamiento;
  while (TProcesamiento != 1 && TProcesamiento !=2) {
    std::cout << "No existe su opción, introduzca otra: " << std::endl;
    std::cin >> TProcesamiento;
  }
if ( TProcesamiento == 2 ) {
  std::cout << "Número de canales: " << std::endl;
  std::cin >> chanels;
  while( chanels < 1 ){
    std::cout << "Opción inválida, ingrese otro número: " << std::endl;
    std::cin >> chanels;
  }
}
//
// std::cout << "\nTareas\n"
//           << "1. Monotarea\n"
//           << "2. Multitarea"
// << std::endl;
// std::cin >> Tareas;
// while ( Tareas != 1 && Tareas != 2 ) {
//   std::cout << "Su opción es inválida, intente otra vez" << std::endl;
//   std::cin >> Tareas;
// }
  std::cout << "     Menu  \n"
            << " Selecciona el orden de prioridad: \n"
            << " 1. PID \n"
            << " 2. Tiempo de ejecución\n"
            << " 3. Prioridad "
  << std::endl;
  std::cout << "( 1, 2, 3 ): ";
  std::cin >> args;
  data_pila = new std::string[2];
  data_pila[ 0 ] = "Llegada";
  data_pila[ 1 ] = "Ascendente";
  prioridad.push_back( data_pila );

  for( auto item : args ){
    data_pila = new std::string[2];
    switch ( item ) {
      case ( '1' ):
        data_pila[ 0 ] = "PID";
      break;
      case ( '2' ):
        data_pila[ 0 ] = "Ejecucion";
      break;
      case ( '3' ):
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
    prioridad.push_back( data_pila );
  }


  Gestor miGestorEspecial( prioridad, chanels, TProcesamiento, Tareas );

  std::vector<Proceso> dataLoad;
  Proceso buffer[] = {
    Proceso( 2, 0, 0, "Chrome" ),
    Proceso( 1, 0, 0, "Filezilla" ),
    Proceso( 8, 0, 0, "Spotify" ),
    Proceso( 6, 4, 1, "UTorrent" ),
    Proceso( 3, 2, 1, "Zelda" ),
    Proceso( 4, 1, 5, "Netflix" )
  };
  dataLoad.assign( buffer, buffer+(std::size(buffer)) );
  miGestorEspecial.loadData( dataLoad );
  miGestorEspecial.showInitProcess( );
  std::cout << "Procesos: " << '\n';
  int cont_channel = 1;
  for( auto item : dataLoad ){
    while( cont_channel <= chanels ){
      miGestorEspecial.merge( miGestorEspecial.getInitProcess().getToVector( miGestorEspecial.getInitProcess() ) );
      cont_channel++;
    }
    cont_channel = 1;
    miGestorEspecial.showLastProcess();
  }
  return 0;
}
