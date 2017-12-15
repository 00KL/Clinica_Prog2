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
        strcpy(atualizacao->faixa[0][atualizacao->contFaixa[0]], especialidade);
        /*o valor do contador é atualizado para q na proxima pesquisa seja
        a especialidade seja escrita na posição correta da matriz faixa*/
        atualizacao->contFaixa[0]+=1;

    }
    else if( idade < 51){
        strcpy(atualizacao->faixa[1][atualizacao->contFaixa[1]], especialidade);
        atualizacao->contFaixa[1]+=1;
    }
    else if(idade < 76){
        strcpy(atualizacao->faixa[2][atualizacao->contFaixa[2]], especialidade);
        atualizacao->contFaixa[2]+=1;
    }
    else if(idade < 101){
        strcpy(atualizacao->faixa[3][atualizacao->contFaixa[3]], especialidade);
        atualizacao->contFaixa[3]+=1;

    }


}


void exibeTodasAsFaixas(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";

    for(int j = 0; j < 4; j++){


        for(int i = 0; i < pesquisa->contFaixa[j]; i++){

            if(!compStr(pesquisa->faixa[j][i], " ")){
                for(int j = i + 1; j < pesquisa->contFaixa[j]; j++){
                    if( compStr(pesquisa->faixa[j][i], pesquisa->faixa[j][i]) ) {
                        cont1++;
                          strcpy(pesquisa->faixa[j][i], " ");
                    }
                }
                if(cont1 > cont2){
                    cont2 = cont1;
                    strcpy(vencedor, pesquisa->faixa[j][i]);
                }
            }
        }

        switch (j) {
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

/*
void exibeFaixaDois(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";
    for(int i = 0; i < pesquisa->contFaixaDois; i++){

        if(!compStr(pesquisa->faixaDois[i], " ")){
            for(int j = i + 1; j < pesquisa->contFaixaDois; j++){
                if( compStr(pesquisa->faixaDois[i], pesquisa->faixaDois[j]) ) {
                    cont1++;
                    strcpy(pesquisa->faixaDois[j], " ");
                }
            }
            if(cont1 > cont2){
                cont2 = cont1;
                strcpy(vencedor, pesquisa->faixaDois[i]);
            }
        }
    }

    fprintf(arqDadosClinica," 26 -  50  %s", vencedor);

}
void exibeFaixaTres(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";
    for(int i = 0; i < pesquisa->contFaixaTres; i++){

        if(!compStr(pesquisa->faixaTres[i], " ")){
            for(int j = i + 1; j < pesquisa->contFaixaTres; j++){
                if( compStr(pesquisa->faixaTres[i], pesquisa->faixaTres[j]) ) {
                    cont1++;
                    strcpy(pesquisa->faixaTres[j], " ");
                }
            }
            if(cont1 > cont2){
                cont2 = cont1;
                strcpy(vencedor, pesquisa->faixaTres[i]);
            }
        }
    }

    fprintf(arqDadosClinica, " 51 -  75  %s", vencedor);

}
void exibeFaixaQuatro(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 0, cont2 = 0;
    char vencedor[dim] = " ";
    for(int i = 0; i < pesquisa->contFaixaQuatro; i++){

        if(!compStr(pesquisa->faixaQuatro[i], " ")){
            for(int j = i + 1; j < pesquisa->contFaixaQuatro; j++){
                if( compStr(pesquisa->faixaQuatro[i], pesquisa->faixaQuatro[j]) ) {
                    cont1++;
                    strcpy(pesquisa->faixaQuatro[j], " ");
                }
            }
            if(cont1 > cont2){
                cont2 = cont1;
                strcpy(vencedor, pesquisa->faixaQuatro[i]);
            }
        }
    }

    fprintf(arqDadosClinica, " 76 - 100  %s", vencedor);

}
*/
