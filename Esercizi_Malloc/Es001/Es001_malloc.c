#include<stdio.h>
#include<stdlib.h>




void main(){
  float *p;
  int n;
  int k;

  printf("Inserisci la dimensione del vettore :\n");
  scanf("%d", &n);

  p=(float*)malloc(n*sizeof(float));  //Calcola la dimensione del float e gli indica la prima cella libera
  for(k=0; k<n; k++){
    printf("Inserisci valore all' interno del vettore in posizione %d :\n", k);
    scanf("%f", &num);
    *(p+k)= num;
  }
  for(k=0; k<n; k++){
    printf("%.2f\n", *(p+k));  //L' asterisco deferenzia l' indirizzo
  }
}
