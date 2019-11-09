#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void main(){
    char string[50];
    bool end = true;
    int cont = -1;
    printf("Inserire la stringa: \n");
    gets(string);

    for(int i=0;end==true;i++){  //Il ciclo continua fino a quando end diventa false
        if(*(string+i)=='\0'){
            end=false; //Assegna "false" ad end e consente di uscire dal ciclo
          }
        cont++;
    }
    printf("La stringa è lunga  %d : ", cont);

}
