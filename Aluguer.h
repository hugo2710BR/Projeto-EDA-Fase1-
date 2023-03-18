#ifndef ALUGUER_H
#define ALUGUER_H

#include <stdbool.h>
#include "Cliente.h" 
#include "MobilidadeEletrica.h"

/**
 * @brief Ficheiro para declarar struct e funções que serão usados no ficheiro .c
 * 
 */

typedef struct {
    int idCliente;
    int idVeiculo;
    char dataInicio[11]; 
    char dataTermino[11];
    double preco; 
    bool aluguerAtivo; 
} Aluguer;

void atribuirAluguer(Cliente *clientes, int numClientes, MobilidadeEletrica *veiculos, int numVeiculos);
void listarAlugueres();

#endif // ALUGUER_H
