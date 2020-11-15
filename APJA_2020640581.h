#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct _Nodo {
	char modelo[20], color[10], placa[10];
	struct _Nodo *siguiente;
	struct _Nodo *anterior;
}Nodo;

Nodo *asignarMemoria(char modeloCarro[20], char colorCarro[10], char placaCarro[10] ) {
	Nodo *nuevo;
	nuevo = (Nodo *) malloc(sizeof(Nodo));
	strcpy(nuevo->modelo,modeloCarro);
	strcpy(nuevo->color, colorCarro);
	strcpy(nuevo->placa, placaCarro);
	nuevo -> siguiente = NULL;
	nuevo -> anterior = NULL;

	return nuevo;
}

int contarElementos(Nodo *frente) {
	int c = 0;
	if(frente == NULL) {
		printf("\nLa FILA esta vacia...\n");
	} else {
		while(frente != NULL) {
			frente = frente -> siguiente;
			c++;
		}
	}
	//printf("\nLa longitud de la fILA es de: %d", c);

	return c;
}

Nodo *insertInicial(Nodo *frente,char modeloCarro[20], char colorCarro[10], char placaCarro[10]) {
	Nodo *nuevo;
	nuevo = asignarMemoria(modeloCarro, colorCarro, placaCarro);
	if(frente != NULL) { //
		nuevo -> siguiente = frente;
		frente ->anterior = nuevo;
	}

	return nuevo;
}

