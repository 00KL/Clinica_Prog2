//1. MARCAÇÃO SEMANAL CONSULTAS

//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>


//Aquivos necessarios
//descide q será mais organizado trabalhar
//criando varios arquivos e importando
//suas funcoes nos outros arquivos
//pois assim poderemos modualizar melhor
#include "structs.c"

/*
//Funcoes feitas nesse arquivo
void linhaEspecifica(FILE *, int , char *);
void pedirLinha(FILE *, char *);

//Essa função ira ler uma linha especifica do codigo
//o objetivo e extrair as linhas q tem os horarios
//e dias de atendimento de um medico X para montar
//o calendario dele o q é a primeira questãoo da lista
void linhaEspecifica(FILE *medico, int linha, char *str){
  int contador = 0;
  char lixo[50];
  while(!feof(medico)){
    contador++;
    if(contador == linha){
      fgets(str, 30, medico);
    }
    else{
      fgets(lixo,50, medico);
    }

    exibeStr(str);
  }

}

//Essa aqui é so para chamar a função de cima e poluir
//menos a função principal desse arquivo
void pedirLinha(FILE *medico, char *str){
  scanf("%d", linha);
  linhaEspecifica(medico, linha, str);
}

//funcao para criar a tabela de horarios
//Essa é a função principal desse arquivo
//nela se pretende realizar a função de
//extrair as datas e horarios de um medico X
//e converter em um calendario
void leitura(){
  //variaveis
  FILE *medico;
  char str[dim], str1[dim+7] = "dados/";

  //leitura dos dados do medicos
  medico = fopen ("dados/dadosMedicos.txt","r" );

  pedirLinha(medico, str);
  //fgets(str, 30, medico);

  //strcat(str1, str);

  //medico = fopen (str1, "w+");

  //exibeStr(str1);

}
*/
