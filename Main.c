#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//arquivos com funções necessárias
#include "preenche.c"

int main(){

    char nTeste[1];

    printf("Informe o numero do teste que sera executado:\n");
    scanf("%c", nTeste);

    teste(nTeste);
    //função q irá executar os objetivos no enunciado
    //preencheMedi(&medico, arqEntrada, arqLista, &resultado, &atualizacao, &paciente);

    return 0;
}
