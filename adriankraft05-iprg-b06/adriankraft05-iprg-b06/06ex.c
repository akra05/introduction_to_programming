/*
Zur Abgabe einen branch `iprg-b06` erstellen und pushen, in dem als einzige Datei die `06ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 06ex_test.c -o 06ex_test.o -lm && ./06ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 06ex_test.c -o 06ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./06ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Machen Sie sich in dieser Aufgabe mit dem `Visualizer` (siehe array_visualizer.h) vertraut.
Nutzen Sie die `visualizer_append_array` Funktion damit die Tests durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void warmup(Visualizer *v, uint8_t *arr, size_t len) {
    
    for(int i = 0; i<len;i++){
        visualizer_append_array(v,arr);
        uint8_t tmp_front = arr[0];
        for(int j = 0;j<len;j++){
            arr[j] = arr[j+1];
            if(j == len -1){
                arr[j] = tmp_front;
            }
        }
    }
    
}


/*
Aufgabe 2:
Bringen Sie die Tests zum durchlaufen.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Es handelt sich um eine Abwandlung von iterativem Mergesort.
Tipp 3: `len` ist immer eine Dreierpotenz, damit Sie sich nicht mit Rundungsdetails herumschlagen brauchen.
*/
void merge(uint8_t *arr, int left, int middle, int right, int step) {
    int size1 = middle- left +1;
    int size2 = right - middle;

    uint8_t temp1[size1 ];
    uint8_t temp2[size2];
    for (int i =0; i<size1; i++){
        temp1[i] = arr[left + i];
    }
    for (int j = 0; j< size2; j++){
        temp2[j] = arr[middle + 1 + j];
    }
    int i=0;
    int j=0;
    int k=left;
    while (i < size1 && j < size2) {
        if (temp1[i] <= temp2[j]) {
            arr[k] = temp1[i++];
        } else {
            arr[k] = temp2[j++];
        }
        k++;
    }
    while (i < size1) {
        arr[k++] = temp1[i++];
    }
    while (j < size2) {
        arr[k++] = temp2[j++];
    }
}

void sort_it(Visualizer *v, uint8_t *arr, size_t len) {
    int step = 1;
    visualizer_append_array(v, arr);
    while (step < len) {
        int left = 0;
        while (left <= len - 2 * step) {
            int middle1 = left + step - 1;
            int middle2 = left + 2 * step - 1;
            int right = left + 3 * step - 1;

            merge(arr, left, middle1, middle2, step);
            merge(arr, left, middle2, right, step);

            left += 3 * step;

            visualizer_append_array(v, arr);
        }
        step *= 3;
    }
}






