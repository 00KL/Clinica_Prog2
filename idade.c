#include <stdio.h>

//void preencheESP(agFaixaEtariaVet *, cliente *, int );

void iniciaV(agFaixaEtariaVet *);

//Função que calcula a idade com base na data definida como atual
int calcIdade(cliente *pacientes){
  data dataAtual;
  dataAtual.ano=2017;
  dataAtual.mes=12;
  dataAtual.dia=15;

  for(int i=0; i<99; i++){
    /*se o mes de nascimento do paciente for maior que o mes atual ou se os meses forem iguais mas o dia de nascimento do paciente seja
    maior que o dia atual entao a data é a subtraçao do ano atual pelo ano de nascimento do paciente - 1*/
    if(pacientes[i].idade.mes>dataAtual.mes || ((pacientes[i].idade.mes==dataAtual.mes) && (pacientes[i].idade.dia > dataAtual.dia))){
      pacientes[i].idade.idade = dataAtual.ano - pacientes[i].idade.ano - 1;
    } else{
      /*em outros casos o ano de nascimento do paciente sera subtraido do ano atual*/
      pacientes[i].idade.idade = dataAtual.ano - pacientes[i].idade.ano;
    }
  }
  //printf("%s %d\n",pacientes[0].nome,pacientes[0].idade.idade);
}

/*void preencheESP(agFaixaEtariaVet *vetorEspFaixa, cliente *pacientes, int semana){

  iniciaV(vetorEspFaixa);

  for(int i=0; i<dim;i++){
    for(int k=0; k<99;k++){
      if(compStr(vetorEspFaixa[i].especialidade,pacientes[k].especialidade)){

        if(pacientes[k].idade.idade<26){
          vetorEspFaixa[i].faixa[0][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<51){
          vetorEspFaixa[i].faixa[1][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<76){
          vetorEspFaixa[i].faixa[2][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<101){
          vetorEspFaixa[i].faixa[3][semana-1]+=1
        }
      } else
      if(vetorEspFaixa[i].especialidade[0]==" "){
        strcpy(vetorEspFaixa[i].especialidade,pacientes[k].especialidade)

        if(pacientes[k].idade.idade<26){
          vetorEspFaixa[i].faixa[0][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<51){
          vetorEspFaixa[i].faixa[1][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<76){
          vetorEspFaixa[i].faixa[2][semana-1]+=1
        } else
        if(pacientes[k].idade.idade<101){
          vetorEspFaixa[i].faixa[3][semana-1]+=1
        }
      }
    }
  }
}*/

void iniciaV(agFaixaEtariaVet *vetorEspFaixa){
  for(int i=0; i<dim; i++){
    strcpy(vetorEspFaixa[i].especialidade," ");
    for(int k=0; k<4; k++){
      for(int g=0; g<4;g++){
        vetorEspFaixa[i].faixa[k][g]=0;
      }
    }
  }
}
