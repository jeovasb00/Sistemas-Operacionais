// Programa em C para implementação do escalonamento FCFS  
#include<stdio.h> 

// Função para encontrar o tempo de espera de todos os processos 
void encontrarTempoEspera(int processos[], int n, int bt[], int wt[]) 
{ 
    // tempo de espera para o primeiro processo é 0 
    wt[0] = 0; 
  
    // calculando o tempo de espera 
    for (int i = 1; i < n ; i++ ) 
        wt[i] = bt[i-1] + wt[i-1]; 
} 
  
// Função para calcular o tempo de retorno 
void encontrarTempoRetorno(int processos[], int n, int bt[], int wt[], int tat[]) 
{ 
    // calculando o tempo de retorno somando bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
// Função para calcular o tempo médio 
void encontrarTempoMedio(int processos[], int n, int bt[]) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
  
    // Função para encontrar o tempo de espera de todos os processos 
    encontrarTempoEspera(processos, n, bt, wt); 
  
    // Função para encontrar o tempo de retorno de todos os processos 
    encontrarTempoRetorno(processos, n, bt, wt, tat); 
  
    // Exibir os processos com todos os detalhes 
    printf("Processos   Tempo de execução   Tempo de espera   Tempo de retorno\n"); 
  
    // Calcular o tempo total de espera e o tempo total de retorno 
    for (int i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf("   %d ", (i + 1));
        printf("       %d ", bt[i]);
        printf("       %d", wt[i]);
        printf("       %d\n", tat[i]); 
    } 
    float s = (float)total_wt / (float)n;
    float t = (float)total_tat / (float)n;
    printf("Tempo médio de espera = %f", s);
    printf("\n");
    printf("Tempo médio de retorno = %f ", t); 
} 
  
// Código principal 
int main() 
{ 
    // ID dos processos 
    int processos[] = { 1, 2, 3, 4 }; 
    int n = sizeof processos / sizeof processos[0]; 
  
    // Tempo de execução (burst time) de todos os processos 
    int burst_time[] = {10, 5, 8, 6}; 
  
    encontrarTempoMedio(processos, n, burst_time); 
    return 0; 
} 
// Este código foi contribuído por Shivi_Aggarwal
