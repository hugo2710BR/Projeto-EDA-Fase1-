#include <stdio.h>
#include <stdlib.h>
#include "Aluguer.h"
/**
 * @brief Atribui um aluguer com os dados do cliente e do veiculo criado e guardado no ficheiro binario
 * 
 * @param[out] clientes 
 * @param[out] numClientes 
 * @param[out] veiculos 
 * @param[out] numVeiculos 
 */

void atribuirAluguer(Cliente *clientes, int numClientes, MobilidadeEletrica *veiculos, int numVeiculos) {
    int idCliente, idVeiculo;

    // Obter o ID do cliente do usuário
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    // Validar o ID do cliente
    int clienteValido = 0;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].id == idCliente) {
            clienteValido = 1;
            break;
        }
    }

    if (!clienteValido) {
        printf("ID do cliente invalido!\n");
        return;
    }

    // Obter o ID do veículo do usuário
    printf("Digite o ID do veiculo: ");
    scanf("%d", &idVeiculo);

    // Validar o ID do veículo
    int veiculoValido = 0;
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].id == idVeiculo) {
            veiculoValido = 1;
            break;
        }
    }

    if (!veiculoValido) {
        printf("ID do veiculo invalido!\n");
        return;
    }

    // Crie uma nova estrutura de aluguer e atribua os IDs apropriados
    Aluguer novoAluguer;
    novoAluguer.idCliente = idCliente;
    novoAluguer.idVeiculo = idVeiculo;

    // Adicione outras informações relevantes, como data de início, data de término, etc.
    printf("Digite a data de início do aluguer (AAAA-MM-DD): ");
    scanf("%s", novoAluguer.dataInicio);
    printf("Digite a data de término do aluguer (AAAA-MM-DD): ");
    scanf("%s", novoAluguer.dataTermino);

    // Salvar a estrutura de aluguer em um arquivo binário
    FILE *arquivoAluguer = fopen("alugueres.bin", "ab");
    if (arquivoAluguer != NULL) {
        fwrite(&novoAluguer, sizeof(Aluguer), 1, arquivoAluguer);
        fclose(arquivoAluguer);
    } else {
        printf("Erro ao abrir o arquivo de alugueres");
        exit(1);
    }
}

void listarAlugueres() {
    FILE *arquivoAluguer = fopen("alugueres.bin", "rb");
    if (arquivoAluguer == NULL) {
        printf("Nenhum aluguer encontrado.\n");
        return;
    }

    fseek(arquivoAluguer, 0, SEEK_END);
    long tamanhoArquivoAluguer = ftell(arquivoAluguer);
    rewind(arquivoAluguer);
    int numElementosAluguer = tamanhoArquivoAluguer / sizeof(Aluguer);

    Aluguer *alugueres = (Aluguer *)malloc(numElementosAluguer * sizeof(Aluguer));
    if (alugueres == NULL) {
        printf("Erro ao alocar memoria\n");
        fclose(arquivoAluguer);
        exit(1);
    }

    fread(alugueres, sizeof(Aluguer), numElementosAluguer, arquivoAluguer);
    fclose(arquivoAluguer);

    printf("Lista de alugueres:\n");
    for (int i = 0; i < numElementosAluguer; i++) {
        printf("\nAluguer #%d:\n", i + 1);
        printf("  ID do Cliente: %d\n", alugueres[i].idCliente);
        printf("  ID do Veiculo: %d\n", alugueres[i].idVeiculo);
        printf("  Data de inicio: %s\n", alugueres[i].dataInicio);
        printf("  Data de termino: %s\n", alugueres[i].dataTermino);
        printf("  Aluguer ativo: %s\n", alugueres[i].aluguerAtivo ? "Sim" : "Nao");
    }

    free(alugueres);
}
