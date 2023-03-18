#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"

/**
 * @brief Funções como CriarCliente, CriarClienteFixo, AdicionarCliente
 * 
 * @param[out] id 
 * @param[out] nome 
 * @param[out] email 
 * @param[out] saldo 
 */

Cliente* CriarCliente(int id, char* nome, char* email, float saldo) {
    Cliente* novoCliente = (Cliente*) malloc(sizeof(Cliente));
    novoCliente->id = id;
    strcpy(novoCliente->nome, nome);
    strcpy(novoCliente->email, email);
    novoCliente->saldo = saldo;
  
    return novoCliente;
}

Cliente* CriarClienteFixo(void) {
    return CriarCliente(1, "Joao Silva", "joao.silva@email.com", 50.0);
}

void AdicionarCliente(Cliente** clientes, int *numClientes) {
    Cliente *novoCliente = (Cliente*) malloc(sizeof(Cliente));
    
    printf("Digite o ID do cliente: ");
    scanf("%d", &novoCliente->id);
    getchar();
    
    printf("Digite o nome do cliente: ");
    fgets(novoCliente->nome, sizeof(novoCliente->nome), stdin);
    strtok(novoCliente->nome, "\n");

    printf("Digite o email do cliente: ");
    fgets(novoCliente->email, sizeof(novoCliente->email), stdin);
    strtok(novoCliente->email, "\n");

    printf("Digite o saldo do cliente: ");
    scanf("%f", &novoCliente->saldo);
    getchar();

    system("cls");
    printf("\nCliente com ID: %i foi adicionado com sucesso!\n", novoCliente->id);

    (*numClientes)++;
    *clientes = (Cliente*) realloc(*clientes, *numClientes * sizeof(Cliente));
    (*clientes)[*numClientes - 1] = *novoCliente;
    free(novoCliente);
}

