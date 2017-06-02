#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int data = fork();
  if( !data ){
    printf("Soy el proceso hijo, id %d\n", getpid());
    printf("El id de mi padre es: %d\n", getppid() );
  }else if( data < 0)
    printf(" Error\n" );
  else{
    printf("Soy el proceso padre, id %d\n", getpid());
    printf("El id de mi padre es: %d\n",getppid() );
  }
  return 0;
}
