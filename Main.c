#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//arquivos com funções necessárias
#include "preenche.c"

int main(){

    //Criação de structs
    agMedico medico;
    cliente paciente;
    agFaixaEtaria atualizacao;

    //variaveis necessárias
    FILE *arqSaida, *arqEntrada, *arqLista;


    //função q irá executar os objetivos no enunciado
    preencheMedi(&medico, arqEntrada, arqLista, &atualizacao, &paciente);

    return 0;
}
