/*
Willkommen zum achten Aufgabenblatt vom Programmierkurs. Auf diesem Aufabenblatt geht es um Pointer und Arrays.

Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall 08ex_test.c -o 08ex_test.o -lm && ./08ex_test.o
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "turtlecanvas.h"

/*
Aufgabe 1a:
Lesen Sie das Headerfile `turtlecanvas.h`. Diese Funktion soll die Turtle `d` Schritte vorwärts machen lassen.
*/
void turtle_advance_by(TurtleCanvas *c, uint32_t d) {
    for(int x = 0; x < d; x++){
        turtle_advance(c);
    }
    
    return;
}

/*
Aufgabe 1b:
Füllen Sie die Turtlecanvas mit horizontalen, abwechselnd schwarzen und weißen Linien (die unterste Zeile soll
schwarz gefärbt werden). Die Turtle ist anfangs an Position (0, 0), ist nach rechts orientiert, und zeichnet schwarz.
*/
void turtle_stripes(TurtleCanvas *c) {
    for(int y = 0; y < turtle_canvas_height(c);y+= 2){
        turtle_advance_by(c,turtle_canvas_width(c));
        turtle_rotate_left(c);
        turtle_advance(c);
        turtle_toggle_color(c);
        turtle_advance(c);
        turtle_toggle_color(c);
        turtle_rotate_right(c);
    }
    
    
    return;
}

/*
Aufgabe 1c:
Lesen Sie die Implementierungen der Turtlecanvas-Funktionen weiter unten in der "turtlecanvas.h".
Der Quellcode sollte vollständig verständlich und unüberraschend sein.
Hinweis: Diese Aufgabe wird nicht bewertet.
*/

/*
Aufgabe 2a:
Geben Sie einen Pointer auf das erste Vorkommen der größten Zahl im Eingabearray zurück.
*/
uint16_t *find_maximal_number(uint16_t numbers[], size_t numbers_len) {
    int max = 0;
    uint16_t *p;
    for(int i = 0;i<numbers_len;i++){
        if(numbers[i] > max){
            max = numbers[i];
            p = &numbers[i];
        }
        
    }
    return p;
}

/*
Aufgabe 2b:
Geben Sie (einen Pointer auf) das Teilarray zurück, welches ab dem ersten Vorkommen der größten Zahl im Eingabearray beginnt.
*/
uint16_t *find_subarray_starting_at_maximal_number(uint16_t numbers[], size_t numbers_len) {
    int max = 0;
    uint16_t *p;
    
    for(int i = 0;i<numbers_len;i++){
        if(numbers[i] > max){
            max = numbers[i];
            p = &numbers[i]+1/2;
            
        }
        
    }
    return p;
}

/*
Aufgabe 2c:
Geben Sie die größtmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die größte Distanz die zwischen 1 und 7, und beträgt damit `6`.
*/
uint16_t find_maximum_distance(uint16_t numbers[], size_t numbers_len) {
    int max = 0;
    for(int i = 0;i<numbers_len;i++){
        if(numbers[i] > max){
            max = numbers[i];

        }
        
    }
    int min = max;
    for(int i = 0;i<numbers_len;i++){
        if(numbers[i] < min){
            min = numbers[i];
        }
        
    }
    return max - min;
}

/*
Aufgabe 2d:
Geben Sie die kleinstmögliche Distanz zwischen zwei Zahlenwerten aus dem Array `numbers` zurück.
Beispiel: Im Array {1, 3, 7, 4} ist die kleinste Distanz die zwischen 3 und 4, und beträgt damit `1`.
*/


uint16_t find_minimum_distance(uint16_t numbers[], size_t numbers_len) {
    uint16_t minimum_distance = *find_maximal_number(numbers, numbers_len); 
    int distance;
    for(int i = 0; i < numbers_len; i++) {
        for(int j = i + 1; j < numbers_len; j++) {
            if(numbers[i] < numbers[j]) {

                distance = numbers[j] - numbers[i];
            } else {

                distance = numbers[i] - numbers[j];
            }
            if(distance < minimum_distance) {
                minimum_distance = distance;
            }
        }
    }
    
    return minimum_distance;
}


/*
Aufgabe 2e:
Schreiben Sie die ersten `numbers_len` Quadratzahlen aufsteigend in das gegebene Array `numbers`.
Hinweis: Wir starten bei `1`. Sollte numbers_len also `5` sein, sind die ersten 5 Quadratzahlen bis
einschließlich die von 5 gemeint: 1, 4, 9, 16, 25.
*/
void square_ascending(uint16_t numbers[], size_t numbers_len) {
    for(int i = 0;i<numbers_len;i++){
        numbers[i]=(i+1)*(i+1);
    }
    return;
}

/*
Aufgabe 2f:
Füllen Sie das Array `out` mit den aufsteigend sortierten Zahlen aus dem `in` Array. Beide Arrays haben die Länge `len`.
Beispiel: Ist `in` {1, 4, 3, 7, 4}, so soll `out` am Ende {1, 3, 4, 4, 7} sein.
*/
void sort_ascending(uint16_t in[], uint16_t out[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        int minimum = in[i];
        size_t min_index = i;

        for (size_t j = i + 1; j < len; j++) {
            if (in[j] < minimum) {
                minimum = in[j];
                min_index = j;
            }
        }

        // Swap the found minimum value with the current position in the sorted array
        int temp = in[i];
        in[i] = minimum;
        in[min_index] = temp;

        out[i] = minimum;
    }
    return;
}





