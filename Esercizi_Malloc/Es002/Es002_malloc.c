#include<stdio.h>
#include<stdlib.h>

void main(){

  float *p;
  int n;
  float num, max;

  do{
      printf("Inserire il numero di numeri : \n");
      scanf("%d", &n);
  }while(n<0);

  p=(float*)malloc(n*sizeof(float));  //alloca lo spazio in memoria e indica l'indirizzo della prima cella libera
  *p = 0;

  for(int k=0; k<n; k++){

      printf("Inserire un numero : \n ");
      scanf("%f", &num);
      *(p+k) = num;  // Aggingo all'indirizzo il valore della k in modo da arrivare al l'indirizzo desiderato e poi inserisco
                          // il valore di num al interno della cella punatata dal nuovo indirizzo sbloccandolo con "*"
  }
  for(int j=0; j<n; j++){

      printf(" Il numero %d e': %.2f \n", j, *(p+j)); //stampo il valore contenuto nella cella punatata da "p+j" sbloccato dell'asterisco

  }

  max=*p;    //do un primo valore al max come il valore massimo
  for(int i=0; i<n; i++){
      if(max<*(p+i)){  //controllo il massimo tra max e la cella contrassegnata dall'indirizzo di p+i
          max=*(p+i);
      }
  }
  printf("Il maggiore è: %.2f \n", max);    //stampo il valore massimo


  free(p);
}
