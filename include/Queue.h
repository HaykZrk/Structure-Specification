/**
 * @file Queue.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of queue.
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __QUEUE_H
#define __QUEUE_H

#include "Structuration_data.h"

/**
 * @brief Structure of file who takes one pointer of value of type "Type" and one pointer of next element.
 * 
 */
typedef struct QueueElement
{
    type type_of_value;
    union UType value;
    struct QueueElement *next;
}QueueElement;

/**
 * @brief Structure of file who takes two pointer of QueueElement.
 * 
 */
typedef struct File
{
    struct QueueElement *head;
    struct QueueElement *queue;
}File;

/**
 * @brief Create empty file.
 * 
 * @return File* 
 */
File* FILE_new_file (void);

/**
 * @brief Return true or false if file is empty.
 * 
 * @param[in] file 
 * @return Bool 
 */
Bool FILE_is_empty (File *file);

/**
 * @brief Add new element in file.
 * 
 * @param[in] file 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return File* 
 */
File* FILE_new_element (File *file, UType value, type type_of_value);

#endif