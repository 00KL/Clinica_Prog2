void horas(int , FILE *);
void escreveMatriz(agMedico *, FILE *, int);

/*A função "horas" recebe valores de 0 a 9 e o arquivo no qual deve imprimir sua resposta, sendo esta
resposta dada em função de um switch que imprime uma determinada string no arquivo de saída.*/
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
/* A função "escreveMatriz" tem por objetivo imprimir no arquivo a tabela de consultas da semana de medico.
Tem como entrada o struct com dados do medico, o arquivo em que a matriz deve ser impressa e a semana da
matriz de horarios.*/
void escreveMatriz(agMedico *medico, FILE *arqSaida, int semana){

    //semana
    fprintf(arqSaida, "\nSemana %d:\n", semana);

    //dias
    fprintf(arqSaida, "\n        2a   3a   4a   5a   6a\n" );

/*Neste for antes da impressão de cada linha da matriz de horarios é impressa pela função "horas" o horario referente
a cada linha*/
    for(int ho = 0; ho < h; ho++){

        horas(ho, arqSaida);
/*O for logo abaixo imprime nos arquivos os valores da matriz de acordo o valor de "ho" que são as horas, sendo
atualizado pelo for acima e o valor de "di" que é o dia da semana, sendo atualizado pelo for logo abaixo.
Para que a matriz esteja alinhada após a impressão é necessario uma formatação especifica para cada tipo possivel de valor
na matriz de horarios*/
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
