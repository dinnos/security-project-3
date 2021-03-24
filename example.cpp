#include <iostream>

void codificar(char Mensaje[100],int numero);
void decodificar(char Mensaje[100],int numero);
char* ABC = "ABCDEFGHIJKLMN\xa5OPQRSTUVWXYZ";
char* abc = "abcdefghijklm\xa4opqrstuvwxyz";

int main(){
    int n;
    char cadena[100];
    printf("introduce un mensaje: ");
    fflush(stdin);
    fgets(cadena, 100, stdin);
    printf("introduce un numero: ");
    scanf("%d",&n);
    while(getchar()!= '\n' );
    codificar(cadena, n);
    decodificar(cadena,n);
    return 0;
}

void codificar(char Mensaje[100],int numero){
    int i;
    char*p;
    for(i = 0; Mensaje[i]; i++){
        if( p = strchr(ABC, Mensaje[i]) ){
            Mensaje[i] = ABC[(p - ABC + numero) % 27];
        }
        if( p = strchr(abc, Mensaje[i]) ){
            Mensaje[i] = abc[(p - abc + numero) % 27];
        }
    }
    printf("\nEl mensaje codificado es:\n%s\n",Mensaje);
}

void decodificar(char Mensaje[100],int numero){
    char*p;
    int i;
    for(i = 0; Mensaje[i]; i++){
        if( p = strchr(ABC, Mensaje[i]) ){
            Mensaje[i] = ABC[(p - ABC - numero + 27) % 27];
        }
        if( p = strchr(abc, Mensaje[i]) ){
            Mensaje[i] = abc[(p - abc - numero + 27) % 27];
        }

    }
    printf("\nEl mensaje decodificado es:\n%s\n",Mensaje);
}