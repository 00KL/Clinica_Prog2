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
int pacienteMedico(agMedico *, FILE *);

void colocar(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    int indice, posicao[h], cont = 0, semana;

    preencheMatriz(medico);

    buscaHorarios(medico, posicao, indice, cont, arqEntrada, str);

    semanas(medico, arqSaida, semana);

}

int pacienteMedico(agMedico *medico, FILE *dadosPacientes){

  char nomeMedico[dim]={0},lixo[1];
  int id=0;

  //fscanf(dadosPacientes,"%s\n%d\n%s\n%s\n%s\n", lixo, &id, lixo1, lixo2, nomeMedico);

    fscanf(dadosPacientes, "%c", &lixo[0]);
    fgets(lixo, 30, dadosPacientes);
    //printf("%s", lixo);
    fscanf(dadosPacientes,"%d", &id);
    fgets(lixo, 30, dadosPacientes);
    //printf("%s", lixo);
    fgets(lixo, 30, dadosPacientes);
    //printf("%s", lixo);
    fgets(lixo, 30, dadosPacientes);
    //printf("%s", lixo);
    fgets(nomeMedico, 30, dadosPacientes);
  //  printf("%s", nomeMedico);

    //scanf("%c", &lixo[0]);


    //printf("\n%s   %d\n", nomeMedico, id);

  if(!(strcmp(nomeMedico, medico->nome))){
    //printf("%d\n",id);
    return id;
  }

  return 0;

}

void preencheMatriz(agMedico *medico){
  FILE *dados;

  if (!(dados = fopen("listaPacientes­Semana1.txt", "r"))){
    printf("Tortona pra esquerda\n");
      exit(1);
    }


    for(int ho = 0; ho < h; ho++){

        for(int di = 0; di < d; di++){
            if(!feof(dados)){
                medico->agenda[ho][di] = pacienteMedico(medico,dados);
            }
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
