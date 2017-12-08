void nomeLista(FILE *arqLista, char *nomeMedico, char *lixo, int *id){
    fgets(lixo, 30, arqLista);
    fscanf( arqLista ,"%d\n", id);
    fgets(lixo, 30, arqLista);
    fgets(lixo, 30, arqLista);
    fgets(nomeMedico, dim, arqLista);

    //printf("%d \n%s", *id, nomeMedico);
}

void nomesListas(FILE *, agMedico *);
void nomeLista(FILE *, char *, char *, int *);

void nomesListas(FILE *arqLista, agMedico *medico){
    char nomeMedico[dim], lixo[dim];
    int id;

    srand(time(NULL) );

    while(! feof(arqLista) ){
        nomeLista(arqLista, nomeMedico, lixo, &id);
        //printf("%d \n", id);
        //printf("%c  %c  \n", nomeMedico[11],medico->nome[11]);

        if(compStr(nomeMedico, medico->nome)){
            //printf("%s %s\n" , nomeMedico, medico->nome);
            aleatorio(medico, id, nomeMedico);
        }

        fgets(lixo, 30, arqLista);
    }
}
