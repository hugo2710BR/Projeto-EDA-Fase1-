#include <stdlib.h>
#include <string.h>
#include "MobilidadeEletrica.h"

MobilidadeEletrica* CriarMobilidadeEletrica(int id, char* tipo, char* estado, char* localizacao, int bateria, float preco) {
    MobilidadeEletrica* novoMeio = (MobilidadeEletrica*) malloc(sizeof(MobilidadeEletrica));
    novoMeio->id = id;
    strcpy(novoMeio->tipo, tipo);
    strcpy(novoMeio->estado, estado);
    strcpy(novoMeio->localizacao, localizacao);
    novoMeio->bateria = bateria;
    novoMeio->preco = preco;
    return novoMeio;
}

MobilidadeEletrica* CriarMobilidadeEletricaFixa(void) {
    return CriarMobilidadeEletrica(1, "Bicicleta eletrica", "Disponivel", "Praca da Republica", 80, 0.15);
}