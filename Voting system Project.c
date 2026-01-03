#include <stdio.h>

int main() {
    int candidates, voters;

    printf("Number of candidates: ");
    scanf("%d", &candidates);

    int votes[candidates];
    for (int i = 0; i < candidates; i++) {
        votes[i] = 0;
    }

    printf("Number of voters: ");
    scanf("%d", &voters);

    for (int i = 1; i <= voters; i++) {
        int choice;
        printf("Choose candidates(1 to %d)\n" ,candidates);
        printf("Voter %d: ", i);

        scanf("%d", &choice);

        if (choice >= 1 && choice <= candidates) {
            votes[choice - 1]++;
        }
        else {
            printf("Invalid vote!\n");
        }
    }

    int winner = 0;
    for (int i = 1; i < candidates; i++) {
        if (votes[i] > votes[winner]){
            winner = i;
    }
}

    printf("Result:\n");
    for (int i = 0; i < candidates; i++) {
        printf("Candidate %d :", i + 1);
        printf(" %d votes\n", votes[i]);
    }

    printf("Winner of the candidates is:");
    printf(" candidate %d\n ", winner + 1 );
    printf("By the number of votes:");
    printf(" %d\n", votes[winner] );
    return 0;
}