#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define NAME_LEN 100

// Structure to store candidate and votes
struct Candidate {
    char name[NAME_LEN];
    int votes;
};

// Function to find index of candidate
int findCandidate(struct Candidate arr[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0)
            return i;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Candidate arr[MAX];
    int size = 0;

    char name[NAME_LEN];

    // Count votes
    for (int i = 0; i < n; i++) {
        scanf("%s", name);

        int idx = findCandidate(arr, size, name);

        if (idx == -1) {
            // New candidate
            strcpy(arr[size].name, name);
            arr[size].votes = 1;
            size++;
        } else {
            // Existing candidate
            arr[idx].votes++;
        }
    }

    // Find winner
    char winner[NAME_LEN];
    int maxVotes = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i].votes > maxVotes) {
            maxVotes = arr[i].votes;
            strcpy(winner, arr[i].name);
        } else if (arr[i].votes == maxVotes) {
            // Lexicographically smaller
            if (strcmp(arr[i].name, winner) < 0) {
                strcpy(winner, arr[i].name);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
