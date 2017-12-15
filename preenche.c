 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Arquivos necessários por conter
//funções relevantes para o funcionamento
//desse arquivo

//A ordem em q cada um dos arquivos são chamadas
//é TOTALMENTE RELEVANTE, pois ao chamar structs.c
//antes de colocar.c e criaDadosPacientes.c permite
//que os structs sejam acessiveis para colocar.c e
//criaDadosPacientes.c
#include "structs.c"
#include "semanas.c"
#include "colocar.c"
#include "criaDadosPacientes.c"

void teste();

void escreveArqMedico(agMedico *, int);

void resetVetorPacientes(cliente *);

void vetorMedico(FILE *, agMedico *, int *);

void escreveDadosMedico(FILE *, agMedico *);

void nomeLista(char *, int);

void diasOcupados(agMedico *, FILE *);

void preencheMatriz(agMedico * /*agMedico **/);

void marcaHorario(FILE *, agMedico *, agFaixaEtaria *, cliente *, int);
void obterPaciente(FILE *, cliente *);
void aleatorio(agMedico *, cliente *);

//SO PARA TESTES
void exebeMatriz(agMedico *);

void escreveDadosMedico(FILE *arqSaida, agMedico *medico){
  /*escreve o nome do medico no arquivo de saida*/
  fprintf(arqSaida, "%s", medico->nome);

  /*lê o id do medico no arquivo de entrada
  o '\n' é expresso na leitura para q a proxima leitura
  se inicie na linha seguinte
  isso é necessário aqui pois o "fscanf" n pula uma linha
  ao final da leitura como o "fgets"*/
  //fscanf(arqEntrada, "%d\n", &medico->id);

  /*escreve o id do medico no arquivo de saida*/
  fprintf(arqSaida, "%d\n", medico->id);

  /*lê a especialidade do medico no arquivo de entrada*/
  //fgets(medico->especialidade, dim, arqEntrada);
  /*escreve a especialidade do medico no arquivo de saida*/
  fprintf(arqSaida, "%s", medico->especialidade);

  //medico->consultas = 0;
}



void preencheMatriz(agMedico *medico){

  /*loop q ira percorrer todas as horas.
  as horas são as linhas da matriz
  agMedico medico->agenda[hora][dias]*/
    for(int ho = 0; ho < h; ho++){

      /*loop q ira percorrer todas as horas.
    as horas são as colunas da matriz
    agMedico medico->agenda[hora][dia]*/
        for(int di = 0; di < d; di++){

              /*hora de almoço de todos os medicos*/
            if(ho == 4){
                //copia->agenda[ho][di] = -1;
                medico->agenda[ho][di] = -1;
            }else{
                /*hora disponivel genérico de todos os medicos*/
                medico->agenda[ho][di] = 0;
                //copia->agenda[ho][di] = 0;
            }
        }
    }
}
void diasOcupados(agMedico *medico, FILE *arqMedico){

    /*anuncio das varaveis q serão usadas nessa
    função*/
    int dia, hora;

    /*variavel q ira checar q valor o proximo char possui
    para saber quando houver uma quebra de linha '\n' para
    sair do primeiro loop de leitura do arquivo arqEntrada,
    na linha onde há os horarios ocupados personalizados de cada
    medico*/
    char check = '\n';

    preencheMatriz(medico);

    /*leitura do dia q deve ser usado para o primeiro loop
    pois os outros dias serão definidos no final do loop*/
        fscanf(arqMedico, "%d", &dia);
    do{

      /*leitura do "a " padrão do inicio de cada linha de horarios
      personalizados*/
        fscanf(arqMedico, "a ");

        do{
          /*leitura da hora q deve ser usada para gravar o horario
          ocupado em questão e da variavel de checagem do poroximo caracter
          que pode ser '\n', q é a condição de parada*/
            fscanf(arqMedico, "%d%c", &hora, &check);

            /*gravação do valor q representa ocupado '-1' nas posições
            estavelecidas no arquivo de entrada.
            o '-8' na hora é porque as horas começão a ser contadas de)
            '8' no arquivo de entrada no enunciado da questão, porém uma
            matriz tem por primeira posição o valor '0'
            o '-2' no dia é porque os dias começam a ser contados de
            '2' no arquivo de entrada e no enunciado da questão, porém unma
            matriz tem por primeira posição o valor '0' */
            medico->agenda[hora - 8][dia - 2] = -1;
            //copia->agenda[hora - 8][dia - 2] = -1;

        }while( check != '\n' && !feof(arqMedico) );/*a condição de parada do primeiro loop é o fim
        de uma linha do arquivo que sempre será '/n' */


        /*o arquivo check le a proxima posição, essa proxima posição pode
      ser um interiro, reprensetando mais um dia, ou um '\n' reprensetando
      uma linha vazia q sepera os dados de um medico dos dados do seguinte
      sendo assim a condição de parada para esse loop*/
        fscanf(arqMedico, "%c", &check);

        /*conversão do arquivo char "check", para um inteiro,
        pois há  possibilidade de ser o proximo dia*/
        dia = check - 48;

    }while(check != '\n' && !feof(arqMedico));/*um '\n' reprensetando
    uma linha vazia q sepera os dados de um medico dos dados do seguinte
    sendo assim a condição de parada para esse loop*/


}
void nomeLista(char *nomeArq, int semana){

  char fimNome[5];

  strcpy(fimNome, " .txt");
  fimNome[0] = semana + 48;

  /*copia do inicio de nome de cada arquivo para a atualização
  do arquivo q deve ser lido*/
  strcpy(nomeArq, "entrada/listaPacientesSemana");

  /*concatenação do inicio do nome da parte que varia, ou seja o
  numero da semana*/
  strcat(nomeArq, fimNome);

}


