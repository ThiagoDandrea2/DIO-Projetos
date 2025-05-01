#include <stdio.h>
#include <math.h>

// Função para exibir número em binário
void exibirBinario(int n) {
    if (n == 0) {
        printf("Binário: 0\n");
        return;
    }

    char bin[32];
    int i = 0;
    while (n > 0) {
        bin[i++] = (n % 2) + '0';
        n /= 2;
    }

    printf("Binário: ");
    for (int j = i - 1; j >= 0; j--) {
        putchar(bin[j]);
    }
    printf("\n");
}

int main() {
    double num1, num2, resultado;
    char operador;

    printf("Calculadora com conversões\n");
    printf("Operações: +  -  *  /  %%\n");
    printf("Digite no formato: número1 operador número2 (ex: 10 %% 3): ");
    scanf("%lf %c %lf", &num1, &operador, &num2);

    int resultadoInt;
    int operacaoValida = 1;

    switch (operador) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2lf\n", resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2lf\n", resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
                operacaoValida = 0;
            }
            break;
        case '%':
            if ((int)num2 != 0) {
                resultado = (int)num1 % (int)num2;
                printf("Resultado: %d\n", (int)resultado);
            } else {
                printf("Erro: Divisão por zero no módulo!\n");
                operacaoValida = 0;
            }
            break;
        default:
            printf("Operador inválido!\n");
            operacaoValida = 0;
    }

    if (operacaoValida) {
        resultadoInt = (int)resultado;

        // Exibir em diferentes bases numéricas
        printf("Decimal: %d\n", resultadoInt);
        printf("Octal: %o\n", resultadoInt);
        printf("Hexadecimal: %X\n", resultadoInt);
        exibirBinario(resultadoInt);
    }

    return 0;
}
