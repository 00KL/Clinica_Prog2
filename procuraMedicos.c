//1. MARCAÇÃO SEMANAL CONSULTAS

//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>


//Aquivos necessarios
//decide q será mais organizado trabalhar
//criando varios arquivos e importando
//suas funcoes nos outros arquivos
//pois assim poderemos modualizar melhor
#include "colocar.c"

//Funcoes desse codigo
void procuraMedico(agMedico * );
void preencheMedicos( agMedico *, FILE *, FILE *, char *);

void criaArquivoMedico(FILE *, agMedico *, FILE *, char *, char *);
void dadosMedico(FILE *, agMedico *, FILE *, char *);
void inserirValor(char *, agMedico *);


void procuraMedico(agMedico *medico ){

    char str[dim] = {0};

    FILE *arqEntrada, *arqSaida;

    if (!(arqEntrada = fopen("entrada/dadosMedicos.txt", "r"))){
        exit(1);
    }

    fgets(str, 30, arqEntrada);


    while(!(feof(arqEntrada))){
      preencheMedicos(medico, arqEntrada, arqSaida, str);
      fgets(str, 30, arqEntrada);
    }

}

void preencheMedicos( agMedico *medico, FILE *arqEntrada, FILE *arqSaida, char *str){
    //anuncio da variavel q ira receber
    //o endereco do arquivo
    //printf("%s\n",str);
    strcpy(medico->nome,str);
    //variavel
    char nomeArq[dim+10] = {0};


    //funcao para criar arquivo com o nome do medico
    criaArquivoMedico(arqEntrada, medico, arqSaida, str, nomeArq);

    if (!(arqSaida = fopen (nomeArq, "w"))){
        printf("test \n");
        exit(1);
    }

    //funcao para incerir dados do medico
    dadosMedico(arqEntrada, medico, arqSaida, str);

    //printf("%s", medico->nome);
    //Colocar e gerar horarios
    colocar(arqEntrada, medico, arqSaida, str);

}


void criaArquivoMedico(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str, char *str1){

    //Coloca .txt no final do arquivo
    strcat(str1, "saida/");
    strcat(str1, str);
    retiraInterrogacao(str1);
    strcat(str1, ".txt");

}

void dadosMedico(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){


    fprintf(arqSaida, "%s", str);

    fgets(str, 30, arqEntrada);

    fprintf(arqSaida, "%s", str);

    fgets(str, 30, arqEntrada);

    fprintf(arqSaida, "%s", str);

    fprintf(arqSaida, "\nQuadro de consultas semanais\n");

}
