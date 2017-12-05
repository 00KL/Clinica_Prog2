#include <stdio.h>
#include <stdlib.h>
#include "procuraMedicos.c"

int main(){
    agMedico lucas;

    FILE *arqSaida, *arqEntrada;

    procuraMedico(&lucas);

    return 0;
}
