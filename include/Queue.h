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

/**
 * @brief Return size of file.
 * 
 * @param[in] file 
 * @return int 
 */
int FILE_height (File *file);

/**
 * @brief Delete element in head.
 * 
 * @param[in] file 
 * @return File* 
 */
File* FILE_del_element (File *file);

/**
 * @brief Return the head value of the file.
 * 
 * @param[in] file 
 * @return UType 
 */
UType FILE_head_value (File *file);

/**
 * @brief Return the queue value of the file.
 * 
 * @param[in] file 
 * @return UType 
 */
UType FILE_queue_value (File *file);

/**
 * @brief Display element of file.
 * 
 * @param[in] file 
 */
void FILE_show (File *file);



#endif