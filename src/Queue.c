/**
 * @file Queue.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of queue.
 * @version 0.1
 * @date 2021-11-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Queue.h"

/**
 * @brief Structure of file who takes two pointer of QueueElement.
 * 
 * @return File* 
 */
File* FILE_new_file (void) {
    File *file = malloc(sizeof(FILE));
    file->head = NULL;
    file->queue = NULL;
    return file;
}

/**
 * @brief Create empty file.
 * 
 * @param[in] file 
 * @return File* 
 */
Bool FILE_is_empty (File *file) {
    if (file->head == NULL && file ->queue == NULL)
        return true;
    return false;
}

/**
 * @brief Add new element in file.
 * 
 * @param[in] file 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return File* 
 */
File* FILE_new_element (File *file, UType value, type type_of_value) {
    QueueElement *element = malloc(sizeof(QueueElement));
    element->value = value;
    element->type_of_value = type_of_value;
    element->next = NULL;

    if (FILE_is_empty (file)) {
        file->head = element;
        file->queue = element;
    }
    else {
        file->queue->next = element;
        file->queue = element;
    }

    return file;
}