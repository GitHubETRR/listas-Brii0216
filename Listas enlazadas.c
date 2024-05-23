#include <stdio.h>
#include <stdlib.h>
#define MAX_AL 30
#define SALIR 3
typedef struct pais{
    char Nombre[30];
    char Capital[40];
    struct pais *next;
}pais_t; 

pais_t * mundo=NULL;
void menu(void);
void imprimir_pais(pais_t);
void pedir_datos(pais_t * pais);
void ver_lista(void);
void cargar_pais(void);
void liberar_memoria(void);

int main(){
    menu();
    liberar_memoria;
    return 0;
}

void imprimir_pais(pais_t pais){
    printf("------------------\n");
    printf("Nombre: %s\n",pais.Nombre);
    printf("Capital: %s\n",pais.Capital);
    printf("------------------\n");

}
void pedir_datos(pais_t * pais){
    printf("ingrese el nombre de su pais:\n");
    scanf(" %[^\n]%*c",pais->Nombre);
    printf("ingrese la capital del pais:\n");
    scanf(" %[^\n]%*c",&(pais->Capital));
    while(getchar() != '\n');
}

void menu(void){
    int opcion;
    do{
        printf("1_Cargar un nuevo pais\n");
        printf("2_Ver todos los paises cargados\n");
        printf("3_Salir\n");
        scanf("%d",&opcion);
        if(opcion==1)cargar_pais();
        if(opcion==2)ver_lista();
    }while(opcion!=SALIR);
    
}

void cargar_pais(){
    pais_t *pais_aux;
    pais_aux=malloc(sizeof(pais_t));
    if(pais_aux==NULL){
        printf("Out of memory\n");
    }else{
        pedir_datos(pais_aux);
        pais_aux->next=mundo;
        mundo=pais_aux;
    }
     
        
}

void ver_lista(void){
    pais_t *lista=mundo;
    while(lista!=NULL){
        imprimir_pais(*lista);
        lista=lista->next;
    }
}
void liberar_memoria(void){
    pais_t *aux=NULL;
    while(mundo!=NULL){
        aux=mundo;
        mundo=mundo->next;
        free(aux);

    }
    
}

