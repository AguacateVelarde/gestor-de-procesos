#include <iostream>

class Proceso{
  private:
    int PID;
    std::string name;
    int priority;
    Proceso *father;
    std::string user;
    int arrival;
    int time;

  public:
    Proceso( void );
    Proceso( int, int, int );
    void setPID( int );
    void setName( std::string );
    void setPriority( int );
    void setFather( Proceso * );
    void setUser( std::string );
    void setArrival( int );
    void setTime( int );

    int getPID( void );
    std::string getName( void );
    int getPriority( void );
    Proceso* getFather( void );
    std::string getUser( void );
    int getArrival( void );
    int getTime( void );


    bool operator!=( Proceso );
    friend std::ostream& operator<<(std::ostream& ,  Proceso&);
    void show( void );

};
