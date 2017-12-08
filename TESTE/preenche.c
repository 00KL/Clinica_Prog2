//Bibliotecas relevantes para o progama
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "colocar.c"

void preencheMedico(agMedico *, FILE *, FILE *, FILE *, cliente *);

void nomeLista(char *, int);

void diasOcupados(agMedico *, FILE *, agMedico *);
void preencheMatriz(agMedico *, agMedico *);

void exebeMatriz(agMedico *, FILE *arqSaida);

void marcaHorario(FILE *, agMedico *, cliente *);
void obterPaciente(FILE *, cliente *);

void aleatorio(agMedico *, cliente *);

int compStr(char *, char *);

void copiaMatriz(agMedico *, agMedico *);


void preencheMedi(agMedico *medico, FILE *arqEntrada, FILE *arqLista, cliente *paciente){

    FILE *arqSaida;

    if (!(arqEntrada = fopen ("entrada/dadosMedicos.txt", "r"))){
        printf("ERRO1\n");
        exit(1);
    }

    while(! feof(arqEntrada)){

        preencheMedico(medico, arqEntrada, arqLista, arqSaida, paciente);

    }
}

void preencheMedico(agMedico *medico, FILE *arqEntrada, FILE *arqLista, FILE *arqSaida, cliente *paciente){
    agMedico copia;
    char nomeArq[dim+5],nomeM[dim];

    fgets(medico->nome, dim, arqEntrada);

    strcpy(nomeM,medico->nome);
    nomeM[ strlen(medico->nome) - 1 ] = '.' ;

    strcpy(nomeArq, "saida/");
    strcat(nomeArq, nomeM);
    strcat(nomeArq, "txt");

    if (!(arqSaida = fopen (nomeArq, "w"))){
        printf("ERRO \n");
        exit(1);
    }

    fprintf(arqSaida, "%s", medico->nome);

    fscanf(arqEntrada, "%d\n", &medico->id);
    fprintf(arqSaida, "%d\n", medico->id);

    fgets(medico->especialidade, dim, arqEntrada);
    fprintf(arqSaida, "%s", medico->especialidade);

    preencheMatriz(medico, &copia);

    diasOcupados(medico, arqEntrada, &copia);

    for(int semana = 1; semana < 5; semana++){
      nomeLista(nomeArq, semana);

      if (!(arqLista = fopen(nomeArq, "r"))){
          printf("%s \nERRO3 \n", nomeArq);
          exit(1);
      }

      marcaHorario(arqLista, medico, paciente);

      //exebeMatriz(medico, arqSaida);

      escreveMatriz(medico, arqSaida, semana);

      copiaMatriz(medico, &copia);

      fclose(arqLista);

    }

}

void nomeLista(char *nomeArq, int semana){

  char fimNome[5];

  strcpy(fimNome, " .txt");
  fimNome[0] = semana + 48;

  strcpy(nomeArq, "entrada/listaPacientesSemana");
  strcat(nomeArq, fimNome);

}

void preencheMatriz(agMedico *medico, agMedico *copia){
    for(int ho = 0; ho < h; ho++){

        for(int di = 0; di < d; di++){

            if(ho == 4){
                copia->agenda[ho][di] = -1;
                medico->agenda[ho][di] = -1;
            }else{
                medico->agenda[ho][di] = 0;
                copia->agenda[ho][di] = 0;
            }
        }
    }
}

void diasOcupados(agMedico *medico, FILE *arqMedico, agMedico *copia){

    int dia, hora;
    char check = '\n';


        fscanf(arqMedico, "%d", &dia);
    do{

        fscanf(arqMedico, "a ");

        do{

            fscanf(arqMedico, "%d%c", &hora, &check);

            medico->agenda[hora - 8][dia - 2] = -1;
            copia->agenda[hora - 8][dia - 2] = -1;

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

void aleatorio(agMedico *medico, cliente *paciente){

    int hora =  rand()%9;
    int dia = rand()%4;

    if(medico->agenda[dia][hora] != 0){

        while(medico->agenda[dia][hora] != paciente->id){

            hora =  rand()%9;
            dia = rand()%4;

            if(medico->agenda[dia][hora] == 0){

                medico->agenda[dia][hora] = paciente->id;
            }
        }
    }else{
        medico->agenda[dia][hora] = paciente->id;
    }

}

void obterPaciente(FILE *arqLista, cliente *paciente){
    fgets(paciente->nome, dim, arqLista);
    fscanf( arqLista ,"%d\n", &paciente->id);
    fgets(paciente->fone, dim, arqLista);
    fscanf(arqLista, "%d\n", &paciente->idade);
    fgets(paciente->medico, dim, arqLista);


}

void marcaHorario(FILE *arqLista, agMedico *medico, cliente *paciente){

    srand(time(NULL) );

    while(! feof(arqLista) ){
        obterPaciente(arqLista, paciente);

        if(compStr(paciente->medico, medico->nome)){

            aleatorio(medico, paciente);
        }

        //fgets(lixo, 30, arqLista);
    }
}

int compStr(char *str, char *str1){
    int cont = 0, i = 0;
    for(i = 0; str[i] != '\0'; i++){

        if(str[i] == str1[i]){
            cont ++;
        }
    }
    if(cont == i){

        return 1;
    }
    return 0;
}

/*A função "copiaMatriz" simplesmente transforma a matriz que foi preenchida em "marcaHorario" na matriz
de horarios daquele medico em questão antes de ser preenchida com os id's dos pacientes, para que assim possa ser utilizada
no proximo loop, que dará origem a matriz de horarios da proxima semana.*/
void copiaMatriz(agMedico *medico, agMedico *copia){
  for(int ho = 0; ho < h; ho++){

      for(int di = 0; di < d; di++){

          medico->agenda[ho][di] = copia->agenda[ho][di];

      }
   }
}
