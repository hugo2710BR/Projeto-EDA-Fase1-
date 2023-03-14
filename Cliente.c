#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

Cliente* CriarCliente(int id, char* nome, char* email, float saldo) {
    Cliente* novoCliente = (Cliente*) malloc(sizeof(Cliente));
    novoCliente->id = id;
    strcpy(novoCliente->nome, nome);
    strcpy(novoCliente->email, email);
    novoCliente->saldo = saldo;
    novoCliente->meios = NULL;
    novoCliente->proximo = NULL;
    return novoCliente;
}

Cliente* CriarClienteFixo(void) {
    return CriarCliente(1, "Joao Silva", "joao.silva@email.com", 50.0);
}

