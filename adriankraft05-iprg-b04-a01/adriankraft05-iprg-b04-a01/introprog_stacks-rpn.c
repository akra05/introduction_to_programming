#include <stdlib.h>
#include <string.h>
#include <math.h>  // definiert den speziellen Wert NaN für floats
#include "introprog_stacks-rpn.h"
#include "introprog_input_stacks-rpn.h"

/* 
 * Füge Element am Anfang des Stacks ein
 *
 * char* - Ein Pointer auf den Stack.
 * float - Zahl, die als neues Element auf den Stack gelegt
 *         werden soll.
 */
void stack_push(stack* my_stack, float number)
{
    stack_element* new_elem = (stack_element*)malloc(sizeof(stack_element));
    new_elem->value = number;
    
    new_elem->next = my_stack->top;
    my_stack->top = new_elem;
}

/* 
 * Nehme das letzte eingefügte Element vom Anfang des Stacks
 * Gebe NaN zurück, wenn keine Element vorhanden ist.
 *
 * stack* - Ein Pointer auf den Stack
 *
 * Gebe die im Element enthaltenen Zahl zurück
 */
float stack_pop(stack* my_stack)
{
    if(my_stack->top == NULL){
        return NAN;
    }

    float number = my_stack->top->value;
    my_stack->top = my_stack->top->next;

    return number;
}

/*
 * Führt abhängig von dem Token eine entsprechende Operation auf
 * dem Stack aus.  Wenn es sich bei dem Token um
 *  -> eine Zahl handelt, dann konvertiere die Zahl mithilfe von
 *     atof() zu einem float und lege sie auf den Stack.
 *  -> einen Operator handelt, dann nehme zwei Zahlen vom Stack,
 *     führe die Operation aus und lege das Resultat auf den Stack.
 *  -> eine nichterkennbare Zeichenkette handelt, dann tue nichts.
 *
 * stack*  - Ein Pointer auf den Stack
 * char*  - Eine Zeichenkette
 */
void process(stack* my_stack, char* token)
{
    /* HIER implementieren */
    float number = atof(token);
    if (number != 0 || (*token == '0' && *(token + 1) == '\0')) {
        stack_push(my_stack, number);
    }
    else if (is_add(token) == 1 || is_sub(token) == 1 || is_mult(token) == 1)
    {
        float a = stack_pop(my_stack);
        float b = stack_pop(my_stack);
        float result = 0;
        if(strcmp(token,"+") == 0){
            result = a + b;
            stack_push(my_stack, result);
        }
        else if(strcmp(token,"-") == 0){
            result = b - a;
            stack_push(my_stack, result);
        }
        else if(strcmp(token,"*") == 0){
            result = a * b;
            stack_push(my_stack, result);
        }

    }
    
    /* Du kannst zur Erkennung der Token folgende Hilfsfunktionen
     * benutzen:
     *
     * Funktion          Rückgabewert von 1 bedeutet
     * ---------------------------------------------
     * is_add(token)     Token ist ein Pluszeichen
     * is_sub(token)     Token ist ein Minuszeichen
     * is_mult(token)    Token ist ein Multiplikationszeichen
     * is_number(token)  Token ist eine Zahl
     */
}

/* 
 * Erstelle einen Stack mit dynamischem Speicher.
 * Initialisiere die enthaltenen Variablen.
 *
 * Gebe einen Pointer auf den Stack zurück.
 */
stack* stack_erstellen() {
    stack* created_stack = (stack*)malloc(sizeof(stack));
    created_stack->top = NULL;
    return created_stack;

}