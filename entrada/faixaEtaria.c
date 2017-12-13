//Questão 5
void iniciaFaixaEtaria(agFaixaEtaria *);
void exibeFaixaUm(agFaixaEtaria *, FILE *);
void exibeFaixaDois(agFaixaEtaria *, FILE *);
void exibeFaixaTres(agFaixaEtaria *, FILE *);
void exibeFaixaQuatro(agFaixaEtaria *, FILE *);
void exibeTodasAsFaixas(agFaixaEtaria *, FILE *);



/*como o proprio nome sugere a função só inicia os valores daquelas posiçoes na struct com valor 0, para que
nao haja erros causados por lixo de memoria*/
void iniciaFaixaEtaria(agFaixaEtaria *atualizacao){

    atualizacao[0].contFaixa = 0;
    atualizacao[1].contFaixa = 0;
    atualizacao[2].contFaixa = 0;
    atualizacao[3].contFaixa = 0;
}

/**/
void pesquisaDeFaixaEtaria(int idade, char *especialidade, agFaixaEtaria *atualizacao){

    /* idade refere-se ao ano de nascimento do pasciente.
    Considerando o ano atual 2017 e desconsederando os meses e dias,
    basta subtriar o ano de nascimento de 2017 q se tem a idade do
    pasciene.*/
    idade = 2017 - idade;

    /*Cada if representa uma das faixa etaria estabelecida no enunciado
    */
    if( idade < 26){
        /*os vetores de matrizes q respresentam cada faixa etaria são inicializados aqui
        assim sendo a posição atual esta vazia ou com lixo e deve ser sobreescrita
        com o valor q sera analizado por funçõe posteriores.*/
        strcpy( ( atualizacao[0].faixa[ atualizacao[0].contFaixa ] ) , especialidade);
        /*o valor do contador é atualizado para q na proxima pesquisa seja
        a especialidade seja escrita na posição correta da matriz faixa*/
        atualizacao[0].contFaixa+=1;

    }
    else if( idade < 51){
        strcpy( ( atualizacao[1].faixa[ atualizacao[1].contFaixa ] ) , especialidade);
        atualizacao[1].contFaixa+=1;
    }
    else if(idade < 76){
        strcpy( ( atualizacao[2].faixa[ atualizacao[2].contFaixa ] ) , especialidade);
        atualizacao[2].contFaixa+=1;
    }
    else if(idade < 101){
        strcpy( ( atualizacao[3].faixa[ atualizacao[3].contFaixa ] ) , especialidade);
        atualizacao[3].contFaixa+=1;

    }


}


void exibeTodasAsFaixas(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";

    for(int faixaEtaria = 0; faixaEtaria < 4; faixaEtaria++){

        for(int especialidade = 0; especialidade < pesquisa[faixaEtaria].contFaixa; especialidade++){

            if(!compStr(pesquisa[faixaEtaria].faixa[especialidade], " ")){

                for(int compara = especialidade + 1; compara < pesquisa[faixaEtaria].contFaixa; compara++){

                    if( compStr(pesquisa[faixaEtaria].faixa[especialidade], pesquisa[faixaEtaria].faixa[compara]) ) {
                        cont1++;
                          strcpy(pesquisa[faixaEtaria].faixa[compara], " ");
                    }

                }

                if(cont1 > cont2){
                    cont2 = cont1;
                    strcpy(vencedor, pesquisa[faixaEtaria].faixa[especialidade]);
                }
            }
        }

        switch (faixaEtaria) {
          case 0:
                  fprintf(arqDadosClinica,"  0 -  25  %s", vencedor);
                  break;
          case 1:
                  fprintf(arqDadosClinica," 26 -  50  %s", vencedor);
                  break;
          case 2:
                  fprintf(arqDadosClinica, " 51 -  75  %s", vencedor);
                  break;
          case 3:
                  fprintf(arqDadosClinica, " 76 - 100  %s", vencedor);
                  break;
        }

        cont1 = 0;
        cont2 = 0;
        strcpy(vencedor, " ");

    }

}
