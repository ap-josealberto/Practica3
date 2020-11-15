#include "APJA_2020640581.h"

int main(){
    Nodo *top;
    top=NULL;
    char origen[20] = "autos.txt";
    top = leerArchivo(origen);
    mostrar(top);
    acomodar(top);
    printf("\n\n\n");
    mostrar(top);

    /*top = insertInicial(top, 2);
    top = insertInicial(top, 1);
    top = insertFinal(top,5);
    top = insertFinal(top,6);
    top = insertFinal(top,7);
    top = insertPosicion(top, 3,3);
    top = insertPosicion(top, 4,4);
    top = borrarInicio(top);
    top = borrarFinal(top);
    mostrar(top);
    printf("\n");
    mostrarAlRevez(top);
    top = borrarPosicion(top, 2);
    printf("\n");
    mostrar(top);
    printf("\n");
    mostrarAlRevez(top);
    printf("\n");
    top = intercambiar(top,4,10);
    mostrar(top);
    printf("\n");
    mostrarAlRevez(top);
    top = intercambiarAlReves(top,6,20);
    printf("\n");
    mostrar(top);
    printf("\n");
    mostrarAlRevez(top);
    */

    return 0;
}
