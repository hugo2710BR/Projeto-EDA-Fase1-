#include <stdlib.h>
#include <string.h>
#include "MobilidadeEletrica.h"

MeioMobilidade* criarMeioMobilidade(int id, char* tipo, int carga_bateria, int capacidade, float latitude, float longitude, float autonomia) {
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
