/**
 * @file List.c
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of list.
 * @version 0.1
 * @date 2021-11-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/List.h"

/**
 * @brief Empty list.
 * 
 * @return List* 
 */
ListElement* LIST_new_list (void)
{
    return NULL;
}

/**
 * @brief Return true or false if list is empty.
 * 
 * @param[in] list 
 * @return Bool 
 */
Bool LIST_is_empty (ListElement *list)
{
    return list == NULL;
}

/**
 * @brief Return size of list.
 * 
 * @param[in] list 
 * @return int 
 */
int LIST_height (ListElement *list)
{
    ListElement *head = list;
    int height = 0;

    while (head != NULL)
    {
        height++;
        head = head->next;
    }

    return height;
}

/**
 * @brief Return the top value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_head_value (ListElement *list)
{
    return list->value;
}

/**
 * @brief Return the queue value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_queue_value (ListElement *list)
{
    ListElement *head = list;

    while (head != NULL)
    {
        head = head->next;
    }

    return head->value;
}

/**
 * @brief Add new element in front of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
ListElement* LIST_push_front (ListElement *list, UType value, type type_of_value)
{
    ListElement *element = malloc(sizeof(ListElement));
    element->value = value;
    element->type_of_value = type_of_value;
    element->next = list;
    return element;
}

/**
 * @brief Delete element in front of list.
 * 
 * @param[in] list 
 * @return List* 
 */
ListElement* LIST_pop_front (ListElement *list)
{
    if (LIST_is_empty (list))
        return list;

    ListElement *new_head = list->next;
    free (list);
    return new_head;
}

/**
 * @brief Add new element in back of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
ListElement* LIST_push_back (ListElement *list, UType value, type type_of_value)
{
    ListElement *element = malloc(sizeof(ListElement));
    element->value = value;
    element->next = NULL;
    element->type_of_value = type_of_value;

    if (LIST_is_empty (list))
        return element;

    ListElement *queue = list;

    while (queue->next != NULL)
        queue = queue->next;

    queue->next = element;
    return list;
}

/**
 * @brief Delete element in back of list.
 * 
 * @param[in] list 
 * @return List* 
 */
ListElement* LIST_pop_back (ListElement *list)
{
    if (LIST_is_empty (list))
        return list;

    if (list->next == NULL)
    {
        free (list);
        list = NULL;
    }

    ListElement *queue = list;
    ListElement *previous_queue = list;

    while (queue->next != NULL)
    {
        previous_queue = queue;
        queue = queue->next;
    }

    previous_queue->next = NULL;
    free (queue);
    queue = NULL;

    return list;
}

/**
 * @brief Display element of list.
 * 
 * @param[in] list 
 */
void LIST_show (ListElement *list)
{
    printf ("\n[PRINTING OF LIST] :\n");
    if (LIST_is_empty (list))
        printf ("[List is empty]\n");

    ListElement *head = list;
    while (!LIST_is_empty (head))
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