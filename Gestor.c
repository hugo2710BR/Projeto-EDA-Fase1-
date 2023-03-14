#include <stdlib.h>
#include <string.h>
#include "Gestor.h"

Gestor* criarGestor(int id, char* nome, char* email, int contribuinte) {
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
