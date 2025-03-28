#include <stdio.h>
#include <math.h>

// Funkcija za izračunavanje hipotenuze
double izracunajHipotenuzu(double a, double b) {
    return sqrt(a * a + b * b);
}

// Funkcija za izračunavanje trigonometrijskih funkcija
void izracunajKuteve(double a, double b, double h) {
    double sinA = a / h;
    double sinB = b / h;

    double cosA = b / h;
    double cosB = a / h;

    double tanA = a / b;
    double tanB = b / a;

    double cotA = b / a;
    double cotB = a / b;

    // Ispis rezultata
    printf("\nHipotenuza: %.2lf\n", h);
    printf("Sinusi kuteva (A i B): %.2lf, %.2lf\n", sinA, sinB);
    printf("Kosinusi kuteva (A i B): %.2lf, %.2lf\n", cosA, cosB);
    printf("Tangensi kuteva (A i B): %.2lf, %.2lf\n", tanA, tanB);
    printf("Kotangensi kuteva (A i B): %.2lf, %.2lf\n", cotA, cotB);
}

int main() {
    double stranicaA, stranicaB;

    // Unos stranica
    printf("Unesite duljinu prve stranice: ");
    scanf("%lf", &stranicaA);
    printf("Unesite duljinu druge stranice: ");
    scanf("%lf", &stranicaB);

    // Izračunavanje
    double hipotenuza = izracunajHipotenuzu(stranicaA, stranicaB);
    izracunajKuteve(stranicaA, stranicaB, hipotenuza);

    return 0;
}
