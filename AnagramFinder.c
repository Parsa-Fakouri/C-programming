#include <stdio.h>
#include <string.h>

int main(void) {
    int counter1[4] = {0, 0, 0, 0}; // Counters for 'a', 'b', 'c', 'd'
    int counter2[4] = {0, 0, 0, 0}; // Counters for 'a', 'b', 'c', 'd'
    int flag = 1;

    char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
    char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";

    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] == 'a') {
            counter1[0]++;
        } else if (s1[i] == 'b') {
            counter1[1]++;
        } else if (s1[i] == 'c') {
            counter1[2]++;
        } else if (s1[i] == 'd') {
            counter1[3]++;
        }
    }

    for (int j = 0; j < strlen(s2); j++) {
        if (s2[j] == 'a') {
            counter2[0]++;
        } else if (s2[j] == 'b') {
            counter2[1]++;
        } else if (s2[j] == 'c') {
            counter2[2]++;
        } else if (s2[j] == 'd') {
            counter2[3]++;
        }
    }

    for (int x = 0; x < 4; x++) {
        if (counter1[x] != counter2[x]) {
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("Anagram!\n");
    } else {
        printf("Not Anagram!\n");
    }

    return 0;
}

