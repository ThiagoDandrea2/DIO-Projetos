#include <stdio.h>

int main() {
    double num1, num2;
    char operador;

    printf("Calculadora simples em C\n");
    printf("Operações suportadas: +  -  *  /  %% (resto da divisão)\n");
    printf("Digite a operação no formato: número1 operador número2 (ex: 5 %% 2): ");
    scanf("%lf %c %lf", &num1, &operador, &num2);

    switch (operador) {
        case '+':
            printf("Resultado: %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Resultado: %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Resultado: %.2lf\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Resultado: %.2lf\n", num1 / num2);
            else
                printf("Erro: Divisão por zero!\n");
            break;
        case '%':
            if ((int)num2 != 0)
                printf("Resultado: %d\n", (int)num1 % (int)num2);
            else
                printf("Erro: Divisão por zero no módulo!\n");
            break;
        default:
            printf("Operador inválido!\n");
    }

    return 0;
}
