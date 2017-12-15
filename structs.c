//Constantes estabelicdas no enunciado
#define dim 30
#define h 10
#define d 5


int compStr(char *, char *);

//Tipo definido no enunciado
typedef struct {
    char nome[dim];
    int id;

    char especialidade[dim];
    int nConsultasSemana[4];

    int agenda[h][d];
    int consultas;
} agMedico;

//Cliente
typedef struct {
    char nome[dim];
    int id;
    char fone[dim];
    int idade;
    char medico[dim];
} cliente;

/*//Faixa etária
typedef struct {
    char faixa[dim][dim];
    int contFaixa;

} agFaixaEtaria;*/

//Faixa etária
typedef struct {
    char faixaUm[dim][dim];
    int contFaixaUm;

    char faixaDois[dim][dim];
    int contFaixaDois;

    char faixaTres[dim][dim];
    int contFaixaTres;

    char faixaQuatro[dim][dim];
    int contFaixaQuatro;
} agFaixaEtaria;

typedef struct{
  char especialidade[dim];
  int nEspecialidade;
  int nConsultas[4];
} esp;

//N será necessário exibir para o usuário
//uma string, porem para nos será importante
//para testar os valores q estão sendo registrados
//nos campos de uma string

  /*essa função está sendo usada para substituir a strcmp
  pois a strcmp ela não estava funcionando devidamente para as necessidades
  da dupla*/
int compStr(char *str, char *str1){

    /*variaveis necessárias para a função

    int cont irá acumular aquantidade de letras iguais
    de ambas as strings

    i irá acumular o tamanho da str em questão
    */
    int cont = 0, i = 0;

    /*o for irá percorrer as duas strings ate até q a primeira
    acabe, também poderia ser ate a segunda acabar.*/
    for(i = 0; str[i] != '\n' && str1[i] != '\n'; i++){
        /*ira comprar posição a posição da matriz*/
        if(str[i] == str1[i]){
            cont ++;
        }
    }

    if(cont == i){
        /*retorna '1' caso as strings sejam iguais*/
        return 1;
    }

    /*retorna '0' caso as strings sejam diferentes*/
    return 0;
}
