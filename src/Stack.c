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
Stack* STACK_new_element (Stack *stack, Type value) 
{
    Stack *element = malloc(sizeof(Stack));
    element->value = value;
    element->next = stack;

    return element;
}






