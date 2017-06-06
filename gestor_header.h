#include "vector"
#include "lista_class.cpp"

class Gestor{
private:
  Lista initProcess;
  Lista lastProcess;
  Lista buffer_chanels;
  int priority_cont;
  std::vector<std::string*> priority;
  int TProcesamiento;
  int chanels;
  int tasks;
  std::vector<std::vector<bool>> timeChanels;

public:
  Gestor( auto, int, int, int );
  void loadData(  std::vector<Proceso> data );

  Lista getInitProcess( void );

  void showInitProcess( void );
  void showLastProcess( void );

  void add( auto );
  int merge( std::vector<Proceso> );











};
