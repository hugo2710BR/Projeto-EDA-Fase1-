#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
    int id;             // Identificador único do cliente
    char nome[50];      // Nome do cliente
    char email[50];     // Endereço de email do cliente
    char morada[100];   // Morada do cliente
    int contribuinte[9];   // Contribuinte do cliente
} Cliente;

Cliente* criarCliente(int id, char* nome, char* email, char* morada, int contribuinte);
int destruirCliente(Cliente* cliente);

#endif // CLIENTE_H_INCLUDED
