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


void preencheMedico(agMedico *, FILE *, FILE *, FILE *, agFaixaEtaria *, cliente *);

void escreveDadosMedico(FILE *, FILE *, agMedico *);

void nomeLista(char *, int);

void diasOcupados(agMedico *, FILE *, agMedico *);

void preencheMatriz(agMedico *, agMedico *);

void marcaHorario(FILE *, agMedico *, agFaixaEtaria *, cliente *);
void obterPaciente(FILE *, cliente *);
void aleatorio(agMedico *, cliente *);


void copiaMatriz(agMedico *, agMedico *);

//SO PARA TESTES
//void exebeMatriz(agMedico *, FILE *arqSaida);


void preencheMedi(agMedico *medico, FILE *arqEntrada, FILE *arqLista, agFaixaEtaria *atualizacao, cliente *paciente){

    //Variaveis necessarias
    FILE *arqSaida;
    medico->consultas = 0;
    int maisConsultas = 0, especialidadeMaisProcurada = 0;
    char maisProcurados[100], especialidades[100] = {0};

    iniciaFaixaEtaria(atualizacao);


    /*to achando q vamos ter q criar um vetor
    de structs para as proximas questões...*/
    //cliente todosOsClientes[100];

    //preenchimento de arqEntrada
    if (!(arqEntrada = fopen ("entrada/dadosMedicos.txt", "r"))){
        printf("ERRO1\n");
        exit(1);
    }


    /*Loop para percorrer arqEntrada e extrair as informações
    necessárias para o enunciado do trabalho

    O loop acaba quando o arquivo entrada/dadosMedicos.txt acabar
    de ser lido

    A função feof(FILE *) retorna '0' quando o arquivo acaba de ser lido
    e por isso é necessário negar sua saida no argumento
    do loop*/
    while(! feof(arqEntrada)){

        preencheMedico(medico, arqEntrada, arqLista, arqSaida, atualizacao,paciente);

        /*extrai o medico mais popular*/
        medicoPopular(maisProcurados, medico, &maisConsultas);

        /*extrai e organiza as especialidades em mais procuradas*/
        especialidadesPopulares(especialidades, medico, &especialidadeMaisProcurada);
    }

    criaDadosPacientes(maisProcurados, especialidades, atualizacao);

}


void preencheMedico(agMedico *medico, FILE *arqEntrada, FILE *arqLista, FILE *arqSaida, agFaixaEtaria *atualizacao, cliente *paciente){
    /*Variaveis necessárias para a função

    agMedico copia esta servindo para armazenar uma copia
    dos valores de medico->agenda com o objetivo de reescreve-los
    ao final do loop q escreve as semanas de cada médico.
    Isso porque cada semana deve conter suas consultas especificas
    mas os horarios de almoço e horarios ocupados personalizados de
    cada medico devem se manter*/
    agMedico copia;
    /*nomeArq será o nome do arquivo q deve ser lido
    a contanstante "dim" esta sendo usada pois todos os medicos
    terão seus nomes limitados por esse valor, e "+5" porconta do
    numero da semana e do ".txt"

    ja nomeM tem apaenas dim, pois irá armazenar apenas o nome do
    medico em questão*/
    char nomeArq[dim+5],nomeM[dim];

    /*Ira armazenar o nome do medico presente em arqEntrada
    no struct medico*/
    fgets(medico->nome, dim, arqEntrada);

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

    /*leitura do nome do arquivo q deve ser criado com o nome do medico
    no loop atual, junto com um teste de um possivel erro de criação*/
    if (!(arqSaida = fopen (nomeArq, "w"))){
        printf("ERRO \n");
        exit(1);
    }

    /*escreve os dados iniciais dos medicos
    no arquivo saida*/
    escreveDadosMedico(arqEntrada, arqSaida, medico);

    /*preenche medico->agenda e copia->agenda com os '0's e '-1's
    padrões especeficados para todos os medicos
    estabelicido no enuncido */
    preencheMatriz(medico, &copia);

    /*preenche medico->agenda e copia->agenda com os dias ocupados
    personalizados de cada medico*/
    diasOcupados(medico, arqEntrada, &copia);

    /*loop q percorre os arquivos das 4 semanas, extrai seus valores, põe
    de forma aleatorios os ids de cada paciente nas semanas e medicos
    estabelecidos no arqLista
     */
    for(int semana = 1; semana < 5; semana++){

      /*cria nome devido para o arquivo do loop em questão*/
      nomeLista(nomeArq, semana);

      /*lê o arquivo cujo nome esta armazenado em nomeArq e checa se há
      algum erro na leitura*/
      if (!(arqLista = fopen(nomeArq, "r"))){
          printf("%s \nERRO3 \n", nomeArq);
          exit(1);
      }


      marcaHorario(arqLista, medico, atualizacao,paciente);

      //exebeMatriz(medico, arqSaida);

      escreveMatriz(medico, arqSaida, semana);

      copiaMatriz(medico, &copia);

      fclose(arqLista);

    }

}


