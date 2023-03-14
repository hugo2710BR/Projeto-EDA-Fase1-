#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

Cliente* criarCliente(int id, char* nome, char* email, char* morada, int contribuinte) {
    Cliente* novo_cliente = malloc(sizeof(Cliente));
    novo_cliente->id = id;
    strcpy(novo_cliente->nome, nome);
    strcpy(novo_cliente->email, email);
    strcpy(novo_cliente->morada, morada);
    strcpy(novo_cliente->contribuinte, contribuinte);
    return novo_cliente;
}

int destruirCliente(Cliente* cliente) {
    free(cliente);
}
