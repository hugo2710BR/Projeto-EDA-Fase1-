#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Gestor.h"

/**
 * @brief Ficheiro que contem funções CriarGestor, CriarGestorFixo e AdiconarGestor
 * 
 * @param[out] id 
 * @param[out] nome 
 * @param[out] email 
 * @param[out] senha 
 */

/// @brief 
/// @param id 
/// @param nome 
/// @param email 
/// @param senha 
/// @return 
Gestor* CriarGestor(int id, char* nome, char* email, char* senha) {
    Gestor* novoGestor = (Gestor*) malloc(sizeof(Gestor));
    novoGestor->id = id;
    strcpy(novoGestor->nome, nome);
    strcpy(novoGestor->email, email);
    strcpy(novoGestor->senha, senha);
    return novoGestor;
}

/// @brief 
/// @param  
/// @return 
Gestor* CriarGestorFixo(void) {
    return CriarGestor(1, "Maria Fernandes", "maria.fernandes@email.com", "senha123");
}

/// @brief 
/// @param gestores 
/// @param numGestores 
void AdicionarGestor(Gestor** gestores, int *numGestores) {
    Gestor *novoGestor = (Gestor*) malloc(sizeof(Gestor));
    
    printf("Digite o ID do cliente: ");
    scanf("%d", &novoGestor->id);
    getchar();
    
    printf("Digite o nome do cliente: ");
    fgets(novoGestor->nome, sizeof(novoGestor->nome), stdin);
    strtok(novoGestor->nome, "\n");

    printf("Digite o email do gestor: ");
    fgets(novoGestor->email, sizeof(novoGestor->email), stdin);
    strtok(novoGestor->email, "\n");

    printf("Digite a senha do gestor: ");
    fgets(novoGestor->senha, sizeof(novoGestor->senha), stdin);
    strtok(novoGestor->senha, "\n");

    system("cls");
    printf("\nGestor com ID: %i foi adicionado com sucesso!\n", novoGestor->id);

    (*numGestores)++;
    *gestores = (Gestor*) realloc(*gestores, *numGestores * sizeof(Gestor));
    (*gestores)[*numGestores - 1] = *novoGestor;
    free(novoGestor);
}
