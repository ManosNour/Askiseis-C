#include <stdio.h>

int main(void) {
    FILE *fp;
    int N, i;
    double sum = 0.0;

    fp = fopen("goals.txt", "r");
    if (fp == NULL) {
        printf("Den vriskei to arxeio goals.txt\n");
        return 1;
    }

    if (fscanf(fp, "Arithmos Agwnwn: %d", &N) != 1) {
        printf("Sfalma sthn anagnwsh tou plithous agwnwn.\n");
        fclose(fp);
        return 1;
    }

    char label[50];
    fscanf(fp, "%s %s %s", label, label, label); 

    int goals[N];

    for (i = 0; i < N; i++) {
        if (fscanf(fp, "%d", &goals[i]) != 1) {
            printf("Sfalma sthn anagnwsh twn goal (sth thesi %d).\n", i + 1);
            fclose(fp);
            return 1;
        }
        sum += goals[i]; 
    }

    fclose(fp);

    double avg = (N > 0) ? sum / N : 0.0;

    printf("Agwnes: %d\n", N);
    printf("Goal ana agwna: ");
    for (i = 0; i < N; i++) printf("%d ", goals[i]);
    printf("\n");
    printf("\nSynolika goal: %.0f\n", sum);       
    printf("Mesos oros twn goal/agwna: %.2f\n", avg);   

    printf("\nPata Enter gia eksodo...");
    getchar(); 
    getchar(); 

    return 0;
}