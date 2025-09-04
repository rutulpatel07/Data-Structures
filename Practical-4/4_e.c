// e) Tower of Hanoi problem

#include <stdio.h>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    // Step 1: move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, from, aux, to);

    // Step 2: move the nth disk from source to destination
    printf("Move disk %d from %c to %c\n", n, from, to);

    // Step 3: move n-1 disks from auxiliary to destination
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("The moves are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // source=A, destination=C, aux=B

    return 0;
}