void marcaHorario(FILE *arqLista, agMedico *medico, agFaixaEtaria *atualizacao, cliente *pacientes, int semana){

    /*variaveis q serão utilizados na questão

    nomeMedico ira armazenar o nome do medico do loop em questão

    lixo[dim] é apenar para guardar arquivos q n serão úteis

    id será o id do paciente extraido do arqLista para a
    matriz da semana do medico em questão desse loop
    */
    /*char nomeMedico[dim], lixo[dim];
    int id, idade;*/

    /*geração de seed aleatoria para o rand baseada
    no tempo de execução do codigo*/
    srand(time(NULL) );

    /*loop para percorrer todo o arquivo listaPacientesSemana*.txt
  com o objetivo de marcar as consultas em cada medico.
  essa função extrair as consultas de um medico especifico em uma
  semana especifica
  o que significa q para cada execução da função marcaHorarios
  uma lista de consultas para uma semana especifica ira ser colocada
  em um agMedico medico->agenda especifico
   */
    for(int i=0; pacientes[i].id != 0; i++){

      /*printf("%d %s\n",pacientes[i].id,pacientes[i].nome);
      printf("%s %s\n",pacientes[i].medico,medico->nome);
      printf("\n" );*/

        /*essa função irá percorrer o arquivo listaPc*/
        //obterPaciente(arqLista, paciente);

        if(compStr(medico->nome,pacientes[i].medico)){
            medico->consultas+=1;
            medico->nConsultasSemana[semana-1]+=1;
            //printf("%d -> %s\n",medico->nConsultasSemana[semana],medico[i].especialidade);
          //printf("%s %d\n", pacientes[i].nome, pacientes[i].id);
            pesquisaDeFaixaEtaria( pacientes[i].idade, medico->especialidade, atualizacao);

            

            aleatorio(medico, &pacientes[i]);

        }

    }
    //exebeMatriz(medico);

}
void obterPaciente(FILE *arqLista, cliente *paciente){
  char saltarLinha[dim];

    fgets(paciente->nome, 30, arqLista);
    //printf("oi%soi\n",paciente->nome);
    //fim nome paciente tem \n
    fscanf( arqLista ,"%d\n", &paciente->id);
    fgets(paciente->fone, 30, arqLista);
    fscanf(arqLista, "%d %d %d\n", &paciente->idade, &paciente->idade,&paciente->idade);
    fgets(paciente->medico, dim, arqLista);
    fgets(saltarLinha, 30, arqLista);
    //printf("%d\n",paciente->id);
}
void aleatorio(agMedico *medico, cliente *paciente){
/*A função "copiaMatriz" simplesmente transforma a matriz que foi preenchida em "marcaHorario" na matriz
de horarios daquele medico em questão antes de ser preenchida com os id's dos pacientes, para que assim possa ser utilizada
no proximo loop, que dará origem a matriz de horarios da proxima semana.*/
    int hora =  rand()%9;
    int dia = rand()%4;

    if(medico->agenda[hora][dia] != 0){

        while(medico->agenda[hora][dia] != paciente->id){

            hora =  rand()%9;
            dia = rand()%4;

            if(medico->agenda[hora][dia] == 0 ){

                medico->agenda[hora][dia] = paciente->id;
              //  printf("%d\n",paciente->id );
            }
        }
    }else if(medico->agenda[hora][dia] == 0){
        medico->agenda[hora][dia] = paciente->id;
        //printf("%d\n",paciente->id );
    }


}


