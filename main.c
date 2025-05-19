#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50
#define MAX_SUB_SIZE 20

#define MAX_LENGTH 100
#include <ctype.h>

// Helena Barbosa Costa RM562450
// Isabelle Dias Belini RM566464
// Felipe Rodrigues Ribeiro dos Santos RM565274
// Ryan Amorim De Castro Santana RM 564393


// 1 - Função: Sequência Fibonacci
void fibonacci(int nF){
    int n1[50];
    int i;

    n1[0] = 0;
    if (nF > 1) n1[1] = 1;

    // calculo
    for (i = 2; i < nF; i++){
        n1[i] = n1[i - 1] + n1[i - 2];
    }

    //imprime
    for (i = 0; i < nF; i++) {
            printf("%d ", n1[i]);
        }

    printf("\n");
}

// 2 - Função: Fatoriais
int fatoriais(int n){

    int nFatoriais[n];
    int index = 0;

    // Populando vetor
    for(int i = n; i>= 1; i--){
        nFatoriais[index] = i;
        index++;
    }

    // Declarando varialvel que vai armazenar o resultado final do fatorial
    int resFatorial = 1;

    // For para passar pelo vetor e multiplicar o valor atual pelo número na posiçaõ do vetor
    for (int i = 0; i < n; i++){
        resFatorial *= nFatoriais[i];
    }

    printf("Fatorial de %d e %d\n", n, resFatorial);
    return resFatorial;
}

// 3 - Função: Verificar Palíndromo
int eh_palindromo() {
    char palavra[MAX_LENGTH];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int length = strlen(palavra);
    for (int i = 0; i < length / 2; i++) {
        if (tolower(palavra[i]) != tolower(palavra[length - 1 - i])) {
            return 0; // Não é um palíndromo
        }
    }
    return 1; // É um palíndromo
}



// 4 - Função: Verificar Substring
int substring() {
    char str1[MAX_SIZE];
    char str2[MAX_SUB_SIZE];

    printf("Digite a primeira string: ");
    fgets(str1, MAX_SIZE, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Digite a segunda string: ");
    fgets(str2, MAX_SUB_SIZE, stdin);
    str2[strcspn(str2, "\n")] = 0;

    if (strstr(str1, str2) != NULL) {
        printf("A segunda string esta contida na primeira.\n");
    } else {
        printf("A segunda string NAO esta contida na primeira.\n");
    }

    return 0;
}


int main(){

    int option;
    char con;

    do{
        printf("Seja bem-vindo a CP02, qual exercicio gostaria de testar?\n");
        printf("");
        printf("1 - Sequencia Fibonacci\n");
        printf("2 - Fatoriais\n");
        printf("3 - Verificacao de Palindromo\n");
        printf("4 - Verificacao de Substring\n");
        scanf ("%d", & option);
        getchar();

        switch (option)
        {
        case  1:
            // declaração da variável que indica o número de posições do vetor
            int nF;
            printf("Voce selecionou: Sequencia Fibonacci\n");
            printf("Digite a quantidade de termos da sequencia de Fibonacci (1 a 50):\n");
            scanf("%d", &nF);

            while (nF < 1 || nF > 50) {
                printf("Valor errado, tente novamente!\n");
                scanf("%d", &nF);
            }

            //Chamando a função
            fibonacci(nF);
            break;

        case 2:
            // Declaração da variável que armazena o número para calcúlo do fatorial
            int n;
            printf("Voce selecionou: Fatoriais\n");
            printf("Digite o numero voce deseja calcular seu fatorial (de 1 a 20)\n");
            scanf(" %d", &n);

            // Limitação de números de 1 a 20
            while (n < 1 || n > 20) {
                printf("So aceitamos numeros entre 1 a 20! Tente novamente :)\n");
                scanf(" %d", & n);
            };

            //Chamada da função
            fatoriais(n);
            break;

        case 3:
            printf("Voce selecionou: Verificacao de Palindromo\n");
            if (eh_palindromo()) {
                printf("A palavra, numero ou frase e um palindromo.\n");
            } else {
                printf("A palavra, numero ou frase NAO e um palindromo.\n");
            }
            break;

        case 4:
            printf("Voce selecionou: Verificacao de Substring\n");
            substring();
            break;

        default:
            printf("Opcao invalida. Por favor, selecione entre 1 e 4.\n");
            break;
        }

        printf("\nDeseja continuar testando? (y/n): ");
        scanf (" %c", & con);

    } while (con == 'y');

    printf("\nPrograma encerrado, esperamos que tenha gostado!\n");

    return 0;

}

