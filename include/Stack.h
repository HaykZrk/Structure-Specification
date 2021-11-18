/**
 * @file Stack.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of stack
 * @version 0.1
 * @date 2021-11-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __STACK_H
#define __STACK_H

#include "Structuration_data.h"

/**
 * @brief Structure of stack who takes one pointer of value of type "Type" and one pointer of next element.
 * 
 */
typedef struct Stack
{
    type type_of_value;
    union UType value;
    struct Stack *next;
}Stack;

/**
 * @brief Couple of stack.
 * 
 */
typedef struct CStack 
{
    struct Stack *stack1;
    struct Stack *stack2;
}CStack;

/**
 * @brief Create empty stack.
 * 
 * @return Stack* 
 */
Stack* STACK_new_stack (void);

/**
 * @brief Return true or false if stack is empty.
 * 
 * @param[in] stack 
 * @return Bool 
 */
Bool STACK_is_empty (Stack *stack);

/**
 * @brief Add new element in stack.
 * 
 * @param[in] stack 
 * @param[in] value 
 * @param[in] type_of_value
 * @return Stack* 
 */
Stack* STACK_new_element (Stack *stack, UType value, type type_of_value);

/**
 * @brief Delete element in top.
 * 
 * @param[in] stack 
 * @return Stack* 
 */
Stack* STACK_del_element (Stack *stack);

/**
 * @brief Return the top value of the stack.
 * 
 * @param[in] stack 
 * @return UType 
 */
UType STACK_top_value (Stack *stack);

/**
 * @brief Display element of stack.
 * 
 * @param stack 
 */
void STACK_show (Stack *stack);

/**
 * @brief Return size of stack.
 * 
 * @param[in] stack 
 * @return int 
 */
int STACK_height (Stack *stack);

/**
 * @brief Clean all the elements of stack.
 * 
 * @param[in] stack 
 * @return Stack* 
 */
Stack* STACK_clean_stack (Stack *stack);

/**
 * @brief Initialize the elements of stack with one value for desired number of elements.
 * 
 * @param[in] stack 
 * @param[in] value 
 * @param[in] type_of_value 
 * @param[in] num_element 
 * @return Stack* 
 */
Stack* STACK_new_stack_init (UType value, type type_of_value, int num_element);

/**
 * @brief Return true if the value is in the stack else if false.
 * 
 * @param[in] stack 
 * @param[in] value 
 * @return Bool 
 */
Bool STACK_number_in_stack (Stack *stack, UType value);

#endif
