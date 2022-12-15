/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>


typedef struct node {
    int valore;
    struct node *next;
} Node;

/*
 * per creare una funzuone che modifichi una lista
 * defo passare una variabile per referenza la passo con due asterischi
 * element
 */

/*
 *
 */


void dealloca(Node *list){  //giusto credododododoodo
    Node* temp;
    while(list != NULL){
        temp = list;
        list = list->next;
        free(temp);

    }
}

void insertEl(Node **head, Node *element){
    //HEAD è il puntatore alla testa della lista, il puntatore all'inizio della lista in questo
    //caso è "*head" quindi *head è prprio la testa
    /*
     *
     */
    Node *list = *head, *prev = NULL;

    while(list != NULL){
        if(element->valore <= list->valore)
            break;
        prev = list;
        list = list->next;
    }
    if(prev == NULL){
        *head = element;
    }else{
        prev->next = element;
    }
    element->next = list;

}



void stampa(Node *lista){
    Node *l;
    l = lista;  //l è una variabile di appoggio
    printf("numeri  inseriti: \n");
    while (l != NULL) {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;  //al puntatore viene assegnato valore di l->next, se è null finisce il ciclo
    }
    printf("\n");
}
int lunghezza(Node *lista){
    int cont = 0;
    Node *l;
    l = lista;
    while (l != NULL){
        l = l->next;
        cont++;
    }

    return cont;
}

void stampaRicorsiva(Node *l){
    printf("%d - %p \n", l->valore, l->next);
    if(l->next != NULL){
        stampaRicorsiva(l->next);
    }
}

int lunghezzaRicorsiva(Node *l){
    if(l != NULL){
        return lunghezzaRicorsiva(l->next) + 1;
    } else{
        return 0;
    }
}

void insertHead(Node **head, int newValore){
    Node *newTesta = (Node *) malloc(sizeof(Node));

    newTesta->valore = newValore;  //carico nuovo valore new node nuovo
    newTesta->next = (*head);      //il next punta alla testa attuale
    (*head) = newTesta;            //assegno la nuova testa
}


int main() {
    int n;
    int contN = 0;
    Node *lista;
    Node *l;
    lista = NULL;

    do {
        printf("Inserisci  un  naturale o  -1 per  terminare\n");
        scanf("%d", &n);

        if (n >= 0) {
            if (lista == NULL) //  prima  iterazione
            {
                lista = (Node *) malloc(sizeof(Node));
                l = lista; //puntatore d'appogggio l che punta a lista
            } else // iterazioni  successive
                /*{*/{

                    l->next = (Node *) malloc(sizeof(Node));
                    l = l->next;
                //}*/
                /*
                l->valore = n;
                l->next = NULL;
                 */
                insertEl(lista, n);}
        }

    } while (n >= 0);

    insertHead(lista, 4);
    stampa(lista);
    insertEl(lista, 5);


    //conta elementi in lista
    contN = lunghezza(lista);
    printf("\nci sono %d elementi", contN);
    /*
     * fare una funzione che data una head faccia la free di tutti gli elementi
     */


    return 0;
}