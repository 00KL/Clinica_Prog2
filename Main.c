#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//arquivos com funções necessárias
#include "preenche.c"



int main(){

    //Criação de structs
    agMedico medico;
    agFaixaEtaria resultado, atualizacao;

    //variaveis necessárias
    FILE *arqSaida, *arqEntrada, *arqLista;


    //função q irá executar os objetivos no enunciado
    preencheMedi(&medico, arqEntrada, arqLista, &resultado, &atualizacao);

    return 0;
}
