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
    int time_cont;

  public:
    Proceso( void );
    Proceso( int, int, int, std::string );
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
    void minusTime( void ); //Reduce la tiempo cada ciclo

    friend bool ascendentePID( const Proceso&, const Proceso& );
    friend bool ascendentePriority( const Proceso&, const Proceso& );
    friend bool ascendenteArrival( const Proceso&, const Proceso& );
    friend bool ascendenteTime( const Proceso&, const Proceso& );

    friend bool descendentePID( const Proceso&, const Proceso& );
    friend bool descendentePriority( const Proceso&, const Proceso& );
    friend bool descendenteArrival( const Proceso&, const Proceso& );
    friend bool descendenteTime( const Proceso&, const Proceso& );
};
