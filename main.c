#include <stdio.h>
#include "MobilidadeEletrica.h"
#include "Cliente.h"
#include "Gestor.h"

int main(void) {
    MobilidadeEletrica* mobilidadeFixa = CriarMobilidadeEletricaFixa();
    Cliente* clienteFixo = CriarClienteFixo();
    Gestor* gestorFixo = CriarGestorFixo();

    printf("\n\nMobilidade Eletrica Fixa:\nID: %d\nTipo: %s\nEstado: %s\nLocalizacao: %s\nBateria: %d%%\nPreco: %.2f\n\n",
        mobilidadeFixa->id, mobilidadeFixa->tipo, mobilidadeFixa->estado, mobilidadeFixa->localizacao, mobilidadeFixa->bateria, mobilidadeFixa->preco);

    printf("Cliente Fixo:\nID: %d\nNome: %s\nEmail: %s\nSaldo: %.2f\n\n",
        clienteFixo->id, clienteFixo->nome, clienteFixo->email, clienteFixo->saldo);

    printf("Gestor Fixo:\nID: %d\nNome: %s\nEmail: %s\nSenha: %s\n\n",
        gestorFixo->id, gestorFixo->nome, gestorFixo->email, gestorFixo->senha);

    free(mobilidadeFixa);
    free(clienteFixo);
    free(gestorFixo);

    return 0;
}
