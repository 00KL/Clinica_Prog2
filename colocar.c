//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.c"
#include "semanas.c"
#include "buscaHorarios.c"

//Constantes estabelicdas no enunciado
#define dim 30
#define h 10
#define d 5

//funcoes
void colocar(FILE *, agMedico *, FILE *, char *);
void preencheMatriz(agMedico *medico);
void buscaHorarios(agMedico *, int *, int , int ,FILE *, char *);
void semanas(agMedico *, FILE *, int);


void colocar(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    int indice, posicao[h], cont = 0, semana;

    preencheMatriz(medico);

    buscaHorarios(medico, posicao, indice, cont, arqEntrada, str);

    semanas(medico, arqSaida, semana);

}

void preencheMatriz(agMedico *medico){
    for(int ho = 0; ho < h; ho++){

        for(int di = 0; di < d; di++){

            medico->agenda[ho][di] = 0;
            if(ho == 4){
                medico->agenda[ho][di] = -1;
            }
        }
    }
}

void buscaHorarios(agMedico *medico,int *posicao,int indice, int cont, FILE *arqEntrada, char *str){

    char check;

  do{
        colocarValores(medico, posicao, indice, cont, arqEntrada, str);
        check = str[0];

    } while(check != '\n' && !feof(arqEntrada) );
}

void semanas(agMedico *medico, FILE *arqSaida, int semana){
    for(semana = 1; semana < 5; semana++){
        escreveMatriz(medico, arqSaida, semana);
    }
}
