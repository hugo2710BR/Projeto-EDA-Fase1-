#ifndef MOBILIDADE_ELETRICA_H
#define MOBILIDADE_ELETRICA_H

typedef struct MeioMobilidade {
    int id;
    char tipo[50];
    int carga_bateria;
    int capacidade;
    float latitude;
    float longitude;
    int autonomia;
} MeioMobilidade;

MeioMobilidade* criarMeioMobilidade(int id, char* tipo, int carga_bateria, int capacidade, float latitude, float longitude, int autonomia);
int destruirMeioMobilidade(MeioMobilidade* meio);

#endif
