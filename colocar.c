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
int compStr(char *, char *);

void colocar(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    //printf("%s", medico->nome);

    int indice, posicao[h], cont = 0, semana;

    preencheMatriz(medico);

    buscaHorarios(medico, posicao, indice, cont, arqEntrada, str);

    semanas(medico, arqSaida, semana);

}

int pacienteMedico(agMedico *medico, FILE *dadosPacientes){

  char nomeMedico[dim],lixo[1];
  int id=0;


  //fscanf(dadosPacientes, "%c", &lixo[0]);
  fgets(lixo, 30, dadosPacientes);
  //printf("%s", lixo);
  fscanf(dadosPacientes,"%d", &id);
  //printf("%d\n",id);
  fgets(lixo, 30, dadosPacientes);
  //printf("%s", lixo);
  fgets(lixo, 30, dadosPacientes);
  //printf("%s", lixo);
  fgets(lixo, 30, dadosPacientes);
  //printf("%s", lixo);
  fgets(nomeMedico, 30, dadosPacientes);
  printf("%s", medico->nome);
  printf("%s", nomeMedico);
  fgets(lixo, 30, dadosPacientes);
  //printf("%s\n",lixo);*/


  //printf("%d ",strcmp(nomeMedico, medico->nome) );
  if(compStr(medico->nome, nomeMedico)){
    //printf("%s",nomeMedico);
    //printf("%s\n", medico->nome);
    return id;
  }

  return 0;

}

int compStr(char *str1, char *str2){
  int contador=0;

  for(int i = 0; i < 18; i++){
    printf(" %c    %c  \n", str1[i],str2[i]);
    if(str1[i]==str2[i]){

      contador++;
    }
  }
  printf("\n");

  if(contador==strlen(str1)){
    return 1;
  }

  return 0;
}

void preencheMatriz(agMedico *medico){
  int teste;

  FILE *dados;

  if (!(dados = fopen("listaPacientes­Semana1.txt", "r"))){
      exit(1);
    }

    for(int ho = 0; ho < h; ho++){

        for(int di = 0; di < d; di++){
            if(!feof(dados)){
                //printf("%s",medico->nome);
                medico->agenda[ho][di] = pacienteMedico(medico,dados);


                      //teste = pacienteMedico(medico,dados);
                      //printf("%d\n",teste);
            }

            else if(ho == 4){
                medico->agenda[ho][di] = -1;
            }
            else {
                medico->agenda[ho][di] = 0;
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
