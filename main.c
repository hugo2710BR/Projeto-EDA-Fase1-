#include <stdio.h>
#include <stdlib.h>
#include "MobilidadeEletrica.h"
#include "Cliente.h"
#include "Gestor.h"

void menu(){
    printf("\nMENU:\n");
    printf("1 - Listar Mobilidade Eletrica\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Listar Gestores\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

int main(void) {
    MobilidadeEletrica* mobilidadeFixa = CriarMobilidadeEletricaFixa();
    Cliente* clienteFixo = CriarClienteFixo();
    Gestor* gestorFixo = CriarGestorFixo();

    int opcao;
    do{
        menu();
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado
        
        switch(opcao){
            case 1:
                system("cls");
                printf("\n\nMobilidade Eletrica Fixa:\nID: %d\nTipo: %s\nEstado: %s\nLocalizacao: %s\nBateria: %d%%\nPreco: %.2f\n\n",
                    mobilidadeFixa->id, mobilidadeFixa->tipo, mobilidadeFixa->estado, mobilidadeFixa->localizacao, mobilidadeFixa->bateria, mobilidadeFixa->preco);
                break;

            case 2:
                system("cls");
                printf("\n\nCliente Fixo:\nID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
                    clienteFixo->id, clienteFixo->nome, clienteFixo->email, clienteFixo->saldo);
                break;

            case 3:
                system("cls");
                printf("\n\nGestor Fixo:\nID: %d\nNome: %s\nEmail: %s\nSenha: %s\n\n",
                    gestorFixo->id, gestorFixo->nome, gestorFixo->email, gestorFixo->senha);
                break;

            case 0:
                system("cls");
                printf("Saindo...\n");
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