void escreveDadosMedico(FILE *arqEntrada, FILE *arqSaida, agMedico *medico){
  /*escreve o nome do medico no arquivo de saida*/
  fprintf(arqSaida, "%s", medico->nome);

  /*lê o id do medico no arquivo de entrada
  o '\n' é expresso na leitura para q a proxima leitura
  se inicie na linha seguinte
  isso é necessário aqui pois o "fscanf" n pula uma linha
  ao final da leitura como o "fgets"*/
  fscanf(arqEntrada, "%d\n", &medico->id);

  /*escreve o id do medico no arquivo de saida*/
  fprintf(arqSaida, "%d\n", medico->id);

  /*lê a especialidade do medico no arquivo de entrada*/
  fgets(medico->especialidade, dim, arqEntrada);
  /*escreve a especialidade do medico no arquivo de saida*/
  fprintf(arqSaida, "%s", medico->especialidade);

  medico->consultas = 0;
}



void preencheMatriz(agMedico *medico, agMedico *copia){

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
                copia->agenda[ho][di] = -1;
                medico->agenda[ho][di] = -1;
            }else{
                /*hora disponivel genérico de todos os medicos*/
                medico->agenda[ho][di] = 0;
                copia->agenda[ho][di] = 0;
            }
        }
    }
}
void diasOcupados(agMedico *medico, FILE *arqMedico, agMedico *copia){

    /*anuncio das varaveis q serão usadas nessa
    função*/
    int dia, hora;

    /*variavel q ira checar q valor o proximo char possui
    para saber quando houver uma quebra de linha '\n' para
    sair do primeiro loop de leitura do arquivo arqEntrada,
    na linha onde há os horarios ocupados personalizados de cada
    medico*/
    char check = '\n';

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
            copia->agenda[hora - 8][dia - 2] = -1;

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


void marcaHorario(FILE *arqLista, agMedico *medico, agFaixaEtaria *atualizacao, cliente *paciente){

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
    while(! feof(arqLista) ){

        /*essa função irá percorrer o arquivo listaPc*/
        obterPaciente(arqLista, paciente);

        if(compStr(paciente->medico, medico->nome)){
            medico->consultas+=1;
            medico->contEspecialidade+=1;

            pesquisaDeFaixaEtaria( paciente->idade, medico->especialidade, atualizacao);

            aleatorio(medico, paciente);
        }

    }
}
void obterPaciente(FILE *arqLista, cliente *paciente){
  char saltarLinha[dim];

    fgets(paciente->nome, 30, arqLista);
    fscanf( arqLista ,"%d\n", &paciente->id);
    fgets(paciente->fone, 30, arqLista);
    fscanf(arqLista, "%d %d %d\n", &paciente->idade, &paciente->idade,&paciente->idade);
    fgets(paciente->medico, dim, arqLista);
    fgets(saltarLinha, 30, arqLista);
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

            if(medico->agenda[hora][dia] == 0){

                medico->agenda[hora][dia] = paciente->id;
            }
        }
    }else{
        medico->agenda[hora][dia] = paciente->id;
    }

}


void copiaMatriz(agMedico *medico, agMedico *copia){

  /*faz um loop para percorrer medico->agenda e
  e substituir todos os seus valores pelos valores presentes
  em copia*/
  for(int ho = 0; ho < h; ho++){

      for(int di = 0; di < d; di++){

          if(ho == 4){
              copia->agenda[ho][di] = medico->agenda[ho][di];
          }else{
              medico->agenda[ho][di] = copia->agenda[ho][di];
          }
      }
   }
}




//SOMENTE PARA TESTE
/*void exebeMatriz(agMedico *medico, FILE *arqSaida){

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
}*/



//void funcTeste()
