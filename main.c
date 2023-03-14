#include <stdio.h>
#include <stdlib.h>
#include "MobilidadeEletrica.h"
#include "Gestor.h"


int main() {
    /*
    MeioMobilidade** meios = inicializarMeiosMobilidade();
    printf("ID: %d, Tipo: %s, Carga: %d, Capacidade: %d, Latitude: %f, Longitude: %f, Autonomia: %d\n", meios[0]->id, meios[0]->tipo, meios[0]->carga_bateria, meios[0]->capacidade, meios[0]->latitude, meios[0]->longitude, meios[0]->autonomia);
    printf("ID: %d, Tipo: %s, Carga: %d, Capacidade: %d, Latitude: %f, Longitude: %f, Autonomia: %d\n", meios[1]->id, meios[1]->tipo, meios[1]->carga_bateria, meios[1]->capacidade, meios[1]->latitude, meios[1]->longitude, meios[1]->autonomia);
    printf("ID: %d, Tipo: %s, Carga: %d, Capacidade: %d, Latitude: %f, Longitude: %f, Autonomia: %d\n", meios[2]->id, meios[2]->tipo, meios[2]->carga_bateria, meios[2]->capacidade, meios[2]->latitude, meios[2]->longitude, meios[2]->autonomia);
    */
   
    Gestor** gestores = inicializarGestor();
    printf("ID: %d, Nome: %s, Email: %s, Contribuinte: %s\n", gestores[0]->id, gestores[0]->nome, gestores[0]->email, gestores[0]->contribuinte);
    printf("ID: %d, Nome: %s, Email: %s, Contribuinte: %s\n", gestores[1]->id, gestores[1]->nome, gestores[1]->email, gestores[1]->contribuinte);
    printf("ID: %d, Nome: %s, Email: %s, Contribuinte: %s\n", gestores[2]->id, gestores[2]->nome, gestores[2]->email, gestores[2]->contribuinte);
    

return 0;
}
