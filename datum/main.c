#include <stdio.h>
#include <stdlib.h>

#define MIN_YEAR 1900
#define MAX_YEAR 2023
#define ERROR 0
int input(const char *text, int min, int max) {
    int read;
    int countOfChar;
    do {
        printf("Please enter a %s between %d and %d:", text, min, max);
        scanf("%d", &read);
        countOfChar = 0;
        while (getchar() != '\n') {
            countOfChar++;
        }
        if (countOfChar != 0) {
            printf("You have not typed a whole number.\n");
        } else if (read < min || read > max) {
            printf("The number is not within interval %d-%d.\n", min, max);
        }
    } while (read < min || read > max || countOfChar != 0);
    return read;
}

int leapYear(int year) {
    return year % 4 == 0 && (year % 400 == 0 || year % 100 != 0);
}

int countOfDays(int m, int y){
if (m ==1 || m == 3 || m == 5 || m == 7 || m==8 || m == 10 || m == 12) {
    return 31;
} else if (m ==4 || m == 6 || m == 9 || m == 11) {
    return 30;
} else if (m==2 && leapYear(y)) {
    return 29;
} else if (m==2) {
    return 28;
} else{
    return ERROR;
}
}
int next() {
    int x;
    int countOfChar = 0;
    do {
        printf("Enter 1 to continue, to exit enter 0: ");
        scanf("%d", &x);
        while (getchar() != '\n') {
            countOfChar++;
        }
        if (countOfChar != 0) {
            printf("You haven\'t entered a number");
        } else if (x == 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        } else {
            printf("You haven\'t typed 1 or 0");
        }
    } while (countOfChar != 0 || (x != 0 && x != 1));
}

int daysFromStart(int d, int m, int y){
int days=0;
// Count of days in the year before actual date
    for (int y = MIN_YEAR ; y<y ; y++){
        days+=leapYear(y)?366:365;
        }
    for (int m=1; m<m; m++){
        days+= countOfDays(m, y);
    }
    return (days+=d-1);
}

int difference(int d1, int m1, int y1, int d2, int m2, int y2){
    return abs(daysFromStart(d1, m1, y1) - daysFromStart(d2, m2, y2));
}


int main() {
    do{
    int year, month, day, year2, month2, day2;
    year = input("year", MIN_YEAR, MAX_YEAR);
    month = input("month", 1, 12);
    day = input("day", 1, countOfDays(month, year));
    printf("%d/%d/%d\n", day, month, year);
    printf("The count of days from 1/1/%d is %d\n", MIN_YEAR, daysFromStart(day, month, year));
        year2 = input("year", MIN_YEAR, MAX_YEAR);
        month2 = input("month", 1, 12);
        day2 = input("day", 1, countOfDays(month, year));
        printf("The difference between %s.%s.%s and %d/%d/%d is %d days.\n",
       day, month, year, day2, month2, year2, difference(day, month, year, day2, month2, year2));
}while(next());
    return 0;
}