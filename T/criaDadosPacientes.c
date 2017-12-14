//Arquivos necessários por conter
//funções relevantes para o funcionamento
//desse arquivo
#include "faixaEtaria.c"



//Questão 4
void especialidadesPopulares(esp *, agMedico *, int);

//Questão 3
void medicoPopular(char *, agMedico *, int *);

//Questão 7
void criaDadosPacientes(char *, char *, agFaixaEtaria *);

void iniciaVetor(esp *);

void bubble(esp *, int );




void criaDadosPacientes(char *maisProcurados, char *especialidades, agFaixaEtaria *atualizacao){
    FILE *arqDadosClinica;

    if (!(arqDadosClinica = fopen ("saida/dadosClinica.txt", "w"))){
        printf("ERRO \n");
        exit(1);
    }
    fprintf(arqDadosClinica, "Dados da Clinica:\n\n");

    fprintf(arqDadosClinica, "Médico mais popular:\n");
    fprintf(arqDadosClinica, "%s\n", maisProcurados);

    fprintf(arqDadosClinica, "Ranking   da   procura   por   especialidades   médicas:\n");
    //for(num--)

    fprintf(arqDadosClinica, "Especialidade   mais   procurada   por   faixa   etária:\n");
    exibeTodasAsFaixas(atualizacao, arqDadosClinica);

}


void medicoPopular(char *maisProcurados, agMedico *medico, int *maisConsultas){

    if(*maisConsultas == medico->consultas){
        strcat(maisProcurados, medico->nome);
    }
    else if (*maisConsultas < medico->consultas){
        strcpy(maisProcurados, medico->nome);
        *maisConsultas = medico->consultas;
    }

}


void especialidadesPopulares(esp *vetorEsp, agMedico *medico, int nMedicos){

  char vazio[dim] = {' '};
  int c;
  //printf("%s %d\n",medico[2].especialidade, medico[2].consultas);

  int numEsp=0;

  for(int k=0; k<nMedicos; k++){
    printf("%d %s\n", medico[k].consultas, medico[k].nome);

    for(int i=0; i<dim; i++){


      if(compStr(vetorEsp[i].especialidade,medico[k].especialidade)){
        vetorEsp[i].nEspecialidade+=medico[k].consultas;
        //printf("%d\n", medico[k].consultas);
        break;
      }else if(vetorEsp[i].especialidade[0]==vazio[0]){
            strcpy(vetorEsp[i].especialidade,medico[k].especialidade);
            vetorEsp[i].nEspecialidade=medico[k].consultas;
            //printf("%d\n", medico[k].consultas);
            numEsp++;
            //printf("%s %d\n",vetorEsp[i].especialidade,vetorEsp[i].nEspecialidade );
            break;
          }

    }
  }

  bubble(vetorEsp,numEsp);

  /*for(int j=0; j<numEsp; j++){
    printf("%s %d\n",vetorEsp[j].especialidade,vetorEsp[j].nEspecialidade);
  }*/
}

void iniciaVetor(esp *vetorEsp){
  for(int i=0; i<dim; i++){
    strcpy(vetorEsp[i].especialidade," ");
    vetorEsp[i].nEspecialidade=0;
  }
}

void bubble(esp *vetorEsp, int numEsp){
  int troca;
  char trocaC[dim];

  for(int c=0; c < numEsp; c++){
    for(int n=0; n < numEsp - c - 1; n++){
      if(vetorEsp[n].nEspecialidade > vetorEsp[n+1].nEspecialidade){
        troca = vetorEsp[n].nEspecialidade;
        strcpy(trocaC,vetorEsp[n].especialidade);
        vetorEsp[n].nEspecialidade = vetorEsp[n+1].nEspecialidade;
        strcpy(vetorEsp[n].especialidade,vetorEsp[n+1].especialidade);
        vetorEsp[n+1].nEspecialidade=troca;
        strcpy(vetorEsp[n+1].especialidade,trocaC);
      }
    }
  }
}