//SOMENTE PARA TESTE
void exebeMatriz(agMedico *medico){

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


void teste(){
    esp vetorEsp[dim];
    //test
    char maisProcurados[100];
    int maisConsultas;
    

  agMedico medico[dim];
  cliente pacientes[99];
  FILE *arqEntrada, *arqLista;
  char nomeArq[dim];
  agFaixaEtaria atualizacao;
  int nMedicos;
  char vazio[1]={' '};

  iniciaVetor(vetorEsp);

  if (!(arqEntrada = fopen ("entrada/dadosMedicos.txt", "r"))){
      printf("ERRO1\n");
      exit(1);
  }

  vetorMedico(arqEntrada,medico,&nMedicos);

  //printf("%d\n",nMedicos);



  fclose(arqEntrada);

  for(int semana = 4; semana > 0; semana--){

    resetVetorPacientes(pacientes);

      /*cria nome devido para o arquivo do loop em questão*/
    nomeLista(nomeArq, semana);

    if (!(arqLista = fopen(nomeArq, "r"))){
      printf("%s \nERRO3 \n", nomeArq);
      exit(1);
    }

    for(int k=0; ! feof(arqLista); k++){
      obterPaciente(arqLista,&pacientes[k]);
      //printf("%s %d\n",pacientes[k].nome, pacientes[k].id);
      //printf("\n" );
    }
    fclose(arqLista);

    for(int i=0; i < nMedicos ; i++){


        marcaHorario(arqLista, &medico[i], &atualizacao, pacientes, semana);
        //printf("%d\n", medico[i].nConsultasSemana[semana]);
        medicoPopular(maisProcurados, &medico[i], &maisConsultas);

      
      //  exebeMatriz(&medico[i]);
      //  printf("\n");
        escreveArqMedico(&medico[i] ,semana);

        //printf("%s %d\n",medico[i].especialidade, medico[i].consultas);


    }


  }
  //especialidadesPopulares(vetorEsp, medico,nMedicos);

  criaDadosPacientes(maisProcurados, &atualizacao, vetorEsp, medico, nMedicos);
}

/*Função que preenche o vetor de medicos */
void vetorMedico(FILE *arqEntrada, agMedico *medico, int *nMedicos){
  int contador;

  for(contador=0; ! feof(arqEntrada) ; contador++){
    fgets(medico[contador].nome, dim, arqEntrada);
    //printf("oi%soi\n",medico[contador].nome);

    fscanf(arqEntrada,"%d\n", &medico[contador].id);

    fgets(medico[contador].especialidade, dim, arqEntrada);

    diasOcupados(&medico[contador],arqEntrada);


  }
  *nMedicos=contador;

}

void escreveArqMedico(agMedico *medico, int semana){
    char nomeArq[dim+5],nomeM[dim] = " ";
    FILE *arqSaida;

    /*ira substituir o valor armazenado em nomeM
    pelo valor presente em medico->nome*/
    strcpy(nomeM,medico->nome);
    /*é adicionado a ultima posição de nomeM, q no momento é '\n'
    por conta da saida padrão da função "gets",  o valor de '.'
    que fará parte do nome do arquivo com final ".txt"*/
    nomeM[ strlen(medico->nome) - 1 ] = '.' ;

    /*ira substituir o valor armazenado em nomeArq por
    "saida/", q será o inicio do arquivo onde será
    gravada a saida do programa*/
    strcpy(nomeArq, "saida/");
    /*irá concatenar os valore presentes em nomeArq
    com os valores presentes em nomeM*/
    strcat(nomeArq, nomeM);
    /*irá concatenar os valores presentes em nomeArq
    com o texto "txt"*/
    strcat(nomeArq, "txt");


    /* O if abaixo verifica se a semana é a primeira e caso
    seja satisfeito ele cria o arquivo de saida com o nome
    do medico e escreve o nome,id e especialidade no inicio
    do arquivo.
    */

    if(semana==1){

      arqSaida = fopen(nomeArq, "w'");

      escreveDadosMedico(arqSaida,medico);
      fclose(arqSaida);
  }

  /*Nessa parte o arquivo de saida é sempre aberto
  para que sejam gravadas informações ao final do arquivo,
  mas aparentemente o arquivo é aberto e preparado para gravação
  apos detectar o primeiro "\n" e não o final do arquivo,
  o que nos motivou modificar o contador semanas de maneira
  decrescente para que a função escreveMatriz possa imprimir
  tudo na ordem correta.*/

    arqSaida = fopen(nomeArq, "a+");


    /*if(compStr("Joao Silva da Costa",medico->nome)){
      exebeMatriz(medico);
      printf("\n");
    }*/
    escreveMatriz(medico,arqSaida,semana);

  }

/*A função abaixo reseta os valores do vetor de pacientes
para que não apareçam id's na matriz de horarios que nao sejam
da semana correspondente, pois o vetor de clientes é lido e
amazenado por semana. Depois da primeiro leitura o vetor é sobrescrito
com os dados de pacientes da proxima semana e daí a necessidade
de resetar o vetor. */
void resetVetorPacientes(cliente *pacientes){
  for(int i = 0; i < 99; i++){
    strcpy(pacientes[i].nome, " ");
    pacientes[i].id=0;
    strcpy(pacientes[i].fone, " ");
    pacientes[i].idade=0;
    strcpy(pacientes[i].medico, " ");
  }
}
