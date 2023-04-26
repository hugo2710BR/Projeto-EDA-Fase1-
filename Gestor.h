#ifndef GESTOR_H
#define GESTOR_H

#define N 50
/**
 * @brief Ficheiro para declarar struct e funções para serem utilizados no ficheiro .c
 * 
 */

typedef struct{
    int id;
    char nome[N];
    char email[N];
    char senha[N];
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

