#include <stdio.h>

#define MAX 100

typedef struct {
    int id;
    int at; // arrival time
    int bt; // burst time
    int rt; // remaining time
    int pr; // prioridade (menor valor = maior prioridade)
    int wt; // waiting time
    int tat; // turnaround time
    int completed;
} Processo;

int main() {
    Processo p[MAX];
    int n, time = 0, completed = 0;
    int i, shortest;
    
    printf("Digite o número de processos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Processo P%d:\n", p[i].id);
        printf("  Tempo de chegada: ");
        scanf("%d", &p[i].at);
        printf("  Tempo de execução (burst time): ");
        scanf("%d", &p[i].bt);
        printf("  Prioridade (menor número = maior prioridade): ");
        scanf("%d", &p[i].pr);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }

    printf("\nOrdem de execução:\n");

    while (completed != n) {
        shortest = -1;
        int min_pr = 9999;

        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].completed == 0 && p[i].pr < min_pr && p[i].rt > 0) {
                min_pr = p[i].pr;
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        printf("Tempo %d: P%d\n", time, p[shortest].id);
        p[shortest].rt--;
        time++;

        if (p[shortest].rt == 0) {
            p[shortest].completed = 1;
            completed++;
            p[shortest].tat = time - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
    }

    float total_wt = 0, total_tat = 0;
    printf("\nProcesso | Chegada | Duração | Prioridade | Espera | Retorno\n");
    for (i = 0; i < n; i++) {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("P%-7d | %-7d | %-7d | %-10d | %-6d | %-7d\n",
               p[i].id, p[i].at, p[i].bt, p[i].pr, p[i].wt, p[i].tat);
    }

    printf("\nTempo médio de espera: %.2f\n", total_wt / n);
    printf("Tempo médio de retorno: %.2f\n", total_tat / n);

    return 0;
}
