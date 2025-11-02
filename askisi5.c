#include <stdio.h>
#include <string.h>

#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int age;
    int games;
    int goals;
} Player;

void stats(Player players[], int n, Player result[2]) {
    int i;
    int maxGoalsIdx = 0;
    int maxAvgIdx = 0;

    for (i = 1; i < n; i++) {
        if (players[i].goals > players[maxGoalsIdx].goals)
            maxGoalsIdx = i;

        double curAvg = (players[i].games > 0) ? (double)players[i].goals / players[i].games : 0.0;
        double bestAvg = (players[maxAvgIdx].games > 0) ? (double)players[maxAvgIdx].goals / players[maxAvgIdx].games : 0.0;

        if (curAvg > bestAvg)
            maxAvgIdx = i;
    }

    result[0] = players[maxGoalsIdx];
    result[1] = players[maxAvgIdx];
}

int main(void) {
    int N, i;
    printf("Dose to plithos twn paiktwn: ");
    scanf("%d", &N);

    Player players[N];

    for (i = 0; i < N; i++) {
        printf("\n== Paiktis %d ==\n", i + 1);
        printf("Onoma: ");
        scanf("%s", players[i].name);
        printf("Hlikia: ");
        scanf("%d", &players[i].age);
        printf("Agwnes: ");
        scanf("%d", &players[i].games);
        printf("Goal: ");
        scanf("%d", &players[i].goals);
    }

    Player result[2];
    stats(players, N, result);

    printf("\n--- APOTELESMATA ---\n");
    printf("Perissotera goal: %s (%d goal)\n", result[0].name, result[0].goals);

    double avg = (result[1].games > 0) ? (double)result[1].goals / result[1].games : 0.0;
    printf("Megaluteros mesos oros goal/agwna: %s (%.2f)\n", result[1].name, avg);

    printf("\nPata enter gia eksodo...");
    getchar();
    getchar(); 

    return 0;
}