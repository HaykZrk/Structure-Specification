/**
 * @file Structuration_data.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __STRUCTURATION_DATA_H
#define __STRUCTURATION_DATA_H

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

#endif
