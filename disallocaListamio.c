/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 20

typedef char String[LUNG];

typedef struct  node
{
    String nome;
    int  valore;
    struct  node* next;
}Node;

Node* ultimoInd(Node *list){
    Node *prec;

    while(list->next != NULL){

        prec = list;
        list = list->next;
        //free( ultimoInd(list->next));

    }
    if(prec->next == NULL){
        free(prec);
        return NULL;
    }

    return prec;
}

void inserisci(Node *list){
    Node *l, *temp;
    String nome;
    int valore;
    int esci = -1;
    while(list->next != NULL && esci == -1){
        printf("inserirsci il nome del gioco: ");
        scanf("%s", nome);
        do{
            printf("inserisci il valore: ");
            scanf("%d", &valore);
        }while(valore < 0);
        if(list == NULL){ //solo prima iterazione
            list = (Node*)malloc(sizeof(Node));
            list->valore = valore;
            strcpy(list->nome, nome);

        }else{
            /*
             * l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
             */
            if(list->valore > valore){
                l = list;
                l->next = (Node*)malloc(sizeof(Node));
                l = l->next;
            }else{

            }

            l->valore = valore;
            strcpy(list->nome, nome);


        }
    }
}

void disalloca(Node *list) {
    bool appost = false;
    Node *temp;
    while (!appost) {
        temp = ultimoInd(list);
        if (temp != NULL) {
            free(temp->next);
            temp->next = NULL;
        } else {
            appost = !appost;

        }
    }
}


int  main()
{
    int n;
    Node* lista;
    Node* l;
    String temp;
    lista=NULL;

    do
    {
        printf("Inserisci un nome e un  naturale o  -1 per  terminare\n");

        scanf("%s %d",temp, &n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima  iterazione  */
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni  successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            strcpy(lista->nome, temp);
            l->next = NULL;
        }
    } while (n>=0);

    l=lista;
    printf("numeri  inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next;
    }
    disalloca(lista);
    printf("\ndovrebbe essere stato tutto disallocato correttamente");
    printf("\n");



    return  0;
}
