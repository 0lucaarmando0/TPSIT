#include<stdio.h>
#include<stdlib.h>
#include<string.h>




#define DIM 20000
#define BUFF 150
#define COMMA ,


typedef struct games{
    int rank;
    char* Name;
    char* platform;
    int year;
    char* genre;
    char* publisher;
    float NA_Sales;
    float EU_Sales;
    float JP_Sales;
    float Other_Sales;
    float Global_Sales;
}Game;


void fillList(Game list[], char file[], int *n){
    FILE*f;
    char buffer[BUFF];
    f=fopen(file, "r");
    if(f==NULL){
        printf("Il file non esiste\n");
    }else{
        while((*n<DIM) && fgets(buffer, BUFF, f)){
          if(*n>0){
            list[*n].rank=atoi(strtok(buffer, "COMMA"));
            list[*n].Name=strtok(NULL, "COMMA");
            list[*n].platform=strtok(NULL, "COMMA");
            list[*n].year=atoi(strtok(NULL, "COMMA"));
            list[*n].genre=strtok(NULL, "COMMA");
            list[*n].publisher=strtok(NULL, "COMMA");
            list[*n].NA_Sales=atof(strtok(NULL, "COMMA"));
            list[*n].EU_Sales=atof(strtok(NULL, "COMMA"));
            list[*n].JP_Sales=atof(strtok(NULL, "COMMA"));
            list[*n].Other_Sales=atof(strtok(NULL, "COMMA"));
            list[*n].Global_Sales=atof(strtok(NULL, "COMMA"));
            *n=*n+1;
          }
        }printf("Ho finito fratelo!\n");
    }
}



void jpGame(Game list[], int n){
    int k;
    int cont=0;
    float max=0;
    printf("c\n");
    for(k=0; k<n; k++){
      printf("c\n");
      if(list[k].JP_Sales>list[k+1].JP_Sales){
        max=list[k].JP_Sales;
        cont=k;
      }
    }printf("The most popular game in Japan is %s", list[cont].Name);

}

void main(){
    int n;
    Game list[DIM];
    char answer;
    char fileName[]="File001.txt";
    fillList(list, fileName, &n);
    printf("Do you wanna know which is the most popular game in Japan?\n");
    scanf("%c", answer);
    printf("%c", answer);
    if(answer=='s' || answer=='S'){
      printf("c\n");
      jpGame(list, n);
    }
}
