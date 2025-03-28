#include <stdio.h>

// Funkcija za spajanje (merge) dve sortirane podliste
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Privremeni nizovi
    int L[n1], R[n2];

    // Kopiranje podataka u privremene nizove L[] i R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Spajanje nazad u originalni niz arr[]
    i = 0;  // Početni indeks prvog podniza
    j = 0;  // Početni indeks drugog podniza
    k = left;  // Početni indeks spojenog podniza

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiranje preostalih elemenata iz L[], ako ih ima
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiranje preostalih elemenata iz R[], ako ih ima
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Rekurzivna funkcija za Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sortiraj prvu i drugu polovinu
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Spoji sortirane polovine
        merge(arr, left, mid, right);
    }
}

// Funkcija za ispis niza
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Glavna funkcija
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Originalni niz: ");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("Sortirani niz: ");
    printArray(arr, arr_size);

    return 0;
}
