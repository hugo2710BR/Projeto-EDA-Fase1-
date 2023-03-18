#ifndef CLIENTE_H
#define CLIENTE_H

/**
 * @brief Ficheiro para declarar as funções e struct utilizados no ficheiro .c
 * 
 */
typedef struct {
    int id;
    char nome[50];
    char email[50];
    float saldo;
   
}Cliente;

Cliente* CriarCliente(int id, char* nome, char* email, float saldo);
Cliente* CriarClienteFixo(void);
void AdicionarCliente(Cliente** clientes, int *numClientes);

#endif /* CLIENTE_H */

