#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void timeConversion(char* time) {
    int hour;
    char format[3]; 

    
    sscanf(time, "%2d", &hour);
    strncpy(format, time + 8, 2);
    format[2] = '\0'; 

    if (strcmp(format, "AM") == 0) {
        if (hour == 12) {
            hour = 0;
        }
    } else if (strcmp(format, "PM") == 0) {
        if (hour != 12) {
            hour += 12;
        }
    }

    
    printf("%02d", hour);           
    for (int i = 2; i < 8; i++) {   
        putchar(time[i]);
    }
    printf("\n");
}

int main() {
    char time[11]; 
    scanf("%s", time);
    timeConversion(time);
    return 0;
}
