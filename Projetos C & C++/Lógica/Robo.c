#include <stdio.h>
#include <math.h>

int main() {
    int largura, comprimento;
    double area, tempo;

    // Entrada dos dados
    printf("Digite a largura da sala (em metros): ");
    scanf("%d", &largura);

    printf("Digite o comprimento da sala (em metros): ");
    scanf("%d", &comprimento);

    // Calculando a área
    area = largura * comprimento;

    // Calculando o tempo (5 m²/min) e arredondando para cima
    tempo = ceil(area / 5.0);

    // Verificando se o tempo ultrapassa 2 horas (120 minutos)
    if (tempo > 120) {
        printf("A sala é muito grande. O robô não conseguirá limpar em menos de 2 horas.\n");
    } else {
        printf("O robô de limpeza levará %.0lf minutos para limpar a sala.\n", tempo);
    }

    return 0;
}
