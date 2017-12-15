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

    resultado->contFaixaUm = 0;

    resultado->contFaixaDois = 0;

    resultado->contFaixaTres = 0;

    resultado->contFaixaQuatro = 0;
}

/**/
void pesquisaDeFaixaEtaria(int idade, char *especialidade, agFaixaEtaria *atualizacao){


    char lixo;

    if( idade < 26){
        strcpy(atualizacao->faixaUm[atualizacao->contFaixaUm], especialidade);
        atualizacao->contFaixaUm+=1;

    }
    else if( idade < 51){
        strcpy(atualizacao->faixaDois[atualizacao->contFaixaDois], especialidade);
        atualizacao->contFaixaDois+=1;
        //printf("%d -> %s\n", atualizacao->contFaixaDois, atualizacao->faixaDois[atualizacao->contFaixaDois-1]);
    }
    else if(idade < 76){
        strcpy(atualizacao->faixaTres[atualizacao->contFaixaTres], especialidade);
        atualizacao->contFaixaTres+=1;
    }
    else if(idade < 101){
        strcpy(atualizacao->faixaQuatro[atualizacao->contFaixaQuatro], especialidade);
        atualizacao->contFaixaQuatro+=1;

    }


}
void exibeTodasAsFaixas(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){

    exibeFaixaUm(pesquisa, arqDadosClinica);
    exibeFaixaDois(pesquisa, arqDadosClinica);
    exibeFaixaTres(pesquisa, arqDadosClinica);
    exibeFaixaQuatro(pesquisa, arqDadosClinica);
}
void exibeFaixaUm(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 1, cont2 = 1;
    char vencedor[99] = "Não há consultas para essa faixa etaria\n";

    //printf("%d\n", pesquisa->contFaixaUm);
    for(int i = 0; i < pesquisa->contFaixaUm; i++){

        if(pesquisa->faixaUm[i][0] !=  ' '){

            for(int j = i + 1; j < pesquisa->contFaixaUm; j++){
                if( compStr(pesquisa->faixaUm[i], pesquisa->faixaUm[j]) ) {

                    cont1++;
                    strcpy(pesquisa->faixaUm[j], " ");
                }
            }

            if(cont1 > cont2){
                cont2 = cont1;

                strcpy(vencedor, pesquisa->faixaUm[i]);

            }
            cont1 = 1;

        }

    }

    fprintf(arqDadosClinica,"  0 -  25  %s", vencedor);


}
void exibeFaixaDois(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 1, cont2 = 1;
    char vencedor[99] = "Não há consultas para essa faixa etaria\n";
    for(int i = 0; i < pesquisa->contFaixaDois; i++){

        if( pesquisa->faixaDois[i][0] !=  ' '){
            ///printf("%d\n", pesquisa->contFaixaDois);
            for(int j = i + 1; j < pesquisa->contFaixaDois; j++){
                if( compStr(pesquisa->faixaDois[i], pesquisa->faixaDois[j]) ) {
                    cont1++;

                    //printf("%d -> %s", cont1, pesquisa->faixaDois[i]);
                    strcpy(pesquisa->faixaDois[j], " ");
                }
            }
            if(cont1 > cont2){
                    //printf("%d -> %s", cont1, pesquisa->faixaDois[i]);
                cont2 = cont1;
                strcpy(vencedor, pesquisa->faixaDois[i]);

            }
            cont1 = 1;
        }
    }

    fprintf(arqDadosClinica," 26 -  50  %s", vencedor);

}
void exibeFaixaTres(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 1, cont2 = 1;
    char vencedor[99] = "Não há consultas para essa faixa etaria\n";
    for(int i = 0; i < pesquisa->contFaixaTres; i++){

        if( pesquisa->faixaTres[i][0] !=  ' ' ){
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
            cont1 = 1;
        }
    }

    fprintf(arqDadosClinica, " 51 -  75  %s", vencedor);

}
void exibeFaixaQuatro(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    int cont1 = 1, cont2 = 1;
    char vencedor[99] = "Não há consultas para essa faixa etaria\n";
    for(int i = 0; i < pesquisa->contFaixaQuatro; i++){

        if(pesquisa->faixaQuatro[i][0] !=  ' '){
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

            cont1 = 1;
        }
    }

    fprintf(arqDadosClinica, " 76 - 100  %s", vencedor);

}
