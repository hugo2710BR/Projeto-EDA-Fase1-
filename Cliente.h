#ifndef CLIENTE_H
#define CLIENTE_H

#include "MobilidadeEletrica.h"

typedef struct Cliente Cliente;

struct Cliente {
    int id;
    char nome[50];
    char email[50];
    float saldo;
    MobilidadeEletrica *meios;
    Cliente *proximo;
};

Cliente* CriarCliente(int id, char* nome, char* email, float saldo);
Cliente* CriarClienteFixo(void);

#endif /* CLIENTE_H */

