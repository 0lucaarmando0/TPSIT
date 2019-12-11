#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct El{
    int valore;
    struct El* next;
}El;

bool controlloStringa(char cifra[]);
struct El* pop(struct El** head);
void push(struct El** head, struct El* element);
void stampaPila(struct El** head);

int main(){
    struct El* head;
    struct El* element;
    char cifra[1000];
    do{
        printf("\nInserire il numero:  ");      //richiedo il numero
        fflush(stdin);
        scanf("%s", cifra);
    }while(!controlloStringa(cifra));   //continuo a richiederla finch� non sar� composta solo da cifre
    int i=0;    //contatore per scorrere i caratteri della stringa
    do{
        element = (struct El*) malloc(sizeof(struct El));   //alloco lo spazio necessario al puntatore
        element->valore=cifra[i]-48;    //aggiorno il valore in base a quello della stringa, tolgo 48 per il codice ASCII
        i++;
        push(&head,element);    //aggiungo l'elemento alla mia pila
    }while(cifra[i]!='\0'); //lo ripeto finch� non ho finito di leggere la stringa
    stampaPila(&head);
    return 0;
 }

void push(struct El** head, struct El* element){ //aggiungo l'elemento
	if (*head==NULL){
		*head = element;
		element->next = NULL;
	}else{
		element->next = *head;
		*head = element;
	}
}

struct El* pop(struct El** head){   //tolgo e leggo l'elemento
	struct El *ret = *head;
	if(*head==NULL){
		return NULL;
	}else{
		*head = ret->next;
	}
	return ret;
}

bool controlloStringa(char cifra[]){    //controllo se la stringa � composta solo da cifre
    char numeri[11]="0123456789";
    int i,k;
    bool error=true;
    for(i=0;cifra[i]!='\0';i++){
        for(k=0;k<11;k++){
            if(cifra[i]==numeri[k]){
               error=false;
            }
        }
        if(error!=false){
            return false;
        }else{
            error=true;
        }
    }
    return true;
}

void stampaPila(struct El** head){  //stampo la pila
    struct El *ret;
    int i=1;
    ret=pop(head);
    while(ret!=NULL){   //ripeto finch� ci sono elementi
        printf("\n valore [%d]: %d", i, ret->valore);
        i++;
        free(ret);  //libero lo spazio che ormai non mi serve pi�
        ret=pop(head);  //leggo il prossimo elemento
    }
    return;
}
