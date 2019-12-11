#include <stdio.h>
#include <stdlib.h>


struct El
{
 int valore;
 struct El* next;
};

void deallocaLista(struct El*l){

}

void stampaListaRicorsiva(struct El* l){
        printf("%d\n", l->valore);
        l=l->next;  //Aggiorno l'indirizzo passando il prossimo indirizzo
        stampaListaRicorsiva(l); //Autoreferenziata in modo che scorra fino a quando la if non diventa falsa
}


int LungIterativa(struct El* l){
    int cont = 0;
    while (l!=NULL){
            l=l->next;
            cont++;
    }
    return cont;
}

int LungRicorsiva(struct El* l){
    int cont = 0;
    if(l!=NULL){
        l=l->next;
        cont =  LungRicorsiva(l)  ; //Richaimo la funzione fino al falso della condizione if e conto la lunghezza
    }
    return cont;
}



void stampaListaIterativa(struct El* l) {
  while (l!=NULL){
    printf("%d - %p \n",l->valore, l->next);
    l=l->next; /* il puntatore corrente è assegnato al puntatore all'elemento successivo */
  }
}

int main()
{
 int n;
 struct El* lista;
 struct El* l;
 lista=NULL; //Inizialmete la lista viene inizializzata a NULL

 do
 {
 printf("Inserisci un naturale o -1 per terminare\n");
 scanf("%d",&n);
 if (n>=0)
 {
 if (lista==NULL) //Si effettua un controllo su "list", si verifica se è uguale o meno a NULL
 {
 //Se "list" risulta uguale a NULL, allora si carica il primo indirizzo libero per caricare la struttura, e si alloca in memoria la dimensione di quest' ultima
 lista = (struct El*) malloc(sizeof(struct El));
 l = lista;
 }
 else //Se "list" non è uguale a NULL, cioè non è vuota
 {
 //Viene assegnato l' indirizzo della prima cella della struttura successiva all' interno del campo "next" di "l" e vine allocato lo spazio in memoria della dimesione della struttura
 l->next = (struct El*) malloc(sizeof(struct El));
 l = l->next;
 }
 l->valore = n; //Viene inserito il valore di "n" all' interno del campo "valore" di "l"
 l->next = NULL; //Viene ripulito il campo "next" di "l" assegnandogli il valore NULL
 }
 } while (n>=0);

 l=lista; //Si assegna a "l" il contenuto della variabile "lista"
 printf("numeri inseriti: ");
 while (l!=NULL)
 {
 printf("%d - %p \n",l->valore, l->next);
 l=l->next; //Si assegna a "l" il valore del campo "next" di "l"
 }
 printf("\n");
 return 0;
 }
