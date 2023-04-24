/*Autor = Breno Henrique
Data = 17/04/2023
Descrição = O programa cria um menu com os 5 Exercicios de ponteiros passados ao fim do slide,sendo eles:
Exer 1: Faz a leitura de dois numeros ,alocando eles dinamicamente usando o malloc e apos fazendo suas respectivas apresentações.

Exer 2: Faz a leitura de quantos numeros o usuario quiser ,alocando eles dinamicamente usando malloc e aumentando o seu tamanho usando o comando realloc
ate o usuario digitar um numero negativo.Apos ,faz a apresentação desses respectivos numeros.

Exer 3: Define uma struct de cadastro para clientes e pede para usuario digitar a quantidade de cadastros que deseja entrar. Esse numero e usado
para definir o tamanho da memoria que ira ser alocada dinamicamente.Definida a memoria o usuario faz entrada dos cadastros desejados e apos o programa
faz a apresentação deles.

Exer4: Pede para o usuario entrar com a quantidade de linhas e colunas para a matriz ,fazendo a alocação dinamica usando elas para definir o tamanho
do malloc. Usando esse tamanho ,o sistema usa a função range para criar numero aleatorios e logo em seguida ele faz a apresentação deles

Exer 5:Cria uma struct para cadastros de automoveis ,alocando dinamicamente com 100 posiçoes. O sistema cria um menu para cadastrar o veiculo,
um para fazer a sua ediçao e um para fazer a listagem deles. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct Scadastro {
   int idade;
   int num_clientes;
   char nome[30];
   char telefone[14];
}Cadastro;

typedef struct sCarros{
    char nome[20];
    int ano;
    char cor[15];
    char combustivel[10];
    char direcao[20];
    int portas;
}Carros;

int elementos = 0;

int entrada(int **l){
    int j = 0,k;
    *l = (int*)malloc(1 * sizeof(int));
    printf("Digite quantos números desejar.Para parar, digite um número negativo..\n");
    do{
      scanf("%d",&k);
      (*l)[j] = k;
      j++;
      *l = realloc(*l,(j + 1)* sizeof(int));
    }while(k >= 0);
    return j;
}

void apresentar(int **l,int m){
    printf("----Valores Inseridos----\n\n");
    for(int i = 0;i < m - 1;i++){
        printf("%d\t",(*l)[i]);
    }
    printf("\n\n");
}

void exer1(){
    int *pa,*pb;
    pa = (int*) malloc(sizeof(int));
    pb = (int*) malloc(sizeof(int));

    printf("Entre um valor para A:");
    scanf("%d",pa);
    printf("\nEntre um valor para B:");
    scanf("%d",pb);

    system("cls || clear");

    printf("\nvalor a = %d",*pa);
    printf("\nvalor b = %d\n\n",*pb);

    free(pa);
    free(pb);

    while(getchar() != '\n');
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void exer2(){
    int *n;
    int j = 0;
    j = entrada(&n);
    system("clear || cls");
    apresentar(&n,j);
    free(n);
    while(getchar() != '\n');
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void exer3(){
    Cadastro cliente;
    Cadastro *pnum_clientes;

    printf("Digite a quantidade de clientes que deseja cadastrar:");
    scanf("%d",&cliente.num_clientes);

    pnum_clientes = (Cadastro *) malloc(cliente.num_clientes * sizeof(Cadastro));

    for(int i = 0;i < cliente.num_clientes;i++){
        printf("--- Cadastro ---\n");
        printf("Nome:");
        scanf(" %[^\n]",pnum_clientes[i].nome);
        printf("Telefone:");
        scanf(" %[^\n]",pnum_clientes[i].telefone);
        printf("Idade:");
        scanf("%d",&pnum_clientes[i].idade);
        printf("\n");

    }

    system("cls || clear");
    for(int i = 0;i < cliente.num_clientes;i++){
        printf("--- Cliente %d ---",i + 1);
        printf("\nNome: %s",pnum_clientes[i].nome);
        printf("\nTelefone: %s",pnum_clientes[i].telefone);
        printf("\nIdade: %d\n",pnum_clientes[i].idade);
    }
    while(getchar() != '\n');
    printf("Tecle <ENTER> para continuar...");
    getchar();

}

void exer4(){
    int **tam;
    int indice,linhas,colunas;

    printf("----Entre com Tamanho da matriz----\n");
    printf("Linhas:");
    scanf("%d",&linhas);


    printf("Colunas:");
    scanf("%d",&colunas);

    tam = (int **) malloc(linhas * sizeof(int*));
    srand(time(NULL));
    for(int i = 0;i < linhas;i++){
        tam[i] = (int *) malloc(colunas * sizeof(int));
        for(int j = 0;j < colunas;j++){
            indice = rand()%10;
            tam[i][j] = indice;
        }
    }
    printf("\nGerando números aleatórios \nAguarde.....\n");
    sleep(2);

    system("cls || clear");

    printf("\nMATRIZ:");
    for(int i = 0;i < linhas;i++){
        printf("\n");
        for(int j = 0;j < colunas;j++){
            printf("%d\t",tam[i][j]);
        }
    }
    printf("\n\n");
    while(getchar() != '\n');
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void cadastro_car(Carros **car){
    if(elementos > 100){
        printf("\nlimite de automóveis atingidos\n");
        return;
    }
    printf("---Cadastro do Automóvel---\n");

    printf("Nome do automóvel:");
    scanf(" %[^\n]",(*car)[elementos].nome);

    printf("Ano:");
    scanf("%d",&(*car)[elementos].ano);

    printf("Cor:");
    scanf(" %[^\n]",(*car)[elementos].cor);

    printf("Combustível:");
    scanf(" %[^\n]",(*car)[elementos].combustivel);

    printf("Direção:");
    scanf(" %[^\n]",(*car)[elementos].direcao);

    printf("Portas:");
    scanf("%d",&(*car)[elementos].portas);

    elementos++;
}

void editar(Carros **car){
    int edit;
    char comp[4];
    printf("Digite o Cadastro que deseja alterar:");
    scanf("%d",&edit);
    if(edit < 1 || edit > elementos ){
        printf("\nValor inválido!!\n");
        return;
    }
    while(getchar() != '\n');

    printf("Deseja alterar o nome do Automóvel:");
    scanf( "%[^\n]",comp);
    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Nome do automóvel:");
        scanf(" %[^\n]",(*car)[edit - 1].nome);
    }

    while(getchar() != '\n');
    printf("Deseja alterar o ano do Automóvel:");
    scanf( "%[^\n]",comp);

    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Ano:");
        scanf("%d",&(*car)[edit - 1].ano);
    }

    while(getchar() != '\n');
    printf("Deseja alterar a cor do Automóvel:");
    scanf( "%[^\n]",comp);

    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Cor:");
        scanf(" %[^\n]",(*car)[edit - 1].cor);
    }

    while(getchar() != '\n');
    printf("Deseja alterar o combustivel do Automóvel:");
    scanf( "%[^\n]",comp);

    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Combustivel:");
        scanf(" %[^\n]",(*car)[edit - 1].combustivel);
    }

    while(getchar() != '\n');
        printf("Deseja alterar a direcao do automóvel:");
        scanf( "%[^\n]",comp);

    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Direção:");
        scanf(" %[^\n]",(*car)[edit - 1].direcao);
    }

    while(getchar() != '\n');
    printf("Deseja alterar o número de portas:");
    scanf( "%[^\n]",comp);

    if(strcmp("sim", comp) == 0 || strcmp("Sim", comp) == 0 || strcmp("S", comp) == 0 || strcmp("s", comp) == 0){
        printf("Portas:");
        scanf("%d",&(*car)[edit - 1].portas);
    }
}

void listar(Carros **car){
    for(int i = 0;i < elementos;i++){
        printf("---Automóvel %d---",i+1);
        printf("\n %s",(*car)[i].nome);
        printf("\nAno: %d",(*car)[i].ano);
        printf("\nCor: %s",(*car)[i].cor);
        printf("\nCombustivel: %s",(*car)[i].combustivel);
        printf("\nDireção: %s",(*car)[i].direcao);
        printf("\nPortas: %d\n\n",(*car)[i].portas);
    }
}

void exer5(){
    Carros *carros;
    int op = 0;
    carros = (Carros*) malloc(100 * sizeof(Carros));
    while(op != 4){
        printf("----Menu de Veiculos----\n");
        printf("1 - Cadastrar\n2 - Editar\n");
        printf("3 - Listar\n4 - Fim\n");
        scanf("%d",&op);
        switch(op){
        case 1:
            cadastro_car(&carros);
            break;
        case 2:
            editar(&carros);
            break;
        case 3:
            listar(&carros);
            break;
        case 4:
            printf("\nVoltando ao Menu....\n");
            sleep(2);
            system("cls || clear");
            break;
        default:
            printf("\nValor inválido!!\n");
        }
    }
}

int main(void){
    int op = 0;
    setlocale(LC_ALL,"Portuguese");
    while(op != 6){
    printf("----MENU----\n");
    printf("1 - Exer1\n2 - Exer2\n");
    printf("3 - Exer3\n4 - Exer4\n");
    printf("5 - Exer5\n6 - Fim\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            exer1();
            break;
        case 2:
            exer2();
            break;
        case 3:
            exer3();
            break;
        case 4:
            exer4();
            break;
        case 5:
            exer5();
            break;
        case 6:
            printf("\nFinalizando....\n");
            sleep(2);
            break;
        default:
            printf("\nValor invalido!!\n");
        }
    }


}
