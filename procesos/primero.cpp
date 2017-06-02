#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

printf("hola mundo");
printf("Mi ID es %d, el ID de mi padre es %d \n", getpid(), getppid());
fork();

}

