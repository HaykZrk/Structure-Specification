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

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Type of value for add new element.
 * 
 */
typedef enum type {
    type_char,
    type_int,
    type_float,
    type_double
}type;

/**
 * @brief Implementation of type boolean.
 * 
 */
typedef enum Bool
{
    false,
    true
}Bool;

/**
 * @brief Choose one of the four types.
 * 
 */
typedef union UType
{
    char STACK_TYPE_char;
    int STACK_TYPE_int;
    float STACK_TYPE_float;
    double STACK_TYPE_double;
}UType;

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
 * @brief Empty stack.
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

#endif
