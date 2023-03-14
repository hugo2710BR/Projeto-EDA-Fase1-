#include <stdlib.h>
#include <string.h>
#include "MobilidadeEletrica.h"

MeioMobilidade* criarMeioMobilidade(int id, char* tipo, int carga_bateria, int capacidade, float latitude, float longitude, int autonomia) {
    MeioMobilidade* novo_meio = malloc(sizeof(MeioMobilidade));
    novo_meio->id = id;
    strcpy(novo_meio->tipo, tipo);
    novo_meio->carga_bateria = carga_bateria;
    novo_meio->capacidade = capacidade;
    novo_meio->latitude = latitude;
    novo_meio->longitude = longitude;
    novo_meio->autonomia = autonomia;
    return novo_meio;
}

int destruirMeioMobilidade(MeioMobilidade* meio) {
    free(meio);
}

MeioMobilidade** inicializarMeiosMobilidade() {
    MeioMobilidade** meios = malloc(3 * sizeof(MeioMobilidade*));
    meios[0] = criarMeioMobilidade(1, "bicicleta", 75, 300, 38.736946, -9.142685, 100);
    meios[1] = criarMeioMobilidade(2, "carro", 50, 500, 38.734326, -9.139051, 200);
    meios[2] = criarMeioMobilidade(3, "scooter", 90, 400, 38.737881, -9.153281, 150);
    return meios;
}
