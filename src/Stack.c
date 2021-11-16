/**
 * @file Stack.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of stack
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Stack.h"

/**
 * @brief Empty stack.
 * 
 * @return Stack* 
 */
Stack* STACK_new_stack (void) 
{
    return NULL;
}

/**
 * @brief Return true or false if stack is empty.
 * 
 * @param[in] stack 
 * @return Bool 
 */
Bool STACK_is_empty (Stack *stack) 
{
    if (stack == NULL)
        return true;
    return false;
}

/**
 * @brief Add new element in stack.
 * 
 * @param[in] stack 
 * @param[in] value 
 * @return Stack* 
 */
Stack* STACK_new_element (Stack *stack, UType value, type type_of_value) 
{
    Stack *element = malloc(sizeof(Stack));
    element->value = value;
    element->next = stack;
    element->type_of_value = type_of_value;

    return element;
}

/**
 * @brief Delete element in top.
 * 
 * @param[in] stack 
 * @return Stack* 
 */
Stack* STACK_del_element (Stack *stack) {
    if (STACK_is_empty (stack))
        return stack;
    
    Stack *element = stack->next;
    free(stack);
    return element;
}

/**
 * @brief Return the top value of the stack.
 * 
 * @param[in] stack 
 * @return UType 
 */
UType STACK_top_value (Stack *stack) {
    return stack->value;
}

/**
 * @brief Display element of stack.
 * 
 * @param[in] stack 
 */
void STACK_show (Stack *stack) {
    if (STACK_is_empty (stack))
        printf ("[Stack is empty]\n");

    Stack *temp = stack;
    while (!STACK_is_empty (temp)) {
        switch (temp->type_of_value)
        {
        case type_int:
            printf ("[%d]\n", temp->value);
            break;
        
        case type_char:
            printf ("[%c]\n", temp->value);
            break;
        
        case type_double:
            printf ("[%lf]\n", temp->value);
            break;

        case type_float:
            printf ("[%.3f]\n", temp->value);
            break;
        
        default:
            printf ("[Element incorrect]\n");
            break;
        }

        temp = temp->next;

    }
    putchar ('\n');
    return;
}

/**
 * @brief Return size of stack.
 * 
 * @param[in] stack 
 * @return int 
 */
int STACK_height (Stack *stack) {
    Stack *temp = stack;
    int height = 0;

    while (!STACK_is_empty (temp)) {
        height++;
        temp = temp->next;
    }

    return height;
}

/**
 * @brief Clean all the elements of stack.
 * 
 * @param[in] stack 
 * @return Stack* 
 */
Stack* STACK_clean_stack (Stack *stack) {
    if (STACK_is_empty (stack)) {
        printf ("The stack is empty\n");
        putchar('\n');
        return stack;
    }

    while (!STACK_is_empty (stack)) {
        stack = STACK_del_element (stack);
    }

    if (STACK_is_empty (stack))
        printf ("Clean succes !\n");
    else
        printf ("Clean error !\n");
    
    putchar('\n');
    return stack;
}



