#ifndef GESTOR_H
#define GESTOR_H

typedef struct Gestor Gestor;

struct Gestor {
    int id;
    char nome[50];
    char email[50];
    char senha[50];
};

Gestor* CriarGestor(int id, char* nome, char* email, char* senha);
Gestor* CriarGestorFixo(void);

#endif /* GESTOR_H */

