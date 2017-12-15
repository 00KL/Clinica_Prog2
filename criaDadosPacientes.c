//Arquivos necessários por conter
//funções relevantes para o funcionamento
//desse arquivo
#include "faixaEtaria.c"



//Questão 4
void especialidadesPopulares(esp *, agMedico *, int, FILE *);

//Questão 3
void medicoPopular(agMedico *, FILE *, int);

//Questão 7
void criaDadosPacientes(agFaixaEtaria *,esp *, agMedico *, int );

void iniciaVetor(esp *);

void bubble(esp *, int );

void consultasEspSemana(esp *, agMedico *, int , int );


//A função abaixo obtem e printa no arquivo dadosClinica.txt as informações requisitadas
void criaDadosPacientes(agFaixaEtaria *atualizacao,esp *vetorEsp, agMedico *medico, int nMedicos){
    FILE *arqDadosClinica;


    if (!(arqDadosClinica = fopen ("saida/dadosClinica.txt", "w"))){
        printf("ERRO \n");
        exit(1);
    }
    fprintf(arqDadosClinica, "Dados da Clinica:\n\n");

    fprintf(arqDadosClinica, "Médico(s) mais popular(es):\n");
    medicoPopular(medico,arqDadosClinica,nMedicos);

    fprintf(arqDadosClinica, "Ranking   da   procura   por   especialidades   médicas:\n\n");
    especialidadesPopulares(vetorEsp,medico,nMedicos,arqDadosClinica);

    fprintf(arqDadosClinica, "\nEspecialidade   mais   procurada   por   faixa   etária:\n");
    exibeTodasAsFaixas(atualizacao, arqDadosClinica);

}

/*a funçao abaixo indica qual o medico mais popular verificando qual o maior numero de consultas total entre todos os medicos
e depois printando no arquivo todos os nomes de medico que possuem tal valor de consultas */
void medicoPopular(agMedico *medico, FILE *arqDadosClinica, int nMedicos){
  int maisProcurado=0;

  for(int i=0; i<nMedicos; i++){
    if(medico[i].consultas>maisProcurado){
      maisProcurado=medico[i].consultas;
    }
  }

  for(int v=0; v<nMedicos; v++){
    if(medico[v].consultas==maisProcurado){
      fprintf(arqDadosClinica,"%s",medico[v].nome);
    }
  }

  fprintf(arqDadosClinica,"\n");



}

/*a função abaixo preenche o vetor de especialidades de maneira que verifica sempre se ja existe o mesmo nome de especialidade na posiçao do vetor e em caso de confirmaçao
só adiciona o numero de consultas do medico daquela especialidade ao numero de consultas total da especialidade, caso verifique que os nomes nao sao iguais
ele passa a verificar se o vetor de especialidade na posiçao requisitada nao esta preenchido e caso nao esteja ele adiciona o nome da especialidade e numero de consultasEspSemana
naquela posição do vetor */
void especialidadesPopulares(esp *vetorEsp, agMedico *medico, int nMedicos, FILE *arqDadosClinica){

  char vazio[dim] = {' '};
  //numEsp é o numero de especialidades no vetor
  int c,numEsp=0;
  //o uso do break abaixo é motivado pela falta de necessidade de continuar a percorrer o vetor de especialidades após o preenchimento da especialidade na posiçao
  // em que o if é verdadeiro
  for(int k=0; k<nMedicos; k++){


    for(int i=0; i<dim; i++){


      if(compStr(vetorEsp[i].especialidade,medico[k].especialidade)){
        vetorEsp[i].nEspecialidade+=medico[k].consultas;
        break;
      }else if(vetorEsp[i].especialidade[0]==vazio[0]){
            strcpy(vetorEsp[i].especialidade,medico[k].especialidade);
            vetorEsp[i].nEspecialidade=medico[k].consultas;
            numEsp+=1;
            break;
          }

    }
  }

  //bubbleSort utilizado para organizar o vetor de acordo a maior procura de uma determinada especialidade
  bubble(vetorEsp,numEsp);
  //depois de organizado o vetor recebe as consultas semanais de cada especialidade
  consultasEspSemana(vetorEsp,medico,nMedicos,numEsp);

  //Agora os dados do vetor são escritos no arquivo
  for(numEsp=numEsp-1; numEsp>=0; numEsp-- ){
      fprintf(arqDadosClinica,"%s" ,vetorEsp[numEsp].especialidade);
      for(int p=0; p<4;p++){
        fprintf(arqDadosClinica,"Semana %d: %d\n",p+1,vetorEsp[numEsp].nConsultas[p]);
      }
      fprintf(arqDadosClinica,"\n");
    }
}

//Funçao que inicializa o vetor de especialidades
void iniciaVetor(esp *vetorEsp){
  for(int i=0; i<dim; i++){
    strcpy(vetorEsp[i].especialidade," ");
    vetorEsp[i].nEspecialidade=0;
    for(int f=0;f<4;f++){
      vetorEsp[i].nConsultas[f]=0;
    }
  }
}

//bubbleSort
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

//Função que preenche o vetor de especialidades com o número de consultas semanais
void consultasEspSemana(esp *vetorEsp, agMedico *medico, int nMedicos, int numEsp){
  for(int i=0; i<nMedicos; i++){

    for(int k=0; k<numEsp; k++){

      if(compStr(vetorEsp[k].especialidade,medico[i].especialidade)){

        for(int b=0;b<4;b++){
          vetorEsp[k].nConsultas[b]+=medico[i].nConsultasSemana[b];
        }
      }
    }
  }
}
