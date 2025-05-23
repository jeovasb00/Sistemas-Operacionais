#include <stdio.h>

int main()
{
    // Matriz para armazenar ID do Processo, Tempo de Execução,
    // Tempo Médio de Espera e Tempo Médio de Retorno.
    int A[100][4];
    int i, j, n, total = 0, indice, temp;
    float tempo_medio_espera, tempo_medio_retorno;

    printf("Digite o número de processos: ");
    scanf("%d", &n);

    printf("Digite o Tempo de Execução (Burst Time):\n");

    // Entrada do usuário para o Tempo de Execução e atribuição do ID do processo.
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &A[i][1]);
        A[i][0] = i + 1; // ID do processo
    }

    // Ordenando os processos de acordo com o Tempo de Execução (SJF não-preemptivo).
    for (i = 0; i < n; i++) {
        indice = i;
        for (j = i + 1; j < n; j++)
            if (A[j][1] < A[indice][1])
                indice = j;

        temp = A[i][1];
        A[i][1] = A[indice][1];
        A[indice][1] = temp;

        temp = A[i][0];
        A[i][0] = A[indice][0];
        A[indice][0] = temp;
    }

    A[0][2] = 0; // Tempo de espera do primeiro processo é zero

    // Cálculo dos Tempos de Espera
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1]; // Soma dos tempos de execução anteriores
        total += A[i][2];
    }

    tempo_medio_espera = (float)total / n;
    total = 0;

    printf("P     TE     TEsp    TRet\n");

    // Cálculo do Tempo de Retorno e impressão dos dados
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2]; // TRet = TE + TEsp
        total += A[i][3];
        printf("P%d     %d     %d      %d\n", A[i][0],
               A[i][1], A[i][2], A[i][3]);
    }

    tempo_medio_retorno = (float)total / n;

    printf("Tempo Médio de Espera = %f", tempo_medio_espera);
    printf("\nTempo Médio de Retorno = %f", tempo_medio_retorno);

    return 0;
}
