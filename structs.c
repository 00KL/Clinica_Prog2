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
void preencheMedicos( agMedico *pessoa){
    //anuncio da varaivel q ira receber
    //o endereco do arquivo
    FILE *arq;
    //varaivel
    char lixo, str[dim];

    //leitura do arquivo dos medicos
    arq = fopen("dados/dadosMedicos.txt", "r");

    fgets(str, 30, arq);

    for(int i = 0; i < 30 ; i++){
         pessoa->nome[i] = str[i];
    }

    /*
    printf("Digite o codigo do médico: ");
    scanf("%d", &pessoa->id);
    scanf("%c",&lixo);

    printf("Digite o especialidade do médico:");
    for(int i = 0; pessoa->especialidade[i-1] != '\n'; i++){
        scanf("%c", &pessoa->especialidade[i]);
    }
    printf("\n");*/
}


//Apenas um tipo para testes
//ja que eu n estava domindo bem as tecnicas de struct
typedef struct {
    char nome[dim];
} test;

//N será necessário exibir para o usuário
//uma string, porem para nos será importante
//para testar os valores q estão sendo registrados
//nos campos de uma string
void exibeStr(char *str){
  printf("minha rola\n" );

  for(int i = 0; str[i] != '\0'; i++)
    printf("%c", str[i]);

}
