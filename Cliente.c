#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

Cliente* criarCliente(int id, char* nome, char* email, char* morada, char* contribuinte) {
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

Cliente** inicializarCliente(){
    Cliente** clientes = malloc(3 * sizeof(Cliente*));
    clientes[0] = criarCliente(1, "Hugo Brandao", "hugosoares2710@outlook.pt", "Rua Da Fontainha", "12345789");
    clientes[1] = criarCliente(2, "Diego Brandao", "diegobrandao@outlook.pt", "Rua Da Fontainha", "987654321");
    clientes[2] = criarCliente(3, "Manuel Brandao", "manuelsoares@outlook.pt", "Rua Da Fontainha", "214365879");
    return clientes;
}