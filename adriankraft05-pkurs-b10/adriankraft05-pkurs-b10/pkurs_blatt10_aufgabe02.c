// Bibiotheken I/O, string und stdlib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* prepare_repeated_message(char* message, int repeat){
    char* string_array = (char *)calloc((((strlen(message)+1)*repeat)+1), sizeof(char));
    for(int i = 1;i<repeat;i++){
        strcat(string_array, message);
        strcat(string_array, "\n");
        
    }
    strcat(string_array, message);
    if(repeat > 1){
        strcat(string_array, "\n");
    }
    return string_array;
}

// Einsprungspunkt 'main' in das Programm definieren
int main() {
    // Text hier ohne Umbruch ausgeben, 
    // da die Umbrüche in der Funktion generiert werden sollen
    char* o = prepare_repeated_message("Hallo Osiris!", 3);
    printf("%s", o);
    free(o);
    // Rückgabe von 0 zur Signalisierung, dass kein Fehler aufgetreten ist
    return 0;
}