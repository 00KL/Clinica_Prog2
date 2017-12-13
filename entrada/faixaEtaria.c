//Questão 5
void iniciaFaixaEtaria(agFaixaEtaria *);
void exibeTodasAsFaixas(agFaixaEtaria *, FILE *);
void pesquisaDeFaixaEtaria(int , char *, agFaixaEtaria *);


/*como o proprio nome sugere a função só inicia os valores daquelas posiçoes na struct com valor 0, para que
nao haja erros causados por lixo de memoria*/
void iniciaFaixaEtaria(agFaixaEtaria *faixaEtaria){

    faixaEtaria[0].contFaixa = 0;
    faixaEtaria[1].contFaixa = 0;
    faixaEtaria[2].contFaixa = 0;
    faixaEtaria[3].contFaixa = 0;
}

/**/
void pesquisaDeFaixaEtaria(int idade, char *especialidade, agFaixaEtaria *faixaEtaria){

    /* idade refere-se ao ano de nascimento do pasciente.
    Considerando o ano atual 2017 e desconsederando os meses e dias,
    basta subtriar o ano de nascimento de 2017 q se tem a idade do
    pasciene.*/
    idade = 2017 - idade;

    /*Cada if representa uma das faixa etaria estabelecida no enunciado
    */
    if( idade < 26){
        /* respresentam cada faixa etaria são inicializados aqui
        assim sendo a posição atual esta vazia ou com lixo e deve ser sobreescrita
        com o valor q sera analizado por funçõe posteriores.*/
        strcpy( ( faixaEtaria[0].faixa[ faixaEtaria[0].contFaixa ] ) , especialidade);
        /*o valor do contador é atualizado para q na proxima pesquisa seja
        a especialidade seja escrita na posição correta da matriz faixa*/
        faixaEtaria[0].contFaixa+=1;

    }
    else if( idade < 51){
        strcpy( ( faixaEtaria[1].faixa[ faixaEtaria[1].contFaixa ] ) , especialidade);
        faixaEtaria[1].contFaixa+=1;
    }
    else if(idade < 76){
        strcpy( ( faixaEtaria[2].faixa[ faixaEtaria[2].contFaixa ] ) , especialidade);
        faixaEtaria[2].contFaixa+=1;
    }
    else if(idade < 101){
        strcpy( ( faixaEtaria[3].faixa[ faixaEtaria[3].contFaixa ] ) , especialidade);
        faixaEtaria[3].contFaixa+=1;

    }


}


void exibeTodasAsFaixas(agFaixaEtaria *pesquisa, FILE *arqDadosClinica){
    /*os cont são para checar */
    int cont1 = 0, cont2 = 0;

    /*ira armezar o vencedor referente a casa loop/faixa etaria*/
    char vencedor[dim] = " ";

    //Ira percorrer as faixas
    for(int faixaEtaria = 0; faixaEtaria < 4; faixaEtaria++){

        //ira percorer as especialidades da faixa em questão
        for(int especialidade = 0; especialidade < pesquisa[faixaEtaria].contFaixa; especialidade++){

            //ira checar se a posição do vetor faixa na posição especialidade
            //esta com um espaço, o q significa q ele ja foi lido, nesse caso
            //n é necessário checar essa posição
            if(!compStr(pesquisa[faixaEtaria].faixa[especialidade], " ")){

                //o for começa a contar da posição uma casa a frente
                //da posição "ESPECIALIDADE", pois ela q sera comparada com o
                //restante da matriz
                //Caso a posição ESPECIALIDADE + 1 seja o fim do vetor o for
                //n sera executado
                for(int compara = especialidade + 1; compara < pesquisa[faixaEtaria].contFaixa; compara++){

                    //Ira comparar a posição ESPECIALIDADE com todas as sequentes
                    if( compStr(pesquisa[faixaEtaria].faixa[especialidade], pesquisa[faixaEtaria].faixa[compara]) ) {
                        //ira contar as aparições da especialidade armazenada na
                        //posição ESPECIALIDADE do vetor Faixa
                        cont1++;
                        //ira por espaço vazio em todos as posições q ja foram
                        //checadas q contadas como repetições do
                        strcpy(pesquisa[faixaEtaria].faixa[compara], " ");
                    }

                }

                //ira checar se o contador CONT1 é maior q o contador
                //CONT2, com o objetivo de sobrescrever o cont2 para futuras
                //comparações.
                //CONT2 é iniciado como 0 para q qualquer quantidade seja maior
                // e substitua cont2
                if(cont1 > cont2){
                    cont2 = cont1;
                    //VENCEDOR ira ser sobrescrito com o nome da especialidade
                    //q tem mais requisições na faixaEtaria desse loop
                    strcpy(vencedor, pesquisa[faixaEtaria].faixa[especialidade]);
                }
            }
        }

        //Para cada faixaEtaria ira haver uma escrita diferente no arquivo
        //dadosClientes, seguindo os parametros do enunciado
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

        // ira zerar os dois contadores com o objetivo de novas comparações
        cont1 = 0;
        cont2 = 0;
        //ira colocar espeço no vetor VENCEDOR apenas para limpalo.
        strcpy(vencedor, " ");

    }

}
