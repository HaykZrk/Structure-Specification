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
typedef union Type
{
    char STACK_TYPE_char;
    int STACK_TYPE_int;
    float STACK_TYPE_float;
    double STACK_TYPE_double;
}Type;

/**
 * @brief Structure of stack who takes one pointer of value of type "Type" and one pointer of next element.
 * 
 */
typedef struct Stack
{
    union Type value;
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
 * @return Stack* 
 */
Stack* STACK_new_element (Stack *stack, Type value);

#endif
