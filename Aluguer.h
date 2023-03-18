#ifndef ALUGUER_H
#define ALUGUER_H

#include <stdbool.h>
#include "Cliente.h" // Inclua o arquivo de cabeçalho do Cliente aqui
#include "MobilidadeEletrica.h" // Inclua o arquivo de cabeçalho do MobilidadeEletrica aqui

typedef struct {
    int idCliente;
    int idVeiculo;
    char dataInicio[11]; // Formato de data AAAA-MM-DD + caractere nulo
    char dataTermino[11]; // Formato de data AAAA-MM-DD + caractere nulo
    double preco; // Preço total do aluguer
    bool aluguerAtivo; // Indica se o aluguer está ativo ou não
} Aluguer;

void atribuirAluguer(Cliente *clientes, int numClientes, MobilidadeEletrica *veiculos, int numVeiculos);
void listarAlugueres();

#endif // ALUGUER_H
