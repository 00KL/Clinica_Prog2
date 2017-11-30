//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes estabelicdas no enunciado
#define dim 30
#define h 10
#define d 5

void exibeStr(char *);


typedef struct {
    char nome[dim];
    int id;
    char especialidade[dim];
    int agenda[h][d];
} agMedico;

typedef struct {
   char nome[dim];
    int id;
    long int fone;
    int idade;
    char medico[dim];
} cliente;


void preencheMedicos( agMedico *pessoa){

    char lixo;
    printf("Digite o nome do médico: ");
    for(int i = 0; pessoa->nome[i-1] != '\n'; i++){
        scanf("%c", &pessoa->nome[i]);
    }

    printf("Digite o codigo do médico: ");
    scanf("%d", &pessoa->id);
    scanf("%c",&lixo);

    printf("Digite o especialidade do médico:");
    for(int i = 0; pessoa->especialidade[i-1] != '\n'; i++){
        scanf("%c", &pessoa->especialidade[i]);
    }
    printf("\n");
}

typedef struct {
    char nome[dim];
} test;

void exibeStr(char *str){
  printf("minha rola\n" );

  for(int i = 0; str[i] != '\0'; i++)
    printf("%c", str[i]);

}
