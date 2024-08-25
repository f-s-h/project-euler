#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

int daysMonth(int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
          return 31;
        case 4: case 6: case 9: case 11:
          return 30;
        default: return 0;
    }
}

int nrDays(int month, int year) {
    if(month == 2) {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else {
      return daysMonth(month);
    }
}

int countSundays(int startYear, int endYear) {
    int count = 0;
    // Assumes that startDay is a monday
    int currentDay = 1;

    for(int year = 1900; year < startYear; year++) {
        for(int month = 1; month <= 12; month++) {
            currentDay += nrDays(month, year);
        }
    }


    for(int year = startYear; year <= endYear; year++) {
        for(int month = 1; month <= 12; month++) {
            if(currentDay % 7 == 0) {
                count++;
            }
            currentDay += nrDays(month, year);
        }
    }

    return count;
}

int main(void) {
    // start year >= 1900
    int startYear = 1901;
    int endYear = 2000;

    int result = countSundays( startYear, endYear);

    printf("Numbers of sundays on the first of month: %d\n", result);
    return EXIT_SUCCESS;
}
