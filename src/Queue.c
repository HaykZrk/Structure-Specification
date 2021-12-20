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
    QueueElement *head = file->head;
    int height = 0;

    while (head != NULL) {
        height++;
        head = head->next;
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
    QueueElement *del_element = file->head;

    if (file->head == file->queue) 
    {
        file->head = NULL;
        file->queue = NULL;
    }
    else 
    {
        file->head = file->head->next;
    }

    free (del_element);
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
    printf ("\n[PRINTING OF FILE] :\n");
    if (FILE_is_empty (file))
        printf ("[File is empty]\n");

    QueueElement *head = file->head;
    while (head != NULL)
    {
        switch (head->type_of_value)
        {
            case type_int:
                printf ("[%d] ", head->value);
                break;
            
            case type_char:
                printf ("[%c] ", head->value);
                break;

            case type_double:
                printf ("[%lf] ", head->value);
                break;

            case type_float:
                printf ("[%.3f] ", head->value);
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
 * @brief Clean all the elements of file.
 * 
 * @param[in] file 
 * @return File* 
 */
File* FILE_clean (File *file) 
{
    printf ("\n[CLEANING OF FILE] :\n");

    if (FILE_is_empty (file)) 
    {
        printf ("\nThe file is empty !\n");
        return file;
    }

    while (!FILE_is_empty (file))
        file = FILE_del_element (file);


    if (FILE_is_empty (file))
        printf ("Clean memory succes !\n");
    else
        printf ("Clean memory error !\n");

    putchar ('\n');
    return file;
}