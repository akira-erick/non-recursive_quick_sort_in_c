#ifndef T_STACK_H
#define T_STACK_H

#define value int


typedef struct{
    value *itens;
    int length;
    int memory;
}t_stack;


t_stack* create_stack();
int push_stack(t_stack *stack, value item);
int pop_stack(t_stack *stack, value *item);
int print_stack(t_stack *stack);
int length_stack(t_stack *stack);
int is_empty_stack(t_stack *stack);
int is_full_stack(t_stack *stack);
int clean_stack(t_stack *stack);
int destroy_stack(t_stack *stack);

#endif