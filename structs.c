//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes estabelicdas no enunciado
#define dim 30
#define h 10
#define d 5


//Tipo definido no enunciado
typedef struct {
    char nome[dim];
    int id;
    char especialidade[dim];
    int agenda[h][d];
} agMedico;




//Tipo definido no enunciado
typedef struct {
   char nome[dim];
    int id;
    long int fone;
    int idade;
    char medico[dim];
} cliente;

//Forma de preencher o medico em questão
//ate o momento n encontrei uma utilidade
//ja q ao acabar de ler o enunciado eu notei
//q registrar medico n é uma funcao
//q precisa ser feita
//mas n apaga pq pode ser util


//Apenas um tipo para testes
//ja que eu n estava domindo bem as tecnicas de struct
typedef struct {
    char nome[dim];
} test;

//N será necessário exibir para o usuário
//uma string, porem para nos será importante
//para testar os valores q estão sendo registrados
//nos campos de uma string



//Os arquivos estavam sendo criados com uma '?'
//no final, essa interrogacao se dava pela presenca
//de um '\n' no final da string retirada do arquivo
//pela funcao "fgets"
void retiraInterrogacao(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] = '\0';
        }
    }
}