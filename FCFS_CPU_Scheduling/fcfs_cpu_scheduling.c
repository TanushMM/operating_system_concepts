// FCFS CPU Scheduling

#include <stdio.h>

int waiting_time(int process[], int n, int burst_time[], int wait_time[]){
    wait_time[0] = 0;
    for(int i =1; i < n; i++){
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
    }
    return 0;
}
int turn_around_time(int process[], int n, int burst_time[], int wait_time[], int tat[]){
    for(int i =0; i < n; i++){
        tat[i] = wait_time[i] + burst_time[i];
    }
    return 0;
}

int avg_time(int process[], int n, int burst_time[]){
    int wait_time[n], tat[n], total_wt, total_tat;
    waiting_time(process, n, burst_time, wait_time);
    turn_around_time(process, n, burst_time, wait_time, tat);
    printf("\nProcess\t Burst Time\t Waiting time\t TAT\n");
    for(int i =0; i < n; i++){
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("%d \t %d \t\t %d \t\t %d \n", process[i], burst_time[i], wait_time[i], tat[i]);
    }
    printf("Total Waiting Time: %f\n", (float)total_wt/(float)n);
    printf("Total Turn Around Time: %f", (float)total_tat/(float)n);
}

int main(){
    int process[] = {1,2,3};
    int n = 3;
    int burst_time[] = {3,5,1};
    avg_time(process, n, burst_time);
}