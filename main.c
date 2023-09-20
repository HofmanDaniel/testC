#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENNAME 21
#define LENCODE 4
#define NSQUAD 3

typedef struct
{
    char name[LENNAME];
    char code[LENCODE];
    int goalTo;
    int goalFrom;
} squad;

int menu()
{
    printf("-------Menu-------\n");
    printf("1) inserire i dati di una squadra\n2) visualizzare i dati\n3) Stampi a video tutti i nomi delle squadre che hanno fatto un numero di goal maggiore del numero dei goal subiti.\n4) Letto un codice di una squadra stampi a video\nN maggiore di 4 per uscire\n>");
    int scelta;
    scanf("%d",&scelta);
    return scelta;
};

void insert(squad squadra[], int selected)
{

    printf("Inserisci il nome della squadra: ");
    scanf("%s", squadra[selected].name);
    fflush(stdin);
    printf("Inserisci il codice della squadra: ");
    scanf("%s", squadra[selected].code);

    printf("Inserisci il numero di goal effettuati della squadra: ");
    scanf("%d", &squadra[selected].goalTo);

    printf("Inserisci il numero di goal subiti della squadra: ");
    scanf("%d", &squadra[selected].goalFrom);
    system("pause");
};

void seeAll(squad squadre[], int registred){
    for(int i=0;i<registred;i++){
        printf("-------squadra%d-------\nNome: %s\nCodice: %s\nGoal effettuati: %d\nGoal subiti: %d\n",i+1,squadre[i].name,squadre[i].code,squadre[i].goalTo,squadre[i].goalFrom);
    }
    system("pause");
}

void seeGoals(squad squadre[], int registred){
    printf("squadre che hanno fatto piu' goal di quelli subiti:\n");
    for(int i=0;i<registred;i++){
        if(squadre[i].goalTo-squadre[i].goalFrom>0){
            printf("%s(%s) %d/%d\n",squadre[i].name,squadre[i].code,squadre[i].goalTo,squadre[i].goalFrom);
        }
    }
    system("pause");
}

void finder(squad squadre[], int registred){
    char codice[LENCODE];
    printf("inserisci il codice della squadra: ");
    scanf("%s", codice);
    for(int i=0;i<registred;i++){
        if(strcmp(codice,squadre[i].code)==0){
            printf("Nome: %s\nCodice: %s\nGoal effettuati: %d\nGoal subiti: %d\n",squadre[i].name,squadre[i].code,squadre[i].goalTo,squadre[i].goalFrom);
        }
    }
    system("pause");
}

int main()
{
    int Nregistrati=0,scelta;
    squad squadre[NSQUAD];

    do
    {
        system("cls");
        scelta=menu();
        switch(scelta)
        {
        case 1:
            if(Nregistrati<NSQUAD){
                insert(squadre, Nregistrati);
                Nregistrati++;
            }
            else{
                printf("Non puoi piu' inserire squadre\n");
            }
            break;
        case 2:
            seeAll(squadre, Nregistrati);
            break;
        case 3:
            seeGoals(squadre, Nregistrati);
            break;
        case 4:
            finder(squadre, Nregistrati);
            break;
        }
    }
    while(scelta<5);

    return 0;
}
