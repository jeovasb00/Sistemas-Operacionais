#include <stdio.h>

int main() {
    int n, i, j;
    int at[20], bt[20], pid[20], wt[20], tat[20], completed[20];
    int exec_order[20];
    int current_time = 0, completed_count = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Digite o número de processos: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Processo %d\n", i + 1);
        printf("Tempo de chegada: ");
        scanf("%d", &at[i]);
        printf("Tempo de execução (burst): ");
        scanf("%d", &bt[i]);
        pid[i] = i + 1;
        completed[i] = 0;
    }

    while(completed_count < n) {
        int idx = -1;
        int min_bt = 1e9;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                } else if(bt[i] == min_bt) {
                    if(at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if(idx != -1) {
            wt[idx] = current_time - at[idx];
            current_time += bt[idx];
            tat[idx] = wt[idx] + bt[idx];
            completed[idx] = 1;
            exec_order[completed_count] = idx; // salva ordem de execução
            completed_count++;
        } else {
            current_time++;
        }
    }

    printf("\nOrdem de execução:\n");
    for(i = 0; i < n; i++) {
        printf("P%d ", pid[exec_order[i]]);
    }

    printf("\n\nPID\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;
    printf("\nTempo médio de espera = %.2f\n", avg_wt);
    printf("Tempo médio de retorno = %.2f\n", avg_tat);

    return 0;
}