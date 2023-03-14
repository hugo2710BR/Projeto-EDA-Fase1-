#ifndef GESTOR_H_INCLUDED
#define GESTOR_H_INCLUDED

typedef struct {
    int id;             // Identificador único do gestor
    char nome[50];      // Nome do gestor
    char email[50];     // Endereço de email do gestor
    char contribuinte[9];
} Gestor;

Gestor* criarGestor(int id, char* nome, char* email, char* contribuinte);
int destruirGestor(Gestor* gestor);

#endif // GESTOR_H_INCLUDED;
