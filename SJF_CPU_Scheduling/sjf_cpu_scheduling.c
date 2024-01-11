// SJF CPU Scheduling

#include <stdio.h>
#include <stdlib.h>

int waiting_time(int process[], int n, int burst_time[], int wait_time[]){
    wait_time[0] = 0;
    for(int i = 1; i < n; i++){
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
    }
    return 0;
}

int turn_around_time(int process[], int n, int burst_time[], int wait_time[], int tat[]){
    for(int i = 1; i < n; i++){
        tat[i] = wait_time[i] + burst_time[i];
    }
    return 0;
}

void avg_time(int process[], int n, int burst_time[]){
    int i, j;
    int wait_time[n], tat[n], total_wt, total_tat;
    // Sorting begins
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (burst_time[j] > burst_time[j + 1]){
                int temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
                // swap(process[j], process[j + 1]);
                // swap(burst_time[j], burst_time[j + 1]);
            }
        }
    }
    // Sorting ends
    waiting_time(process, n, burst_time, wait_time);
    turn_around_time(process, n, burst_time, wait_time, tat);
    printf("Process\t   burst time\twaiting time\t turn around time\n");
    for(int i =0;i<n;i++){
        total_wt = total_wt + wait_time[i];
        total_tat = total_tat + tat[i];
        printf("P%d \t   %d \t\t%d \t\t %d \n", process[i], burst_time[i], wait_time[i], tat[i]);
    }
}

int main(){
    int process[] = {1,2,3};
    int n = sizeof(process) / sizeof(process[0]);
    int burst_time[] = {3,1,5};
    avg_time(process, n, burst_time);
}