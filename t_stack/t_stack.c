#include <stdio.h>
#include <stdlib.h>
#include "t_stack.h"

int realloc_stack(t_stack *stack){
    stack->itens = (int*) realloc (stack->itens,(stack->memory+20)*sizeof(int));
    if(NULL==stack->itens){
        printf("\nError , out of memory.");
        exit(0);
    }
    stack->memory+=20;
    return 1;
}

t_stack* create_stack(){
    t_stack *stack = (t_stack*) malloc(sizeof(t_stack));
    if(NULL==stack){
        printf("\nError in creating stack.");
        exit(0);
    }
    stack->itens = (int*)malloc(20*sizeof(int));
    stack->length=0;
    stack->memory=20;

    return stack;
}

int push_stack(t_stack *stack, value item){
    if(stack->memory==stack->length){
        realloc_stack(stack);
    }
    stack->itens[stack->length] = item;
    stack->length++;
    return 1;
}

int pop_stack(t_stack *stack, value *item){
    if(0==stack->length){
        return 0;
    }
    *item = stack->itens[stack->length-1];
    stack->length--;
    return 1;
}

int print_stack(t_stack *stack){
    printf("\n");
    for (int i = 0; i < stack->length; i++){
        printf("%d ", stack->itens[i]);
    }
    return 1;
}

int length_stack(t_stack *stack){
    return stack->length;
}

int is_empty_stack(t_stack *stack){
    if(0==stack->length){
        return 1;
    }
    return 0;
}

int is_full_stack(t_stack *stack){
    if(0!=stack->length){
        return 1;
    }
    return 0;
}

int clean_stack(t_stack *stack){
    stack->length=0;
    return 1;
}

int destroy_stack(t_stack *stack){
    free(stack->itens);
    free(stack);
    return 1;
}