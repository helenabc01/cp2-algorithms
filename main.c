#include <stdio.h>

// Helena Barbosa Costa RM562450

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

    printf("Fatorial de %d é %d\n", n, resFatorial);
    return resFatorial;
 
}


int main(){
    
    int option;
    char con;

    do{
        printf("Seja bem-vindo à CP02, qual exercício gostaria de testar?\n");
        printf("1 - Sequência Fibonacci\n");
        printf("2 - Fatoriais\n");
        printf("3 - Verificação de Pelíndromo\n");
        printf("4 - Verificação de Substring\n");
        scanf ("%d", & option);

        switch (option)
        {
        case  1:
            printf("Sequência Fibonacci");
            break;
        
        case 2:
            // Declaração da variável que armazena o número para calcúlo do fatorial
            int n;
            printf("Digite o número você deseja calcular seu fatorial (de 1 a 20)\n");
            scanf(" %d", & n);

            // Limitação de números de 1 a 20
            while (n < 1 || n > 20) {
                printf("Só aceitamos números entre 1 a 20! Tente novamente :)");
                scanf(" %d", & n);
            };

            //Chamada da função
            fatoriais(n);
            break;

        case 3:
            printf("Verificação de Pelíndromo");
            break;
        case 4:
            printf("Verificação de Substring");
            break;
        
        default:
            break;
        }

        printf("\nDeseja continuar testando? (y/n): ");
        scanf (" %c", & con);
        
    } while (con == 'y');

    printf("\nPrograma encerrado, esperamos que tenha gostado!\n"); 
    
    return 0;

}

