/*void inserirValor(char *str, agMedico *medico){
    int hora = 0, dia, aux;
    dia = str[0] - 50;

    preencheMatriz(medico);

    for(int ho = 4; ho < 11 ; ho+=3){
        for(int i = 0; i < h; i++){
            if( i == (str[ho] - 50) ){
                medico->agenda[i][dia] = -1;
                i = h;
            }
        }
    }

}*/


/*
    for(int i = 0; lucas.nome[i] != '\0'; i++){
        printf("%c", lucas.nome[i]);
    }

    printf("\n");

    for(int i = 0; lucas.especialidade[i] != '\0'; i++){
        printf("%c", lucas.especialidade[i]);
    }


    //Aparentemente é necessário por esse expoço para evitar
    //a exibição de "lixo" que esta na memoria
    printf("\n");
    printf("tortona\n");

    printf("\n");


    for(int i = 0; i < dim; i++){
        scanf("%c", &lucas.nome[i]);

        if(lucas.nome[i] == '.'){
            fim = i;
            i = dim;
            lucas.nome[i] = ' ';
        }
    }

    printf("\n");




    for(int i; i < dim; i++){
        printf("%c", lucas.nome[i]);
    }

    */

    //1. MARCAÇÃO SEMANAL CONSULTAS

    //Bibliotecas necessárias
    #include <stdio.h>
    #include <stdlib.h>


    //Aquivos necessarios
    //decide q será mais organizado trabalhar
    //criando varios arquivos e importando
    //suas funcoes nos outros arquivos
    //pois assim poderemos modularizar melhor
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

    /*void semanas(agMedico *medico, FILE *arqSaida){

        int semana;

        char comesoNome[dim], fimNome[5] = {0};

        FILE *arqLista;

        for(semana = 1; semana < 5; semana++){

            strcpy(fimNome, " .txt");
            fimNome[0] = semana + 48;

            strcpy(comesoNome, "entrada/listaPacientes­Semana");
            strcat(comesoNome, fimNome);

            if (!(arqLista = fopen("entrada/listaPacientesSemana1.txt", "r"))){
                printf("ERRO2 \n");
                exit(1);
            }
        }

        exit(1);


        for(semana = 1; semana < 5; semana++){
            escreveMatriz(medico, arqSaida, semana);
        }
    }*/
