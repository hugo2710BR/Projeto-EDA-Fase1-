#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MobilidadeEletrica.h"

/**
 * @brief Ficheiro .c com as funções CriarMobilidadeEletrica, CriarMobilidadeEletricaFixa e AdicionarMobilidadeEletrica
 * 
 * @param[out] id 
 * @param[out] tipo 
 * @param[out] estado 
 * @param[out] localizacao 
 * @param[out] autonomia 
 * @param[out] bateria 
 * @param[out] preco 
 * @return  
 */

MobilidadeEletrica* CriarMobilidadeEletrica(int id, char* tipo, char* estado, char* localizacao, char* autonomia, double bateria, float preco) {
    MobilidadeEletrica* novoMeio = (MobilidadeEletrica*) malloc(sizeof(MobilidadeEletrica));
    novoMeio->id = id;
    strcpy(novoMeio->tipo, tipo);
    strcpy(novoMeio->estado, estado);
    strcpy(novoMeio->localizacao, localizacao);
    strcpy(novoMeio->autonomia, autonomia);
    novoMeio->bateria = bateria;
    novoMeio->preco = preco;
    return novoMeio;
}

MobilidadeEletrica* CriarMobilidadeEletricaFixa(void) {
    return CriarMobilidadeEletrica(1, "Bicicleta eletrica", "Disponivel", "Praca da Republica", "600", 80, 0.15);
}

void AdicionarMobilidadeEletrica(MobilidadeEletrica** veiculos, int *numVeiculos) {
    MobilidadeEletrica *novoMeio = (MobilidadeEletrica*) malloc(sizeof(MobilidadeEletrica));
    
    printf("Digite o ID do veiculo: ");
    scanf("%d", &novoMeio->id);
    getchar();
    
    printf("Digite o tipo do veiculo: ");
    fgets(novoMeio->tipo, sizeof(novoMeio->tipo), stdin);
    strtok(novoMeio->tipo, "\n");

    printf("Digite o estado do veiculo: ");
    fgets(novoMeio->estado, sizeof(novoMeio->estado), stdin);
    strtok(novoMeio->estado, "\n");

    printf("Digite a localizacao do veiculo: ");
    fgets(novoMeio->localizacao, sizeof(novoMeio->localizacao), stdin);
    strtok(novoMeio->localizacao, "\n");

    printf("Digite a autonomia do veiculo: ");
    fgets(novoMeio->autonomia, sizeof(novoMeio->autonomia), stdin);
    strtok(novoMeio->autonomia, "\n");

    printf("Digite o preco do veiculo: ");
    scanf("%f", &novoMeio->preco);
    getchar();

    printf("Digite a percentagem de bateria que tem o veiculo: ");
    scanf("%d", &novoMeio->bateria);
    getchar();
   
    system("cls");
    printf("\nVeiculo com ID: %i foi adicionado com sucesso!\n", novoMeio->id);

    (*numVeiculos)++;
    *veiculos = (MobilidadeEletrica*) realloc(*veiculos, *numVeiculos * sizeof(MobilidadeEletrica));
    (*veiculos)[*numVeiculos - 1] = *novoMeio;
    free(novoMeio);
}  