#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int month[15];

void updateLeapYear(int year) {
    if (year % 400 == 0)
        month[2] = 29;
    else if (year % 100 == 0)
        month[2] = 28;
    else if (year % 4 == 0)
        month[2] = 29;
    else
        month[2] = 28;
}

void storeMonth() {
    month[1] = 31;
    month[2] = 28;
    month[3] = 31;
    month[4] = 30;
    month[5] = 31;
    month[6] = 30;
    month[7] = 31;
    month[8] = 31;
    month[9] = 30;
    month[10] = 31;
    month[11] = 30;
    month[12] = 31;
}

int findPrimeDates(int d1, int m1, int y1, int d2, int m2, int y2) {
    storeMonth();
    int result = 0;

    while (1) {
        int x = d1;
        x = x * 100 + m1;
        x = x * 10000 + y1;

        if (x % 4 == 0 || x % 7 == 0)
            result++;

        if (d1 == d2 && m1 == m2 && y1 == y2)
            break;

        updateLeapYear(y1);
        d1++;

        if (d1 > month[m1]) {
            m1++;
            d1 = 1;
            if (m1 > 12) {
                y1++;
                m1 = 1;
            }
        }
    }
    return result;
}

int main() {
    char line[100];
    int d1, m1, y1, d2, m2, y2;

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d-%d-%d %d-%d-%d", &d1, &m1, &y1, &d2, &m2, &y2);

    for (int i = 1; i < 15; i++)
        month[i] = 31;

    int result = findPrimeDates(d1, m1, y1, d2, m2, y2);
    printf("%d\n", result);

    return 0;
}
