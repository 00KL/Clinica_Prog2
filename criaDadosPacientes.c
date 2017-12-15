//Arquivos necessários por conter
//funções relevantes para o funcionamento
//desse arquivo
#include "faixaEtaria.c"


//Questão 4
void especialidadesPopulares(char *, agMedico *, int *, esp *, int *);

//Questão 3
void medicoPopular(char *, agMedico *, int *);

//Questão 7
void criaDadosPacientes(char *, char *, agFaixaEtaria *);

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
    fprintf(arqDadosClinica, "%s\n", especialidades);

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


void especialidadesPopulares(char *especialidades, agMedico *medico, int *especialidadeMaisProcurada, esp *test, int *cont){
    char atualizaResultado[100];
    char *local;
    int aux = 0;

    do{
        
        if(!strcmp( medico->especialidade, test[aux].especialidade)){
            printf("%s|%s", test[aux].especialidade, medico->especialidade);
            test[aux].nEspecialidade += medico->consultas;

            printf("entro pooooorra\n\n");
            break;
        }
        else{
            strcpy(test[*cont].especialidade, medico->especialidade);
            test[*cont].nEspecialidade = medico->consultas;
            *cont+=1;

            printf("%s%s", test[aux].especialidade, medico->especialidade);
            printf("segundo entro pooooorra\n\n");
            break;
        }

        aux++;
    }while(medico->consultas == 0);
    

    //printf("%d -> %s", test[*cont].nEspecialidade, test[*cont].especialidade  );

    //local = strstr(especialidades, medico->especialidade);

    if( (*especialidadeMaisProcurada < medico->contEspecialidade) && !(strstr(especialidades, medico->especialidade)) ){
        //printf("%d --> %s", medico->contEspecialidade, medico->nome);
        //printf("%d --> %s\n\n", *especialidadeMaisProcurada, especialidades);
        strcpy(atualizaResultado, especialidades);
        strcpy(especialidades, medico->especialidade);
        strcat(especialidades, atualizaResultado);
        *especialidadeMaisProcurada = medico->contEspecialidade;
        medico->contEspecialidade = 0;
        medico->consultas = 0;
    }

    else if( *especialidadeMaisProcurada == medico->contEspecialidade && strstr(especialidades, medico->especialidade) == 0 ){
        //printf("test\n");
        strcat(especialidades, medico->especialidade);
    }

    else if (*especialidadeMaisProcurada > medico->contEspecialidade){

        strcat(especialidades, medico->especialidade);
    }

    //printf("%s\n\n", especialidades );
}

void iniciaEsp(esp *test){
    for(int i = 0; i < 30; i++){
        test[i].nEspecialidade = 0;
    }
}

void bubble(esp *vetorEsp, int numEsp){

  int troca;
  char trocaC[dim];

  //printf("%d\n", numEsp);


  for(int c = 0; c < numEsp ; c++){
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

  for(int i = 0; i < numEsp; i++){
        printf("%d -> %s", vetorEsp[i].nEspecialidade, vetorEsp[i].especialidade);
    }
}

