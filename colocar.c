//Arquivos relevantes
#include "buscaHorarios.c"

//funcoes
void colocar(FILE *, agMedico *, FILE *, char *);

void buscaHorarios(agMedico *, int *, int , int ,FILE *, char *);


void colocar(FILE *arqEntrada, agMedico *medico, FILE *arqSaida, char *str){

    int indice, posicao[h], cont = 0;

    buscaHorarios(medico, posicao, indice, cont, arqEntrada, str);

}

void buscaHorarios(agMedico *medico,int *posicao,int indice, int cont, FILE *arqEntrada, char *str){

    char check;

  do{
        colocarValores(medico, posicao, indice, cont, arqEntrada, str);
        check = str[0];

    } while(check != '\n' && !feof(arqEntrada) );
}
