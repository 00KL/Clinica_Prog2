void colocarValores(agMedico *, int *, int , int , FILE *, char *);
void extrair(char *, int *, int *);
void colocarValor(agMedico *, int *, int, int);

void colocarValores(agMedico *medico, int *posicao, int indice, int cont, FILE *arqEntrada, char *str){

    fgets(str, 30, arqEntrada);

    indice = str[0] - 50;

    extrair(str, posicao, &cont);

    colocarValor(medico, posicao, indice, cont);
}

void extrair(char *str, int *posicao, int *cont){

    for(int i = 4; str[i-2] != '\n'; i += 3){
        switch(str[i]){
            case '8':
                posicao[*cont] = 0;
                *cont+= 1;
                break;
            case '9':
                posicao[*cont] = 1;
                *cont+= 1;
                break;
            case '0':
                posicao[*cont] = 2;
                *cont+=1;
                break;
            case '1':
                posicao[*cont] = 3;
                *cont+=1;
                break;
            case '2':
                posicao[*cont] = 4;
                *cont+=1;
                break;
            case '3':
                posicao[*cont] = 5;
                *cont+=1;
                break;
            case '4':
                posicao[*cont] = 6;
                *cont+=1;
                break;
            case '5':
                posicao[*cont] = 7;
                cont+=1;
                break;
            case '6':
                posicao[*cont] = 8;
                *cont+=1;
                break;
            case '7':
                posicao[*cont] = 9;
                *cont+=1;
                break;
        }
    }
}

void colocarValor(agMedico *medico, int *posicao, int indice, int cont){

    for(int i = 0; i < cont ; i++ ){
        medico->agenda[posicao[i]][indice] = -1;
    }

}
