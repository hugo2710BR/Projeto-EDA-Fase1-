#ifndef MOBILIDADEELETRICA_H
#define MOBILIDADEELETRICA_H

typedef struct MobilidadeEletrica MobilidadeEletrica;
struct MobilidadeEletrica {
    int id;
    char tipo[50];
    char estado[50];
    char localizacao[50];
    int bateria;
    float preco;
     MobilidadeEletrica *proximo;
} ;

MobilidadeEletrica* CriarMobilidadeEletrica(int id, char* tipo, char* estado, char* localizacao, int bateria, float preco);
MobilidadeEletrica* CriarMobilidadeEletricaFixa(void);

#endif /* MOBILIDADEELETRICA_H */
