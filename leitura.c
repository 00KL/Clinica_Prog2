//1. MARCAÇÃO SEMANAL CONSULTAS

//Bibliotecas necessárias
#include <stdio.h>
#include <stdlib.h>


//Aquivos necessarios
//descide q será mais organizado trabalhar
//criando varios arquivos e importando
//suas funcoes nos outros arquivos
//pois assim poderemos modualizar melhor
#include "exibe.c"

//Funcoes desse codigo
void preencheMedicos( agMedico *, FILE *, FILE *, char *);
void inserirValor(char *, agMedico *);
void criaArquivoMedico(FILE *, agMedico *, FILE *, char *, char *);
void dadosMedico(FILE *, agMedico *, FILE *, char *);
void preencheMedicosFILHADAPUTAVAISEFUDER( agMedico *, FILE *, FILE *);


void procuraMedico(agMedico *medico ){

    char str[dim] = {0}, nomeArq[dim+4];

    FILE *arqEntrada, *arqSaida;

    if (!(arqEntrada = fopen("dadosMedicos.txt", "r"))){
        exit(1);
    }

    fgets(str,  30, arqEntrada);
    while(str[0] != '\n'){
      //printf("rola tortona");
      preencheMedicos(medico, arqEntrada, arqSaida, str);
      fgets(str,  30, arqEntrada);
    }

    //preencheMedicos(medico, arqEntrada, arqSaida);
    //preencheMedicos(medico, arqEntrada, arqSaida);
    //preencheMedicos(medico, arqEntrada, arqSaida);
    //preencheMedicos(medico, arqEntrada, arqSaida);
}

void preencheMedicos( agMedico *medico, FILE *arqEntrada, FILE *arqSaida, char *str){
    //anuncio da varaivel q ira receber
    //o endereco do arquivo

    //varaivel
    char /*str[dim] = {0},*/ nomeArq[dim+4] = {0};

    //fgets(str,  30, arqEntrada);


    //funcao para criar arquivo com o nome do medico
    criaArquivoMedico(arqEntrada, medico, arqSaida, str, nomeArq);

    if (!(arqSaida = fopen (nomeArq, "w"))){
        printf("test \n");
        exit(1);
    }

    //funcao para incerir dados do medico
    dadosMedico(arqEntrada, medico, arqSaida, str);

    //Colocar e gerar horarios
    colocar(arqEntrada, medico, arqSaida, str);



}

void inserirValor(char *str, agMedico *medico){
    int hora = 0, dia, aux;
    dia = str[0] - 50;

    preencheMatriz(medico);

    //exibeMatriz(medico);


    for(int ho = 4; ho < 11 ; ho+=3){
        for(int i = 0; i < h; i++){
            //printf("%d\n", '10' );
            if( i == (str[ho] - 50) ){
                //printf("minha rola tortona");
                medico->agenda[i][dia] = -1;
                i = h;
            }
        }

    }


    //exibeMatriz(medico);


}

void criaArquivoMedico(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str, char *str1){

    //retira nome do arquivo
    //fgets(str, 30, arqEntrada);
    //printf("%s ", str );

    //exibeStr(str);

    //Coloca .txt no final do arquivo
    strcat(str1, str);
    retiraInterrogacao(str1);
    strcat(str1, ".txt");
    printf("%s ", str1 );

    //Cria arquivo
    //arqSaida = fopen (str1, "w");


    //coloca nome em pessoa
    for(int i = 0; i < 30 ; i++){
         medico->nome[i] = str[i];
    }
}

void dadosMedico(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    fprintf(arqSaida, "%s", str);

    fgets(str, 30, arqEntrada);

    fprintf(arqSaida, "%s", str);

    fgets(str, 30, arqEntrada);

    fprintf(arqSaida, "%s", str);

    fprintf(arqSaida, "\nQuadro de consultas semanais\n");

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
