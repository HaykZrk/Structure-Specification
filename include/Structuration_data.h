/**
 * @file Structuration_data.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of data common.
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
    char TYPE_char;
    int TYPE_int;
    float TYPE_float;
    double TYPE_double;
}UType;

#endif
