#ifndef GESTOR_H
#define GESTOR_H

/**
 * @brief Ficheiro para declarar struct e funções para serem utilizados no ficheiro .c
 * 
 */

typedef struct{
    int id;
    char nome[50];
    char email[50];
    char senha[50];
}Gestor;

/// @brief 
/// @param id 
/// @param nome 
/// @param email 
/// @param senha 
/// @return 
Gestor* CriarGestor(int id, char* nome, char* email, char* senha);
/// @brief 
/// @param  
/// @return 
Gestor* CriarGestorFixo(void);
/// @brief 
/// @param gestores 
/// @param numGestores 
void AdicionarGestor(Gestor** gestores, int *numGestores);

#endif /* GESTOR_H */

