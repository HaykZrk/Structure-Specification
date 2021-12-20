/**
 * @file Stack.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of stack.
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
    return stack == NULL;
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
Stack* STACK_del_element (Stack *stack) 
{
    if (STACK_is_empty (stack))
        return stack;
    
    Stack *new_head = stack->next;
    free (stack);
    return new_head;
}

/**
 * @brief Return the top value of the stack.
 * 
 * @param[in] stack 
 * @return UType 
 */
UType STACK_top_value (Stack *stack) 
{
    return stack->value;
}

/**
 * @brief Display element of stack.
 * 
 * @param[in] stack 
 */
void STACK_show (Stack *stack) 
{
    printf ("\n[PRINTING OF STACK]\n");
    if (STACK_is_empty (stack))
        printf ("[Stack is empty]\n");

    Stack *head = stack;
    while (head != NULL) 
    {
        switch (head->type_of_value)
        {
        case type_int:
            printf ("[%d]\n", head->value);
            break;
        
        case type_char:
            printf ("[%c]\n", head->value);
            break;
        
        case type_double:
            printf ("[%lf]\n", head->value);
            break;

        case type_float:
            printf ("[%.3f]\n", head->value);
            break;
        
        default:
            printf ("[Element incorrect]\n");
            break;
        }

        head = head->next;

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
int STACK_height (Stack *stack) 
{
    Stack *head = stack;
    int height = 0;

    while (head != NULL) 
    {
        height++;
        head = head->next;
    }

    return height;
}

/**
 * @brief Clean all the elements of stack.
 * 
 * @param[in] stack 
 * @return Stack* 
 */
Stack* STACK_clean_stack (Stack *stack) 
{
    printf ("\n[CLEANING OF FILE] :\n");

    if (STACK_is_empty (stack)) 
    {
        printf ("\nThe stack is empty !\n");
        return stack;
    }

    while (!STACK_is_empty (stack)) 
        stack = STACK_del_element (stack);
    

    if (STACK_is_empty (stack))
        printf ("Clean memory succes  !\n");
    else
        printf ("Clean memory error !\n");
    
    putchar('\n');
    return stack;
}

/**
 * @brief Initialize the elements of stack with one value for desired number of elements.
 * 
 * @param[in] value 
 * @param[in] type_of_value 
 * @param[in] num_element 
 * @return Stack* 
 */
Stack* STACK_new_stack_init (UType value, type type_of_value, int num_element) 
{
    Stack *stack = STACK_new_stack ();
    for (int i = 0; i < num_element; i++) 
    {
        stack = STACK_new_element (stack, value, type_of_value);
    }
    return stack;
}

/**
 * @brief Return true if the value is in the stack else if false.
 * 
 * @param[in] stack 
 * @param[in] value 
 * @return Bool 
 */
Bool STACK_number_in_stack (Stack *stack, UType value) 
{
    Stack *head = stack;
    for (int i = 0; i < STACK_height (head); i++) 
    {
        if (STACK_top_value (head).TYPE_int == value.TYPE_int)
            return true;
        head = head->next;
    }
    return false;
}