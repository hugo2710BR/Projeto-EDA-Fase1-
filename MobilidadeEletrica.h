#ifndef MOBILIDADEELETRICA_H
#define MOBILIDADEELETRICA_H

/**
 * @brief Ficheiro .h para declarar struct de mobilidade e devidas funções
 * 
 */
typedef struct{
    int id;
    char tipo[50];
    char estado[50];
    char localizacao[50];
    char autonomia[50];
    double bateria;
    float preco;
}MobilidadeEletrica;

MobilidadeEletrica* CriarMobilidadeEletrica(int id, char* tipo, char* estado, char* localizacao, char* autonomia, double bateria, float preco);
MobilidadeEletrica* CriarMobilidadeEletricaFixa(void);

#endif /* MOBILIDADEELETRICA_H */
