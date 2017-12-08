//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colocar.c"

void preencheMedico(agMedico *, FILE *, FILE *, FILE *);

void diasOcupados(agMedico *, FILE *);
void preencheMatriz(agMedico *);
void exebeMatriz(agMedico *, FILE *arqSaida);

void nomesListas(FILE *, agMedico *);
void nomeLista(FILE *, char *, char *, int *);

void aleatorio(agMedico *, int , char *);

int compStr(char *, char *);


void preencheMedi(agMedico *medico, FILE *arqMedico, FILE *arqLista){
    char comesoNome[dim], fimNome[5] = {0};

    //fgets(str, 30, arqMedico);

    FILE *arqSaida;

    if (!(arqSaida = fopen ("saida/Joao Silva da Costa.txt", "w"))){
        printf("ERRO \n");
        exit(1);
    }


    for(int semana = 1; semana < 5; semana++){

        if (!(arqMedico = fopen ("entrada/dadosMedicos.txt", "r"))){
            printf("ERRO\n");
            exit(1);
        }

        strcpy(fimNome, " .txt");
        fimNome[0] = semana + 48;

        strcpy(comesoNome, "entrada/listaPacientesSemana");
        strcat(comesoNome, fimNome);

        if (!(arqLista = fopen("entrada/listaPacientesSemana4.txt", "r"))){
            printf("%s \ntortona pra esquerda \n", comesoNome);
            exit(1);
        }

        preencheMedico(medico, arqMedico, arqLista, arqSaida);

        fclose(arqLista);
        fclose(arqMedico);

    }

    /*
    //while(!(feof(arqMedico))){

      if (!(arqLista = fopen ("entrada/listaPacientes­Semana1.txt", "r"))){
          printf("ERRO \n");
          exit(1);
      }

      preencheMedico(medico, arqMedico, arqLista, arqSaida);

      fclose(arqLista);
      //printf("\n\n\n");
    //}

      */
}

void preencheMedico(agMedico *medico, FILE *arqMedico, FILE *arqLista, FILE *arqSaida){

    fgets(medico->nome, dim, arqMedico);

    fscanf(arqMedico, "%d\n", &medico->id);

    fgets(medico->especialidade, dim, arqMedico);

    preencheMatriz(medico);

    diasOcupados(medico, arqMedico);

    //nomesListas(arqLista, medico);

    //exebeMatriz(medico, arqSaida);

    //escreveMatriz(medico, arqSaida, 1);

    //semanas(medico, arqSaida);
}

void preencheMatriz(agMedico *medico){
    for(int ho = 0; ho < h; ho++){

        for(int di = 0; di < d; di++){

            if(ho == 4){
                medico->agenda[ho][di] = -1;
            }else{
                medico->agenda[ho][di] = 0;
            }

        }
    }
}

void diasOcupados(agMedico *medico, FILE *arqMedico){

    int dia, hora;
    char check = ' ';


        fscanf(arqMedico, "%d", &dia);
    do{

        fscanf(arqMedico, "a ");

        do{

            fscanf(arqMedico, "%d%c", &hora, &check);

            medico->agenda[hora - 8][dia - 2] = -1;

            //printf("%d %d \n", hora, dia);
            //printf("rola tortona");
            printf("%c\n", check);


        }while(check != '\n');

        fscanf(arqMedico, "%c", &check);

        dia = check - 48;

    }while(check != '\n');


}

void exebeMatriz(agMedico *medico, FILE *arqSaida){

    

    for(int ho = 0; ho < h; ho++){
        for(int di = 0; di < d; di++){
            if(medico->agenda[ho][di] == 0){

                printf(" %d  ", medico->agenda[ho][di]);

            }else if(medico->agenda[ho][di] == -1){

                printf("%d  ", medico->agenda[ho][di]);

            }else{

                printf("%d ", medico->agenda[ho][di]);
            }


        }
        printf("\n");
    }
}

void aleatorio(agMedico *medico, int id, char *nome){

    int hora =  rand()%9;
    int dia = rand()%4;

    if(medico->agenda[dia][hora] != 0){

        while(medico->agenda[dia][hora] != id){

            hora =  rand()%9;
            dia = rand()%4;

            if(medico->agenda[dia][hora] == 0){

                medico->agenda[dia][hora] = id;
            }
        }
    }else{
        medico->agenda[dia][hora] = id;
    }

}

void nomeLista(FILE *arqLista, char *nomeMedico, char *lixo, int *id){
    fgets(lixo, 30, arqLista);
    fscanf( arqLista ,"%d\n", id);
    fgets(lixo, 30, arqLista);
    fgets(lixo, 30, arqLista);
    fgets(nomeMedico, dim, arqLista);

    //printf("%d \n%s", *id, nomeMedico);
}

void nomesListas(FILE *arqLista, agMedico *medico){
    char nomeMedico[dim], lixo[dim];
    int id;

    srand(time(NULL) );

    while(! feof(arqLista) ){
        nomeLista(arqLista, nomeMedico, lixo, &id);
        //printf("%d \n", id);
        //printf("%c  %c  \n", nomeMedico[11],medico->nome[11]);

        if(compStr(nomeMedico, medico->nome)){
            //printf("%s %s\n" , nomeMedico, medico->nome);
            aleatorio(medico, id, nomeMedico);
        }

        fgets(lixo, 30, arqLista);
    }
}

int compStr(char *str, char *str1){
    int cont = 0, i = 0;
    for(i = 0; str[i] != '\0'; i++){
        //printf("%c  %c  \n", str[i], str1[i]);
        if(str[i] == str1[i]){
            cont ++;
        }
    }

    if(cont == i){
        //printf("%s", str);
        return 1;
    }
    return 0;
}
