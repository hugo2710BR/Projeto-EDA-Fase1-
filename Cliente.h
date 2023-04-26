#ifndef CLIENTE_H
#define CLIENTE_H

#define N 50
/**
 * @brief Ficheiro para declarar as funções e struct utilizados no ficheiro .c
 * 
 */
typedef struct {
    int id;
    char nome[N];
    char email[N];
    float saldo;
   
}Cliente;

/// @brief 
/// @param id 
/// @param nome 
/// @param email 
/// @param saldo 
/// @return 
Cliente* CriarCliente(int id, char* nome, char* email, float saldo);

/// @brief 
/// @param  
/// @return 
Cliente* CriarClienteFixo(void);

/// @brief 
/// @param clientes 
/// @param numClientes 
void AdicionarCliente(Cliente** clientes, int *numClientes);

#endif /* CLIENTE_H */

