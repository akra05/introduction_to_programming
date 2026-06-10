/*
Zur Abgabe einen branch `iprg-b11` erstellen und pushen, in dem als einzige Datei die `11ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && ./11ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 11ex_test.c -o 11ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./11ex_test.o
*/

#include "array_visualizer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
Aufgabe 1:
Implementieren Sie folgenden Algorithmus, um ein Array zu partitionieren:

- die `pivot_position` ist initial die letzte Stelle im Array
- der Wert an der `pivot_position` ist das `pivot` Element
- solange es links der `pivot_position` Elemente gibt, die größer oder gleich `pivot` sind:
    - sei `i` die Position des linkesten solchen Elements
    - rotiere die Werte an den Positionen `i`, `pivot_position - 1` und `pivot_position` nach links (siehe Testoutput)
    - dekrementiere die `pivot_position`

Nutzen Sie die `visualizer_append_array` Funktion (siehe `array_visualizer.h` bzw das sechste Semesteraufgabenblatt 06) um den Algorithmus zu visualisieren. Und nutzen Sie die vom Testrunner erstellten Bilder zum Debuggen, und falls Ihnen das zu erwartende Verhalten unklar ist.

Imaginäre Bonuspunkte, wenn Ihre Implementierung in linearzeit läuft.

Tipp: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
*/
void visualize_partition(Visualizer *v, uint8_t *arr, size_t len) {
    uint8_t pivot = arr[len - 1];
    int step = 1;
    uint8_t tmp;
    visualizer_append_array(v,arr);
    for (int i = 0; i < len - step; i++) {
        if (pivot <= arr[i]) {
            
            tmp = arr[i];
            arr[i] = arr[len - step - 1];
            arr[len - step - 1] = arr[len - step];
            arr[len - step] = tmp;
            step++;
            i--;
            visualizer_append_array(v,arr);
        }
    }
}
    




/*
Aufgabe 2:
Implementieren Sie Quicksort rekursiv, und visualisieren Sie den Algorithmus wie von den Tests verlangt.

Wählen Sie als Pivotelement stets das letzte Element eines Teilarrays, und partitionieren Sie mit dem in Aufgabe 1 beschriebenen Algorithmus.

Tipp 1: Die erste Zeile im erzeugten Bild stellt das Eingabearray dar.
Tipp 2: Visualisieren Sie außerdem das Array immer nachdem Sie ein Teilarray der Größe mindestens zwei partitioniert haben.
Tipp 3: Diese Funktion selbst lässt sich nicht sinnvoll rekursiv aufrufen. Schreiben Sie eine geeignete Funktion, und rufen Sie sie in `sort_quickly` auf.
*/
int partition(uint8_t *arr, int start,int end) {
    uint8_t pivot = arr[end];
    int step = 1;
    int len = end-start+1;
    int counter = 0;
    uint8_t tmp;
    for (int i = start; i < end+1 - step; i++) {
        if (pivot <= arr[i]) {
            
            tmp = arr[i];
            arr[i] = arr[start+len - step - 1];
            arr[start+len - step - 1] = arr[start+len - step];
            arr[start+len - step] = tmp;
            step++;
            counter++;
            i--;
        }
    }
    return end-counter;
}



void quick_sort(Visualizer *v,uint8_t *arr, int start, int end) {
    if (start < end) {
        visualizer_append_array(v,arr);

        int pivot_index = partition(arr, start, end);
        
        quick_sort(v,arr, start, pivot_index - 1);
        quick_sort(v,arr, pivot_index + 1, end);
    }
}

void sort_quickly(Visualizer *v,uint8_t *arr, size_t len) {
    quick_sort(v,arr, 0, len - 1);
    visualizer_append_array(v,arr);
}