#ifndef MEIOMOBILIDADE_H_INCLUDED
#define MEIOMOBILIDADE_H_INCLUDED

typedef struct {
    int id;            // Identificador único do meio de mobilidade
    char tipo[20];     // Tipo de meio de mobilidade (ex: bicicleta, carro, scooter)
    int carga_bateria;   // Carga atual da bateria em percentagem (0 a 100)
    int capacidade;    // Capacidade máxima da bateria em kWh
    float latitude;    // Latitude atual do meio de mobilidade
    float longitude;   // Longitude atual do meio de mobilidade
    float autonomia;   // Autonomia do veiculo em KM
} MeioMobilidade;

MeioMobilidade* criarMeioMobilidade(int id, char* tipo, int carga_atual, int capacidade, float latitude, float longitude, float autonomia);
int destruirMeioMobilidade(MeioMobilidade* meio);

#endif // MEIOMOBILIDADE_H_INCLUDED;
