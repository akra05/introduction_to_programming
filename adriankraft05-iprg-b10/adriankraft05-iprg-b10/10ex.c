/*
Zur Abgabe einen branch `iprg-b10` erstellen und pushen, in dem als einzige Datei die `10ex.c` liegt.
*/

/*
Um die Tests für dieses Blatt zu kompilieren und zu starten, führen Sie den folgenden Befehl aus:
cc -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && ./10ex_test.o

Wir empfehlen, mit möglichst streng eingestelltem valgrind zu testen, denn so testen wir auch auf dem Server:
cc -std=c11 -g -Wall -Werror 10ex_test.c -o 10ex_test.o -lm && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./10ex_test.o
*/

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tree.h"
#include "array.h"

/*
Aufgabe 1:

Implementieren Sie min-heapify auf Bäumen: gegeben ein nichtleerer, linksvollständiger Baum `t`, dessen
Kinder der Wurzel die min-heap Eigenschaft erfüllen, lassen Sie den Wert in der Wurzel so lange
"hinuntersinken", bis `t` die min-heap Eigenschaft erfüllt.

Da "hinuntersinken" nicht gerade präzise formuliert ist, müssen Sie unter Umständen Ihre Implementierung
an die Testfälle anpassen. Aber wenn Sie der Intuition der Vorlesungsfolien folgen, sollte das keine Probleme bereiten.

Werte kommen in `t` niemals mehrfach vor.
*/
void heapify_tree(TreeNode *t) {
    TreeNode *right = t->right;
    TreeNode *left = t->left;
    int smallest;
    int is_right = 0;
    if(left != NULL && left->item < t->item){
        smallest = left->item;
    }
    else{
        smallest = t->item;
    }
    if(right != NULL && right->item < smallest){
        smallest = right->item;
        is_right = 1;
    }
    if(smallest != t->item){
        int tmp = t->item;
        t->item = smallest;
        if(is_right == 0){
            left->item = tmp;
            heapify_tree(left);
        }
        else{
            right->item = tmp;
            heapify_tree(right);
        }
    }
}

/*
Aufgabe 2:

Implementieren Sie min-heapify auf Arrays: gegeben ein nichtleeres Array und eine Position `i` innerhalb des Arrays,
sodass die Kinder vom Knoten der zum Element an Position `i` gehört min-heaps sind, lassen Sie den Wert an Position `i`
solange hinuntersinken, wie nötig, um die min-heap Eigenschaft für den Teilbaum ab Position `i` wiederherzustellen.

Oder knapper: Implementieren Sie den heapify Algorithmus aus der Vorlesung, aber für min-heaps.

Werte kommen im Array niemals mehrfach vor.
*/
void heapify_array(Array arr, size_t i) {
    int smallest;
    int is_right = 0;
    if(arr.len <= 1){
        return;
    }
    if(2*i+1 < arr.len && arr.arr[2*i+1]<arr.arr[i]){
        smallest = arr.arr[2*i+1];
    }
    else{
        smallest  = arr.arr[i];
    }
    if(2*i+2 < arr.len && arr.arr[2*i+2]<smallest){
        smallest = arr.arr[2*i+2];
        is_right = 1;
    }
    if(smallest != arr.arr[i]){
        int tmp = arr.arr[i];
        arr.arr[i] =  smallest;
        if(is_right == 0){
            arr.arr[2*i+1] = tmp;
            heapify_array(arr,2*i+1);
        }
        else{
            arr.arr[2*i+2]=tmp; 
            heapify_array(arr,2*i+2);
        }
        
    }
    
}
