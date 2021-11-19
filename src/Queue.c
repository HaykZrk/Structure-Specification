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
File* FILE_new_file (void) 
{
    File *file = malloc(sizeof(File));
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
Bool FILE_is_empty (File *file) 
{
    if (file->head == NULL)
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
File* FILE_new_element (File *file, UType value, type type_of_value) 
{
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

/**
 * @brief Return size of file.
 * 
 * @param[in] file 
 * @return int 
 */
int FILE_height (File *file) 
{
    File *temp = file;
    int height = 0;

    while (!FILE_is_empty (temp)) {
        height++;
        temp->head = temp->head->next;
    }

    return height;

}

/**
 * @brief Delete element in head.
 * 
 * @param[in] file 
 * @return File* 
 */
File* FILE_del_element (File *file) 
{
    QueueElement *temp = file->head;

    if (file->head == file->queue) 
    {
        file->head = NULL;
        file->queue = NULL;
    }
    else 
    {
        file->head = file->head->next;
    }

    free(temp);
    return file;
}

/**
 * @brief Return the head alue of the file.
 * 
 * @param[in] file 
 * @return UType 
 */
UType FILE_head_value (File *file) 
{
    return file->head->value;
}

/**
 * @brief Return the queue value of the file.
 * 
 * @param[in] file 
 * @return UType 
 */
UType FILE_queue_value (File *file)
{
    return file->queue->value;
}

/**
 * @brief Display element of file.
 * 
 * @param[in] file 
 */
void FILE_show (File *file)
{
    File *temp = file;

    while (!FILE_is_empty (temp))
    {
        printf ("[%d] ", temp->head->value.STACK_TYPE_int);
        temp = FILE_del_element (temp);
    }

    putchar ('\n');
    return;
}

