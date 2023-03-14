#include <stdlib.h>
#include <string.h>
#include "Gestor.h"

Gestor* CriarGestor(int id, char* nome, char* email, char* senha) {
    Gestor* novoGestor = (Gestor*) malloc(sizeof(Gestor));
    novoGestor->id = id;
    strcpy(novoGestor->nome, nome);
    strcpy(novoGestor->email, email);
    strcpy(novoGestor->senha, senha);
    return novoGestor;
}

Gestor* CriarGestorFixo(void) {
    return CriarGestor(1, "Maria Fernandes", "maria.fernandes@email.com", "senha123");
}