#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "introprog_buecherliste.h"
#include "introprog_structs_lists_input.h"

/* Fuege ein Element am Anfang der Liste an, sodass das neue
 * Element immer das erste Element der Liste ist.  Wenn die Liste
 * leer ist, soll das Element direkt an den Anfang platziert
 * werden.
 *
 * first    - Pointer auf das erste Element (bzw. Anfang) der
 * Liste
 * new_elem - Pointer auf das neues Element das in die Liste
 * eingefuegt werden soll
 *
 * Gib einen Pointer auf den neuen Anfang der Liste zurueck.
 */

element* insert_at_begin(element* start_pointer, element* new_element_pointer) {
    new_element_pointer->next = start_pointer;
    return new_element_pointer;
}




/* Kreiere ein neues Element mit dynamischem Speicher.
 *
 * title  - Titel des Buches
 * author - Autor des Buches
 * year   - Erscheinungsjahr des Buches
 * isbn   - ISBN des Buches
 *
 * Gib einen Pointer auf das neue Element zurueck.
 */
element *construct_element(char* title, char* author, uint32_t year, uint64_t isbn) {
    element* list_element = (element*)malloc(sizeof(element));
    if(list_element != NULL){
        strncpy(list_element->title, title, MAX_STR - 1);
        list_element->title[MAX_STR - 1] = '\0';

        strncpy(list_element->author, author, MAX_STR - 1);
        list_element->author[MAX_STR - 1] = '\0';
        list_element->year = year;
        list_element->isbn = isbn;
    }
    return list_element;
}

/* Gib den der Liste und all ihrer Elemente zugewiesenen
 * Speicher frei.
 */
void free_list(list* list) {
    while (list->first != NULL) {
        element* current = list->first;
        list->first = current->next;
        free(current);
    }
    free(list);
}




/* Lese die Datei ein und fuege neue Elemente in die Liste ein 
 * _Soll nicht angepasst werden_
 */
void read_list(char* filename, list* alist) {
    element* new_elem;

    char* new_title;
    char* new_author;
    uint32_t new_year;
    uint64_t new_isbn;
    read_line_context ctx;
    open_file(&ctx, filename);
    while(read_line(&ctx, &new_title, &new_author, &new_year, &new_isbn) == 0) {
        new_elem = construct_element(new_title, new_author, new_year, new_isbn);
        alist->first = insert_at_begin(alist->first, new_elem);
        alist->count++;
    }
}

/* Erstelle die Liste:
 *  - Weise ihr dynamischen Speicher zu 
 *  - Initialisiere die enthaltenen Variablen
 * _Soll nicht angepasst werden_
 */
list* construct_list() {
    list *alist = malloc(sizeof(list));
    alist->first = NULL;
    alist->count = 0;
    return alist;
}