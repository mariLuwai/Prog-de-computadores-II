//exercicio 2
#include <stdio.h>
#include <stdlib.h>




int main(){
    int L, C, m, n; 
    scanf("%d %d %d %d", &L, &C, &m, &n);

    int **mat = (int**) malloc (L * sizeof(int)); //alocação das linhas

    for(int i = 0; i < L; i++) *(mat + i) = (int *) malloc (C * sizeof (int)); //alocação das colunas
    

    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            scanf ("%d", *(mat + i) + j); //atribuição de valor
        }
    }

    int maior = 0 ;
    for(int i = 0; i < L; i += m){ //percorre todos os elementos de M a M da matriz
        for(int j = 0; j < C; j += n){ // percorre todos os elementos de N a N da matriz

            int contar = 0;

            for(int k = i; k < (i+m); k++){ //a partir dos blocos MxN, percorre todo o lote
                for(int v = j; v < (j+n); v++){
                    contar += *(*(mat + k) + v); //soma a quantidade de vasos no lote
                }
            }
            
            if(maior < contar) maior = contar; //comparação para encontrar o maior
        }


    }

    printf("%d \n", maior);

    for(int i = 0; i < L; i++) free(mat+i); //free das colunas
    free(mat); //free das linhas


    return 0;
}
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  //exercicio 3

  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func{
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;


//assinatura das funções

void * inicializa (Tfunc *cadastro, int funcionarios);
void * inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais);
void imprime (Tfunc *cadastro, int beg, int end);


int main(void){
    Tfunc *cadastro;
    int funcionarios, adicionais;

    printf("Quantos funcionarios? ");
    scanf("%d",&funcionarios);


    cadastro = inicializa(cadastro, funcionarios);
    if (!cadastro) return -1;


    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d",&adicionais);


    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    if (!cadastro) return -1;


    printf("Lista de funcionarios cadastrados\n");
    imprime(cadastro, 0, funcionarios+adicionais);


    free(cadastro);
    return 0;
}




//deve alocar dinamicamente o vetor de estruturas e 
//armazenar as informações de cada funcionário solicitadas ao usuário (a partir do teclado)


void *inicializa(Tfunc *cadastro, int funcionarios){
    cadastro = (Tfunc *) malloc (funcionarios * sizeof(Tfunc)); //aloca a memória 
    if(cadastro == NULL){ //verificação
        printf("Erro de alocacao de memoria\n");
        return NULL;
    }

    for(int i = 0; i < funcionarios; i++){ //atribuição de valores
        printf("Nome do funcionario %d: ", i+1);
        scanf("%s", cadastro[i].nome);
        printf("Ano de nascimento do funcionario %d: ", i+1);
        scanf("%d", &cadastro[i].ano_nasc);
        printf("Renda do funcionario %d: ", i+1);
        scanf("%f", &cadastro[i].renda);
    }
    return cadastro;
}




//deve realocar dinamicamente o vetor de estruturas 
//para armazenar as informações de mais usuários


void *inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais){
    cadastro = (Tfunc *) realloc (cadastro, (funcionarios + adicionais) * sizeof(Tfunc)); //realoca a memória
    if(cadastro == NULL){ //verificação
        printf("Erro de realocacao de memoria\n");
        return NULL;
    }

    for(int i = funcionarios; i < funcionarios + adicionais; i++){ //atribuição de valor
        printf("Nome do funcionario %d: ", i+1);
        scanf("%s", cadastro[i].nome);
        printf("Ano de nascimento do funcionario %d: ", i+1);
        scanf("%d", &cadastro[i].ano_nasc);
        printf("Renda do funcionario %d: ", i+1);
        scanf("%f", &cadastro[i].renda);
    }
    return cadastro;
}




//deve exibir (em tela) as informações dos funcionários no intervalo de posições indicado; 
//para mostrar as informações de todos os funcionários, o intervalo deve ser 0 a funcionarios+adicionais


void imprime(Tfunc *cadastro, int beg, int end){
    for(int i = beg; i < end; i++){ 
        printf("Nome: %s\n", cadastro[i].nome);
        printf("Ano de nascimento: %d\n", cadastro[i].ano_nasc);
        printf("Renda: %.2f\n\n", cadastro[i].renda);
    }
}

