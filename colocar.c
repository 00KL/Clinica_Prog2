//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "preenche.c"
#include "semanas.c"
#include "buscaHorarios.c"

//Constantes estabelicdas no enunciado
#define dim 30
#define h 10
#define d 5

//funcoes
void colocar(FILE *, agMedico *, FILE *, char *);

void buscaHorarios(agMedico *, int *, int , int ,FILE *, char *);

void colocar(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    int indice, posicao[h], cont = 0;

    buscaHorarios(medico, posicao, indice, cont, arqEntrada, str);

}

void buscaHorarios(agMedico *medico,int *posicao,int indice, int cont, FILE *arqEntrada, char *str){

    char check;

  do{
        colocarValores(medico, posicao, indice, cont, arqEntrada, str);
        check = str[0];

    } while(check != '\n' && !feof(arqEntrada) );
}