Nodo *insertFinal(Nodo *frente, char modeloCarro[20], char colorCarro[10], char placaCarro[10]) {
    Nodo *nuevo;
    Nodo *aux;
    nuevo = asignarMemoria(modeloCarro, colorCarro, placaCarro);
    if(frente == NULL) {
        frente = nuevo;
    } else {
        aux = frente;
        while(aux -> siguiente != NULL) {
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevo;
        nuevo->anterior = aux;
    }

    return frente;
}

Nodo *borrarInicio(Nodo *frente) {
    Nodo *aux;
    aux = frente;
    if(frente != NULL) {
        frente = frente -> siguiente;
        frente -> anterior = NULL;
        free(aux);
    }
    return frente;
}

Nodo *borrarPosicion(Nodo *frente, int pos) {
    Nodo *aux, *aux2, *nuevo;
    int lenght = 0, i;
    lenght = contarElementos(frente);
    if(pos >= 1 && pos <= lenght) {
        if(pos == 1) {
            frente = borrarInicio(frente);
        } else {
            aux = frente;
            for(i = 1 ; i < pos-1 ; i++) {
                aux = aux -> siguiente;
            }
            aux2 = aux ->siguiente;
            nuevo = (aux->siguiente)->siguiente;
            aux->siguiente = (aux->siguiente)->siguiente;
            nuevo ->anterior = aux;
            free(aux2);
        }
    } else {
        printf("Posicion invalida\n");
    }

    return frente;
}

Nodo *borrarFinal(Nodo *frente) {
     Nodo *aux, *aux2;
    int lenght = 0, i;
    lenght = contarElementos(frente);
            aux = frente;
            for(i = 1 ; i < lenght-1 ; i++) {
                aux = aux -> siguiente;
            }
            aux2= aux -> siguiente;
            aux->siguiente = (aux->siguiente)->siguiente;
            free(aux2);
    return frente;
}

// baja en final y en una posicion


Nodo *insertPosicion(Nodo *frente, char modeloCarro[20], char colorCarro[10], char placaCarro[10], int pos) {
    Nodo *nuevo, *aux;
    int lenght = 0, i;
    lenght = contarElementos(frente);
    if(pos >= 1 && pos <= lenght) {
        if(pos == 1) {
            frente = insertInicial(frente, modeloCarro, colorCarro, placaCarro);
        } else {
            aux = frente;
            nuevo = asignarMemoria(modeloCarro, colorCarro, placaCarro);
            for(i = 1 ; i < pos-1 ; i++) {
                aux = aux -> siguiente;
            }
            nuevo -> siguiente = aux -> siguiente;
            nuevo -> anterior = aux;
            aux -> siguiente = nuevo;
            nuevo -> siguiente -> anterior = nuevo;
        }
    } else {
        printf("Posicion invalida\n");
    }

    return frente;
}


void mostrar(Nodo *frente) {
    if(frente == NULL) {
        printf("\nLa FILA esta vacia...");
    } else {
        while(frente != NULL) {
            printf("\nModelo: %s\t Color: %s\t Placa:\t %s dir:%d", frente -> modelo, frente->color, frente->placa, frente);
            frente = frente -> siguiente;
        }
    }
}

void mostrarAlRevez(Nodo *frente) {
    if(frente == NULL) {
        printf("\nLa FILA esta vacia...");
    } else {
        while(frente -> siguiente != NULL) {
            frente = frente -> siguiente;
        }
        while(frente != NULL){
            printf("\nModelo: %s Color: %s Placa: %s", frente -> modelo, frente->color, frente->placa);
            frente = frente -> anterior;
        }
    }
}

Nodo * intercambiar(Nodo *frente, char placaCarro1[20], char modeloCarro2[20], char colorCarro2[10], char placaCarro2[10]){
    Nodo *aux;
    int y = 0, x = 0;
    aux = frente;
    while (aux != NULL){
            if (aux->placa[y] == placaCarro1[y]){
                strcpy(aux->placa , placaCarro2);
                strcpy(aux->modelo, modeloCarro2);
                strcpy(aux->color, colorCarro2);
                x = 1;
                break;
            }
            else{
                aux = aux->siguiente;
            }
    }
    if (x==0){
        printf("\nEl valor que ingresaste no esta en la lista\n");
    }
    return frente;
}

Nodo * intercambiarAlReves(Nodo *frente, char placaCarro1[20], char modeloCarro2[20], char colorCarro2[10], char placaCarro2[10]){
    Nodo *aux;
    int x = 0, y = 0;
    aux = frente;
    while(aux -> siguiente != NULL) {
            aux = aux -> siguiente;
        }
    while (aux != NULL){
            if (aux->placa[y] == placaCarro1[y]){
                strcpy(aux->placa , placaCarro2);
                strcpy(aux->modelo, modeloCarro2);
                strcpy(aux->placa, placaCarro2);
                x = 1;
                break;
            }
            else{
                aux = aux->anterior;
            }
    }
    if (x==0){
        printf("\nEl valor que ingresaste no esta en la lista\n");
    }
    return frente;
}

Nodo * leerArchivo (char origen[20]){
    FILE * arch;
    Nodo * nuevo1;
    nuevo1 = NULL;
    char archOrigen[20], mod[20], col[10], pla[10];
    strcpy(archOrigen,origen);
    arch = fopen (archOrigen, "r");
    if (arch == NULL)
 		exit(1);
 	else
        {
        while (feof(arch) == 0)
            {
                fscanf(arch, "%s\t%s\t%s\n",mod,col,pla);
                nuevo1=insertFinal(nuevo1,mod,col,pla);
            }
        fclose(arch);
        }
    return nuevo1;
}
void acomodar(Nodo * frente){
    Nodo *aux1, *aux2, *aux3, *aux4;
    aux1 = frente;
    aux3 = frente;
    aux2 = aux1->siguiente;
    char modeloC[20], colorC [10], placaC [10];
    int posicion1, posicion2, x = 0, col = 0, cuenta, cuenta2;
    char abecedarios[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int numero = contarElementos(frente);
    for (cuenta = 0; cuenta <= numero; cuenta ++){
        if (cuenta == 0){
            posicion1 = 0;
            posicion2 = 0;
            while( x == 0){
                if (aux1->color[col]==abecedarios[posicion1]){
                    x = 1;
                }
                else {
                    posicion1 ++;
                }
            }
            while( x == 1){
                if (aux2->color[0]==abecedarios[posicion2]){
                    x = 2;
                }
                else {
                    posicion2 ++;
                }
            }
            if (posicion2 < posicion1){
                strcpy(modeloC, aux2 -> modelo); strcpy(colorC, aux2->color); strcpy(placaC, aux2->placa);
                strcpy(aux2 -> modelo, aux1 -> modelo); strcpy(aux2->color, aux1->color); strcpy(aux2->placa, aux1->placa);
                strcpy(aux1 -> modelo, modeloC); strcpy(aux1->color, colorC); strcpy(aux1->placa, placaC);
                /*frente = intercambiar(frente, aux1->placa, aux2->modelo, aux2->color, aux2->placa);
                frente -> siguiente = intercambiar(aux2, aux2->placa, modeloC, colorC, placaC);*/
            }

        }
       else {
            /*Estoy tratando de recorrer el apuntador aux3 a la segunda posicion desde frente, y aux4 a la posicion que va
            despues de aux3 pero cuando lo ejecuto tengo una funcion mostrar en el main justo despues de que termina
            esta función, y ya no la ejecuta esta función, pero el aux3 si recorre las direcciones que quiero que
            recorra, por lo tanto, considero que el error está en esta parte*/
            //for (cuenta2 = 0; cuenta2 <= cuenta; cuenta2++){
            //}
            aux3 = aux3 -> siguiente;
           // aux4 = aux3 -> siguiente;
       // printf("\n %s dir:%d\n", aux3->color, aux3);}
            printf("\n %s\n", aux3->color);}

           /* while( x == 0){
                if (aux1->color[col]==abecedarios[posicion1]){
                    x = 1;
                }
                else {
                    posicion1 ++;
                }
            }
            while( x == 1){
                if (aux2->color[0]==abecedarios[posicion2]){
                    x = 2;
                }
                else {
                    posicion2 ++;
                }
            }
            if (posicion2 < posicion1){
                strcpy(modeloC, aux1->modelo); strcpy(colorC, aux1->color); strcpy(placaC, aux1->placa);
                frente = intercambiar(aux1, aux1->placa, aux2->modelo, aux2->color, aux2->placa);
                frente -> siguiente = intercambiar(aux2, aux2->placa, modeloC, colorC, placaC);
            }

        }*/
    }
    //return frente;
}



#endif
