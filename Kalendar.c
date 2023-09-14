#include <stdio.h>

// Funkcija za određivanje dana u nedelji za određeni datum
int dayOfWeek(int d, int m, int y) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

// Funkcija za ispis kalendara za dati mesec i godinu
void printCalendar(int year, int month) {
    char *months[] = {"", "Januar", "Februar", "Mart", "April", "Maj", "Jun", "Jul", "Avgust", "Septembar", "Oktobar", "Novembar", "Decembar"};
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[2] = 29;

    printf("     %s %d\n", months[month], year);
    printf("Pon Uto Sri Čet Pet Sub Ned\n");

    int firstDay = dayOfWeek(1, month, year);
    int day;

    // Prikazivanje praznih dana pre prvog dana meseca
    for (int i = 0; i < firstDay; i++)
        printf("    ");

    // Prikazivanje dana meseca
    for (day = 1; day <= daysInMonth[month]; day++) {
        printf("%3d ", day);
        if ((day + firstDay) % 7 == 0 || day == daysInMonth[month])
            printf("\n");
    }
}

int main() {
   
}
