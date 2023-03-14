#include <stdlib.h>
#include <string.h>
#include "Gestor.h"

Gestor* criarGestor(int id, char* nome, char* email, char* contribuinte) {
    Gestor* novo_gestor = malloc(sizeof(Gestor));
    novo_gestor->id = id;
    strcpy(novo_gestor->nome, nome);
    strcpy(novo_gestor->email, email);
    strcpy(novo_gestor->contribuinte, contribuinte);
    return novo_gestor;
}

int destruirGestor(Gestor* gestor) {
    free(gestor);
}

Gestor** inicializarGestor(){
    Gestor** gestores = malloc(3 * sizeof(Gestor*));
    gestores[0] = criarGestor(1, "Hugo Brandao", "hugosoares2710@outlook.pt", "12345789");
    gestores[1] = criarGestor(2, "Diego Brandao", "diegobrandao@outlook.pt", "987654321");
    gestores[2] = criarGestor(3, "Manuel Brandao", "manuelsoares@outlook.pt", "214365879");
    return gestores;
}