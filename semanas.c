#include <stdio.h>
#include "structs.c"

void horas(int , FILE *);
void escreveMatriz(agMedico *, FILE *, int);


void horas(int hora, FILE *arqSaida){
    switch(hora){
        case 0: fprintf(arqSaida,"   8-9  ");
                break;
        case 1: fprintf(arqSaida,"  9-10  ");
                break;
        case 2: fprintf(arqSaida," 10-11  ");
                break;
        case 3: fprintf(arqSaida," 11-12  ");
                break;
        case 4: fprintf(arqSaida," 12-13  ");
                break;
        case 5: fprintf(arqSaida," 13-14  ");
                break;
        case 6: fprintf(arqSaida," 14-15  ");
                break;
        case 7: fprintf(arqSaida," 15-16  ");
                break;
        case 8: fprintf(arqSaida," 16-17  ");
                break;
        case 9: fprintf(arqSaida," 17-18  ");
                break;
    }
}

void escreveMatriz(agMedico *medico, FILE *arqSaida, int semana){

    //semana
    fprintf(arqSaida, "\nSemana %d:\n", semana);

    //dias
    fprintf(arqSaida, "\n        2a   3a   4a   5a   6a\n" );


    for(int ho = 0; ho < h; ho++){

        horas(ho, arqSaida);

        for(int di = 0; di < d; di++){

          if(medico->agenda[ho][di] == 0){

              fprintf(arqSaida, " %d   ", medico->agenda[ho][di]);

          }else if(medico->agenda[ho][di] == -1){

              fprintf(arqSaida, "%d   ", medico->agenda[ho][di]);

          }else{

              fprintf(arqSaida, "%d  ", medico->agenda[ho][di]);
          }

        }
        fprintf(arqSaida, "\n");
    }

}
