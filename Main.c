#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//arquivos com funções necessárias
#include "preenche.c"

//Funções usadas nesse arquivo
void finalDeArquivo(FILE *);


int main(){
    //Criação de objeto medico
    agMedico medico;

    //variaveis necessárias
    FILE *arqSaida, *arqEntrada, *arqLista;

    //função q irá executar os objetivos no enunciado
    preencheMedi(&medico, arqEntrada, arqLista);

    return 0;
}
