//Arquivos necessários por conter
//funções relevantes para o funcionamento
//desse arquivo
#include "faixaEtaria.c"


//Questão 4
void especialidadesPopulares(char *, agMedico *, int *);

//Questão 3
void medicoPopular(char *, agMedico *, int *);

//Questão 7
void criaDadosPacientes(char *, char *, agFaixaEtaria *);




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


void especialidadesPopulares(char *especialidades, agMedico *medico, int *especialidadeMaisProcurada){
    char atualizaResultado[100];
    char *local;

    if( (*especialidadeMaisProcurada < medico->contEspecialidade) && !(strstr(especialidades, medico->especialidade)) ){
        strcpy(atualizaResultado, especialidades);
        strcpy(especialidades, medico->especialidade);
        strcat(especialidades, atualizaResultado);
        *especialidadeMaisProcurada = medico->contEspecialidade;
    }

    else if( *especialidadeMaisProcurada == medico->contEspecialidade && strstr(especialidades, medico->especialidade) == 0 ){
        strcat(especialidades, medico->especialidade);
    }

}

