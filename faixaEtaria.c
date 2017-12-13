//Questão 5
void iniciaFaixaEtaria(agFaixaEtaria *);
void exibeFaixaUm(agFaixaEtaria *, FILE *);
void exibeFaixaDois(agFaixaEtaria *, FILE *);
void exibeFaixaTres(agFaixaEtaria *, FILE *);
void exibeFaixaQuatro(agFaixaEtaria *, FILE *);
void exibeTodasAsFaixas(agFaixaEtaria *, FILE *);



/*como o proprio nome sugere a função só inicia os valores daquelas posiçoes na struct com valor 0, para que
nao haja erros causados por lixo de memoria*/
void iniciaFaixaEtaria(agFaixaEtaria *resultado){

    resultado->contFaixa[0] = 0;

    resultado->contFaixa[1] = 0;

    resultado->contFaixa[2] = 0;

    resultado->contFaixa[3] = 0;
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
        strcpy( ( atualizacao->faixa[0][ atualizacao->contFaixa[0] ] ) , especialidade);
        /*o valor do contador é atualizado para q na proxima pesquisa seja
        a especialidade seja escrita na posição correta da matriz faixa*/
        atualizacao->contFaixa[0]+=1;

    }
    else if( idade < 51){
        strcpy( ( atualizacao->faixa[1][ atualizacao->contFaixa[1] ] ) , especialidade);
        atualizacao->contFaixa[1]+=1;
    }
    else if(idade < 76){
        strcpy( ( atualizacao->faixa[2][ atualizacao->contFaixa[2] ] ) , especialidade);
        atualizacao->contFaixa[2]+=1;
    }
    else if(idade < 101){
        strcpy( ( atualizacao->faixa[3][ atualizacao->contFaixa[3] ] ) , especialidade);
        atualizacao->contFaixa[3]+=1;

    }


}


void exibeTodasAsFaixas(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";

    for(int faixaEtaria = 0; faixaEtaria < 4; faixaEtaria++){

        for(int especialidade = 0; especialidade < pesquisa->contFaixa[faixaEtaria]; especialidade++){

            if(!compStr(pesquisa->faixa[faixaEtaria][especialidade], " ")){

                for(int compara = especialidade + 1; compara < pesquisa->contFaixa[faixaEtaria]; compara++){

                    if( compStr(pesquisa->faixa[faixaEtaria][especialidade], pesquisa->faixa[faixaEtaria][compara]) ) {
                        cont1++;
                          strcpy(pesquisa->faixa[faixaEtaria][compara], " ");
                    }

                }

                if(cont1 > cont2){
                    cont2 = cont1;
                    strcpy(vencedor, pesquisa->faixa[faixaEtaria][especialidade]);
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
