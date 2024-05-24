#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "t_stack.h"

int swap(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

int sort_portion(int *numbers, int start, int end){
    int pivot = numbers[end];
    int i = start - 1;

    for(int j = start; j <= end-1; j++){
        if(numbers[j]<=pivot){
            i++;
            swap(&numbers[i], &numbers[j]);
        }
    }
    swap(&numbers[i+1], &numbers[end]);
    return i+1;
}

int quicksort(int *numbers, int size){
    t_stack *stack = create_stack();

    int start, end;

    push_stack(stack, 0);
    push_stack(stack, size-1);

    while(is_full_stack(stack)){
        pop_stack(stack, &end);
        pop_stack(stack, &start);

        int portion = sort_portion(numbers, start, end);

        if(portion-1>start){
            push_stack(stack, start);
            push_stack(stack, portion-1);
        }

        if(portion+1<end){
            push_stack(stack, portion+1);
            push_stack(stack, end);
        }
    }





}

int main(int argc, char const *argv[])
{
    int size;
    scanf("%d", &size);
    int *numbers = malloc(sizeof(int)*size);
    for(int i=0; i<size; i++){
        scanf("%d", &numbers[i]);
    }

    quicksort(numbers, size);

    for(int i=0; i<size; i++){
        printf("%d ", numbers[i]);
    }

    free(numbers);
    return 0;
}
