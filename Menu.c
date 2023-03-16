#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "MobilidadeEletrica.h"
#include "Cliente.h"
#include "Gestor.h"

void menu(){
    printf("\nMENU:\n");
    printf("1 - Listar Mobilidade Eletrica\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Listar Gestores\n");
    printf("4 - Gestao Clientes\n");
    printf("5 - Gestao Gestores\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

void GestaoClientes(){
    printf("\nMenu Gestao Clientes:\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Alterar Cliente\n");
    printf("3 - Remover Cliente\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

}

void GestaoGestores(){
    printf("\nMenu Gestao Gestores:\n");
    printf("1 - Adicionar Gestor\n");
    printf("2 - Alterar Gestor\n");
    printf("3 - Remover Gestor\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

}

int master(void) {
    MobilidadeEletrica* mobilidadeFixa = CriarMobilidadeEletricaFixa();
    Cliente* clienteFixo = CriarClienteFixo();
    Gestor* gestorFixo = CriarGestorFixo();

    Cliente *clientes = NULL;
    Gestor *gestores = NULL;

    int numClientes= 0;
    int numGestores= 0;

void imprimirMobilidadeEletrica(MobilidadeEletrica *mobilidadeFixa) {
    printf("\n\nMobilidade Eletrica Fixa:\nID: %d\nTipo: %s\nEstado: %s\nLocalizacao: %s\nBateria: %d%%\nPreco: %.2f\n\n",
            mobilidadeFixa->id, mobilidadeFixa->tipo, mobilidadeFixa->estado, mobilidadeFixa->localizacao, mobilidadeFixa->bateria, mobilidadeFixa->preco);
}

void ImprimirCliente(Cliente *clientefixo){
    printf("\n\nClientes:\n");
        printf("ID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                clienteFixo->id, clienteFixo->nome, clienteFixo->email, clienteFixo->saldo);
    for (int i = 0; i < numClientes; i++) {
        printf("ID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].saldo);
                
    }   
    
}

    // Abrir o arquivo binário de clientes em modo de leitura
    FILE *arquivoCliente = fopen("clientes.bin", "rb");
    if (arquivoCliente != NULL) {
        // Obter o número de elementos no arquivo binário
        fseek(arquivoCliente, 0, SEEK_END);
        long tamanhoArquivoCliente = ftell(arquivoCliente);
        rewind(arquivoCliente);
        int numElementosCliente = tamanhoArquivoCliente / sizeof(Cliente);

        // Alocar memória para o array "clientes"
        clientes = (Cliente*) malloc(numElementosCliente * sizeof(Cliente));
        if (clientes == NULL) {
            printf("Erro ao alocar memoria");
            exit(1);
        }

        // Ler o array "clientes" do arquivo binário
        fread(clientes, sizeof(Cliente), numElementosCliente, arquivoCliente);

        // Fechar o arquivo
        fclose(arquivoCliente);

        // Atualizar o número de clientes
        numClientes = numElementosCliente;
      

        
    }

    // Abrir o arquivo binário de gestores em modo de leitura
    FILE *arquivoGestor = fopen("gestores.bin", "rb");
    if (arquivoGestor != NULL) {
        // Obter o número de elementos no arquivo binário
        fseek(arquivoGestor, 0, SEEK_END);
        long tamanhoArquivoGestor = ftell(arquivoGestor);
        rewind(arquivoGestor);
        int numElementosGestor = tamanhoArquivoGestor / sizeof(Gestor);

        // Alocar memória para o array "clientes"
        gestores = (Gestor*) malloc(numElementosGestor * sizeof(Gestor));
        if (gestores == NULL) {
            printf("Erro ao alocar memoria");
            exit(1);
        }

        // Ler o array "clientes" do arquivo binário
        fread(gestores, sizeof(Gestor), numElementosGestor, arquivoGestor);

        // Fechar o arquivo
        fclose(arquivoGestor);

        // Atualizar o número de clientes
        numGestores = numElementosGestor;
      

        
    }

    int opcao;
    int OpcaoGestaoCliente;
    int OpcaoGestaoGestor;

    do{
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado
        
        switch(opcao){
            case 1:
                system("cls");
                imprimirMobilidadeEletrica(mobilidadeFixa);
                break;

            case 2:
                system("cls");
                ImprimirCliente(clienteFixo);
                break;

            case 3:
                system("cls");
                printf("\n\nGestor Fixo:\nID: %d\nNome: %s\nEmail: %s\nSenha: %s\n\n",
                    gestorFixo->id, gestorFixo->nome, gestorFixo->email, gestorFixo->senha);
                for (int i = 0; i < numGestores; i++) {
                    printf("ID: %d\nNome: %s\nSenha: %s\nEmail: %s\n\n",
                       gestores[i].id, gestores[i].nome, gestores[i].senha, gestores[i].email);
                }
                break;
            case 4:
                do{
                    system("cls");
                    GestaoClientes();
                    scanf("%d", &OpcaoGestaoCliente);
                    getchar(); // Limpar o buffer do teclado

                    switch (OpcaoGestaoCliente){
                        case 1:
                            system("cls");
                            AdicionarCliente(&clientes, &numClientes);
                            // Abrir o arquivo binário em modo de escrita
                            arquivoCliente = fopen("clientes.bin", "wb");
                            if (arquivoCliente == NULL) {
                                printf("Erro ao abrir o arquivo");
                                exit(1);
                            }

                            // Gravar o array "clientes" no arquivo binário
                            fwrite(clientes, sizeof(Cliente), numClientes, arquivoCliente);

                            // Fechar o arquivo
                            fclose(arquivoCliente);
                            break;
                        case 3:
                            system("cls");
                            printf("\n\nClientes:\n");
                            for (int i = 0; i < numClientes; i++) {
                                printf("ID: %d\n", clientes[i].id);
                                printf("Nome: %s\n", clientes[i].nome);
                                printf("Email: %s\n", clientes[i].email);
                                printf("Saldo: %.2f\n\n", clientes[i].saldo);
                                }
                                // Remover um cliente do array "clientes"
                                printf("Digite o ID do cliente que deseja remover: ");
                                int idRemover;
                                scanf("%d", &idRemover);
                                int indiceRemover = -1;
                                for (int i = 0; i < numClientes; i++) {
                                    if (clientes[i].id == idRemover) {
                                        indiceRemover = i;
                                        break;
                                    }
                                }
                                if (indiceRemover != -1) {
                                    for (int i = indiceRemover; i < numClientes - 1; i++) {
                                        clientes[i] = clientes[i + 1];
                                    }
                                    numClientes--;

                                    // Abrir o arquivo binário em modo de escrita
                                    arquivoCliente = fopen("clientes.bin", "wb");
                                    if (arquivoCliente == NULL) {
                                        printf("Erro ao abrir o arquivo");
                                        exit(1);
                                    }

                                    // Gravar o novo array "clientes" no arquivo binário
                                    fwrite(clientes, sizeof(Cliente), numClientes, arquivoCliente);

                                    // Fechar o arquivo
                                    fclose(arquivoCliente);

                                    printf("\nCliente removido com sucesso!\n");
                                } else {
                                    printf("\nCliente nao encontrado!\n");
                                }
                            break;

                        case 0:
                            system("cls");
                            break;

                    default:
                        printf("\n\nOpcao invalida! Tente novamente.\n");
                        break;
                    }

                }while (OpcaoGestaoCliente != 0);
               
            case 5:
                do{
                    system("cls");
                    GestaoGestores();
                    scanf("%d", &OpcaoGestaoGestor);
                    getchar(); // Limpar o buffer do teclado

                    switch (OpcaoGestaoGestor){
                        case 1:
                            system("cls");
                            AdicionarGestor(&gestores, &numGestores);
                            // Abrir o arquivo binário em modo de escrita
                            arquivoGestor = fopen("gestores.bin", "wb");
                            if (arquivoGestor == NULL) {
                                printf("Erro ao abrir o arquivo");
                                exit(1);
                            }

                            // Gravar o array "clientes" no arquivo binário
                            fwrite(gestores, sizeof(Gestor), numGestores, arquivoGestor);

                            // Fechar o arquivo
                            fclose(arquivoGestor);
                            break;
                        case 3:
                            system("cls");
                            printf("\n\nGestores:\n");
                            for (int i = 0; i < numGestores; i++) {
                                printf("ID: %d\n", gestores[i].id);
                                printf("Nome: %s\n", gestores[i].nome);
                                printf("Senha: %s\n", gestores[i].senha);
                                printf("Email: %s\n", gestores[i].email);
                                }
                                // Remover um cliente do array "gestores"
                                printf("\nDigite o ID do gestor que deseja remover: ");
                                int idRemover;
                                scanf("%d", &idRemover);
                                int indiceRemover = -1;
                                for (int i = 0; i < numGestores; i++) {
                                    if (gestores[i].id == idRemover) {
                                        indiceRemover = i;
                                        break;
                                    }
                                }
                                if (indiceRemover != -1) {
                                    for (int i = indiceRemover; i < numGestores - 1; i++) {
                                        gestores[i] = gestores[i + 1];
                                    }
                                    numGestores--;

                                    // Abrir o arquivo binário em modo de escrita
                                    arquivoGestor = fopen("gestores.bin", "wb");
                                    if (arquivoGestor == NULL) {
                                        printf("Erro ao abrir o arquivo");
                                        exit(1);
                                    }

                                    // Gravar o novo array "clientes" no arquivo binário
                                    fwrite(gestores, sizeof(Gestor), numGestores, arquivoGestor);

                                    // Fechar o arquivo
                                    fclose(arquivoGestor);

                                    printf("\nGestor removido com sucesso!\n");
                                } else {
                                    printf("\nGestor nao encontrado!\n");
                                }
                            break;

                        case 0:
                            system("cls");
                            break;

                    default:
                        printf("\n\nOpcao invalida! Tente novamente.\n");
                        break;
                    }

                }while (OpcaoGestaoGestor != 0);

              break;
            case 0:
                system("cls");
                break;

            default:
                printf("\n\nOpcao invalida! Tente novamente.\n");
                break;
            }
    }while(opcao != 0);

    free(mobilidadeFixa);
    free(clienteFixo);
    free(gestorFixo);

    return 0;
}