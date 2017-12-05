#include <stdio.h>
#include <string.h>
#include "structs.c"

#define dim 30
#define h 10
#define d 5


/*strcat(nomeTxt,"dados/listaPacientesSemana")
conversao = 48 + *week;
strcat(conversao, ".txt");
strcat(nomeTxt, conversao);*/

/* criar função do tipo int que recebe o struct do medico e de pacientes da semana,
cujo funcionamento deve ser comparar o nome do medico com o nome de medico no struct de paciente
e baseado nisso retornar o id do paciente ou 0*/

int pacienteMedico(agMedico *medico, FILE *dadosPacientes){

  char nomeMedico[dim],lixo[1];
  int id;

  fscanf(dadosPacientes,"%s\n%d\n%s\n%s\n%s\n", &lixo, &id, &lixo, &lixo, &nomeMedico);

  /*fgets(lixo, 30, dadosPacientes);
  fscanf(dadosPacientes, "%d", &id);
  fgets(lixo, 30, dadosPacientes);
  fgets(lixo, 30, dadosPacientes);
  fgets(lixo, 30, dadosPacientes);
  fgets(nomeMedico, 30, dadosPacientes);*/

  if(!(strcmp(nomeMedico, medico->nome))){
    return id;
  }

  return 0;

}
