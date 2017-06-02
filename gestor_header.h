#include "vector"
#include "lista_class.cpp"

class Gestor{
private:
  Lista initProcess;
  Lista lastProcess;
  std::vector<std::string*> priority;
  int TProcesamiento;
  int chanels;
  int tasks;

public:
  Gestor( auto, int, int, int );
  void loadData(  std::vector<Proceso> data );

  void showInitProcess();
  void showLastProcess();

  void add( auto );








};
