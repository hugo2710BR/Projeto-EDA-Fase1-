#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "MobilidadeEletrica.h"
#include "Cliente.h"
#include "Gestor.h"
#include "Aluguer.h"

    int numVeiculos= 0;
    int numClientes= 0;
    int numGestores= 0;

void menu(){
    printf("\nMENU:\n");
    printf("1 - Listar Mobilidade Eletrica\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Listar Gestores\n");
    printf("4 - Gestao Clientes\n");
    printf("5 - Gestao Gestores\n");
    printf("6 - Gestao Mobilidade\n");
    printf("7 - Criar Aluguer\n");
    printf("8 - Listar Alugueres\n");
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

void GestaoMobilidade(){
    printf("\nMenu Gestao Veiculo:\n");
    printf("1 - Adicionar Veiculo\n");
    printf("2 - Alterar Veiculo\n");
    printf("3 - Remover Veiculo\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");

}

  int compare(const void *a, const void *b) {
    MobilidadeEletrica *elem1 = (MobilidadeEletrica *)a;
    MobilidadeEletrica *elem2 = (MobilidadeEletrica *)b;
    return (elem2->autonomia - elem1->autonomia);
    } 

int master(void) {
    
    MobilidadeEletrica* mobilidadeFixa = CriarMobilidadeEletricaFixa();
    Cliente* clienteFixo = CriarClienteFixo();
    Gestor* gestorFixo = CriarGestorFixo();

    MobilidadeEletrica *veiculos = NULL;
    Cliente *clientes = NULL;
    Gestor *gestores = NULL;
    
  

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

     // Abrir o arquivo binário de Mobilidade em modo de leitura
    FILE *arquivoMobilidade = fopen("mobilidade.bin", "rb");
    if (arquivoMobilidade != NULL) {
        // Obter o número de elementos no arquivo binário
        fseek(arquivoMobilidade, 0, SEEK_END);
        long tamanhoArquivoMobilidade = ftell(arquivoMobilidade);
        rewind(arquivoMobilidade);
        int numElementosMobilidade = tamanhoArquivoMobilidade / sizeof(MobilidadeEletrica);

        // Alocar memória para o array "clientes"
        veiculos = (MobilidadeEletrica*) malloc(numElementosMobilidade * sizeof(MobilidadeEletrica));
        if (veiculos == NULL) {
            printf("Erro ao alocar memoria");
            exit(1);
        }

        // Ler o array "clientes" do arquivo binário
        fread(veiculos, sizeof(MobilidadeEletrica), numElementosMobilidade, arquivoMobilidade);

        // Fechar o arquivo
        fclose(arquivoMobilidade);

        // Ordenar os dados em ordem decrescente de autonomia
        qsort(veiculos, numElementosMobilidade, sizeof(MobilidadeEletrica), compare);

        // Atualizar o número de clientes
        numVeiculos = numElementosMobilidade;
      
    }

    int opcao;
    int OpcaoGestaoCliente;
    int OpcaoGestaoGestor;
    int OpcaoGestaoMobilidade;

    void ImprimirCliente(Cliente *clientefixo){
        printf("\n\nClientes:\n");
            printf("ID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                    clienteFixo->id, clienteFixo->nome, clienteFixo->email, clienteFixo->saldo);
        for (int i = 0; i < numClientes; i++) {
            printf("ID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                    clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].saldo);
                    
        }   
        
    }

    void ImprimirGestor(Gestor *gestorFixo){
        printf("\n\nGestores:\n");
        printf("ID: %d\nNome: %s\nEmail: %s\nSenha: %s\n\n",
                gestorFixo->id, gestorFixo->nome, gestorFixo->email, gestorFixo->senha);
        for (int i = 0; i < numGestores; i++) {
            printf("ID: %d\nNome: %s\nSenha: %s\nEmail: %s\n\n",
                gestores[i].id, gestores[i].nome, gestores[i].senha, gestores[i].email);
        } 
        
    }

    void imprimirMobilidadeEletrica(MobilidadeEletrica *mobilidadeFixa) {
        printf("\n\nMobilidade Eletrica:\nID: %d\nTipo: %s\nEstado: %s\nLocalizacao: %s\nAutonomia: %s\nBateria: %d\nPreco: %.2f\n\n",
                mobilidadeFixa->id, mobilidadeFixa->tipo, mobilidadeFixa->estado, mobilidadeFixa->localizacao, mobilidadeFixa->autonomia, mobilidadeFixa->bateria, mobilidadeFixa->preco);
        
        int i, j;

        //Listar por ordem descrescente autonomia
        for (i = 0; i < numVeiculos - 1; i++){
            for (j = 0; j < numVeiculos - i - 1; j++){
                if (veiculos[j].autonomia < veiculos[j + 1].autonomia){
                    MobilidadeEletrica temp = veiculos[j];
                    veiculos[j] = veiculos[j+1];
                    veiculos[j+1] = temp;
                }
            }
        }
        for (int i = 0; i < numVeiculos; i++) {
                printf("\nID: %d\n", veiculos[i].id);
                printf("Tipo: %s\n", veiculos[i].tipo);
                printf("Estado: %s\n", veiculos[i].estado);
                printf("Localizacao: %s\n", veiculos[i].localizacao);
                printf("Autonomia: %s\n", veiculos[i].autonomia);
                printf("Bateria: %d\n", veiculos[i].bateria);
                printf("Preco: %.2f\n", veiculos[i].preco);
        }         
    }

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
                ImprimirGestor(gestorFixo);
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
                        case 2:
                            system("cls");
                            printf("\n\nClientes:\n");
                            for (int i = 0; i < numClientes; i++) {
                                printf("ID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                                    clientes[i].id, clientes[i].nome, clientes[i].email, clientes[i].saldo);
                            }
                            // Alterar um cliente do array "clientes"
                            printf("Digite o ID do cliente que deseja alterar: ");
                            int idAlterar;
                            scanf("%d", &idAlterar);
                            int indiceAlterar = -1;
                            for (int i = 0; i < numClientes; i++) {
                                if (clientes[i].id == idAlterar) {
                                    indiceAlterar = i;
                                    break;
                                }
                            }
                            if (indiceAlterar != -1) {
                                printf("\nDigite o novo nome do cliente: ");
                                scanf("%s", &clientes[indiceAlterar].nome);
                                printf("\nDigite o novo email do cliente: ");
                                scanf("%s", &clientes[indiceAlterar].email);
                                printf("\nDigite o novo saldo do cliente: ");
                                scanf("%f", &clientes[indiceAlterar].saldo);
                                getchar(); //

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

                                printf("\nCliente alterado com sucesso!\n");
                            } else {
                                printf("\nCliente nao encontrado!\n");
                            }
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
            break;
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

                        case 2:
                            system("cls");
                            printf("\n\nGestores:\n");
                            for (int i = 0; i < numGestores; i++) {
                                printf("ID: %d\nNome: %s\nSenha: %s\nEmail: %s\n\n",
                                    gestores[i].id, gestores[i].nome, gestores[i].senha, gestores[i].email);
                            }
                            // Alterar um Gestor do array "clientes"
                            printf("Digite o ID do gestor que deseja alterar: ");
                            int idAlterar;
                            scanf("%d", &idAlterar);
                            int indiceAlterar = -1;
                            for (int i = 0; i < numGestores; i++) {
                                if (gestores[i].id == idAlterar) {
                                    indiceAlterar = i;
                                    break;
                                }
                            }
                            if (indiceAlterar != -1) {
                                printf("\nDigite o novo nome do gestor: ");
                                scanf("%s", &gestores[indiceAlterar].nome);
                                printf("\nDigite a nova senha do gestor: ");
                                scanf("%s", &gestores[indiceAlterar].senha);
                                printf("\nDigite o novo email do gestor: ");
                                scanf("%s", &gestores[indiceAlterar].email);
                                getchar(); //

                                // Abrir o arquivo binário em modo de escrita
                                arquivoGestor = fopen("gestores.bin", "wb");
                                if (arquivoGestor == NULL) {
                                    printf("Erro ao abrir o arquivo");
                                    exit(1);
                                }

                                // Gravar o novo array "gestores" no arquivo binário
                                fwrite(gestores, sizeof(Gestor), numGestores, arquivoGestor);

                                // Fechar o arquivo
                                fclose(arquivoGestor);

                                printf("\nGestor alterado com sucesso!\n");
                            } else {
                                printf("\nGestor nao encontrado!\n");
                            }
                            break;

                        case 3:
                            system("cls");
                            printf("\n\nGestores:\n");
                            for (int i = 0; i < numGestores; i++) {
                                printf("\nID: %d\n", gestores[i].id);
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
            case 6:
                do{
                    system("cls");
                    GestaoMobilidade();
                    scanf("%d", &OpcaoGestaoMobilidade);
                    getchar(); // Limpar o buffer do teclado

                    switch (OpcaoGestaoMobilidade){
                        case 1:
                            system("cls");
                            AdicionarMobilidadeEletrica(&veiculos, &numVeiculos);
                            // Abrir o arquivo binário em modo de escrita
                            arquivoMobilidade = fopen("mobilidade.bin", "wb");
                            if (arquivoMobilidade == NULL) {
                                printf("Erro ao abrir o arquivo");
                                exit(1);
                            }

                            // Gravar o array "clientes" no arquivo binário
                            fwrite(veiculos, sizeof(MobilidadeEletrica), numVeiculos, arquivoMobilidade);

                            // Fechar o arquivo
                            fclose(arquivoMobilidade);
                            break;

                        case 2:
                            system("cls");
                            printf("\n\nMobilidade:\n");
                            for (int i = 0; i < numVeiculos; i++) {
                                printf("ID: %d\nTipo: %s\nLocalizacao: %s\nAutonomia: %s\nbateria: %d\nPreco: %f\n\n",
                                    veiculos[i].id, veiculos[i].tipo, veiculos[i].localizacao, veiculos[i].autonomia, veiculos[i].bateria, veiculos[i].preco);
                            }
                            // Alterar um Meio do array "veiculos"
                            printf("Digite o ID do veiculo que deseja alterar: ");
                            int idAlterar;
                            scanf("%d", &idAlterar);
                            int indiceAlterar = -1;
                            for (int i = 0; i < numVeiculos; i++) {
                                if (veiculos[i].id == idAlterar) {
                                    indiceAlterar = i;
                                    break;
                                }
                            }
                            if (indiceAlterar != -1) {
                                printf("\nDigite o novo tipo do veiculo: ");
                                scanf("%s", &veiculos[indiceAlterar].tipo);
                                printf("\nDigite a nova localizacao do veiculo: ");
                                scanf("%s", &veiculos[indiceAlterar].localizacao);
                                printf("\nDigite a autonomia do veiculo: ");
                                scanf("%s", &veiculos[indiceAlterar].autonomia);
                                printf("\nDigite a percentagem de bateria do veiculo: ");
                                scanf("%d", &veiculos[indiceAlterar].bateria);
                                printf("\nDigite o preco do veiculo: ");
                                scanf("%f", &veiculos[indiceAlterar].preco);
                                getchar(); //

                                // Abrir o arquivo binário em modo de escrita
                                arquivoMobilidade = fopen("mobilidade.bin", "wb");
                                if (arquivoMobilidade == NULL) {
                                    printf("Erro ao abrir o arquivo");
                                    exit(1);
                                }

                                // Gravar o novo array "gestores" no arquivo binário
                                fwrite(veiculos, sizeof(MobilidadeEletrica), numVeiculos, arquivoMobilidade);

                                // Fechar o arquivo
                                fclose(arquivoMobilidade);

                                printf("\nMeio alterado com sucesso!\n");
                            } else {
                                printf("\nMeio nao encontrado!\n");
                            }
                            break;

                        case 3:
                            system("cls");
                            printf("\n\nMobilidade:\n");
                            for (int i = 0; i < numVeiculos; i++) {
                                printf("ID: %d\n", veiculos[i].id);
                                printf("Tipo: %s\n", veiculos[i].tipo);
                                printf("Estado: %s\n", veiculos[i].estado);
                                printf("Localizacao: %s\n", veiculos[i].localizacao);
                                printf("Autonomia: %s\n", veiculos[i].autonomia);
                                printf("Bateria: %d\n", veiculos[i].bateria);
                                printf("Preco: %.2f\n", veiculos[i].preco);
                                }
                                // Remover um cliente do array "gestores"
                                printf("\nDigite o ID do veiculo que deseja remover: ");
                                int idRemover;
                                scanf("%d", &idRemover);
                                int indiceRemover = -1;
                                for (int i = 0; i < numVeiculos; i++) {
                                    if (veiculos[i].id == idRemover) {
                                        indiceRemover = i;
                                        break;
                                    }
                                }
                                if (indiceRemover != -1) {
                                    for (int i = indiceRemover; i < numVeiculos - 1; i++) {
                                        veiculos[i] = veiculos[i + 1];
                                    }
                                    numVeiculos--;

                                    // Abrir o arquivo binário em modo de escrita
                                    arquivoMobilidade = fopen("mobilidade.bin", "wb");
                                    if (arquivoMobilidade == NULL) {
                                        printf("Erro ao abrir o arquivo");
                                        exit(1);
                                    }

                                    // Gravar o novo array "clientes" no arquivo binário
                                    fwrite(veiculos, sizeof(MobilidadeEletrica), numVeiculos, arquivoMobilidade);

                                    // Fechar o arquivo
                                    fclose(arquivoMobilidade);

                                    printf("\nMeio removido com sucesso!\n");
                                } else {
                                    printf("\nMeio nao encontrado!\n");
                                }
                            break;

                        case 0:
                            system("cls");
                            break;

                    default:
                        printf("\n\nOpcao invalida! Tente novamente.\n");
                        break;
                    }

                }while (OpcaoGestaoMobilidade != 0);
            break;
            case 7:
                system("cls");
                atribuirAluguer(clientes, numClientes, veiculos, numVeiculos);
            break;
            case 8:
                system("cls");
                listarAlugueres();
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