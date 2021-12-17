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
    if (list == NULL)
        return true;
    return false;
}

/**
 * @brief Return size of list.
 * 
 * @param[in] list 
 * @return int 
 */
int LIST_height (ListElement *list)
{
    ListElement *temp = list;
    int height = 0;

    while (!LIST_is_empty (temp))
    {
        height++;
        temp = temp->next;
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
    ListElement *temp = list;

    while (!LIST_is_empty (temp))
    {
        temp = temp->next;
    }

    return temp->value;
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
    ListElement *temp = list;
    if (LIST_is_empty (list))
        return list;

    temp = temp->next;
    free(list);
    return temp;
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
    ListElement *element = malloc(sizeof(List));
    element->value = value;
    element->next = NULL;
    element->type_of_value = type_of_value;

    if (LIST_is_empty (list))
        return element;

    ListElement *temp = list;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = element;
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
        free(list);
        list = NULL;
    }

    ListElement *temp = list;
    ListElement *before = list;

    while (temp->next != NULL)
    {
        before = temp;
        temp = temp->next;
    }

    before->next = NULL;
    free(temp);
    temp = NULL;

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

    ListElement *temp = list;
    while (!LIST_is_empty (temp))
    {
        switch (temp->type_of_value)
        {
        case type_int:
            printf ("[%d] ", temp->value);
            break;
        
        case type_char:
            printf ("[%c] ", temp->value);
            break;

        case type_double:
            printf ("[%lf] ", temp->value);
            break;

        case type_float:
            printf ("[%.3f] ", temp->value);
            break;
        
        default:
            printf ("[Element incorrect]\n");
            break;
        }
        temp = temp->next;
    }
    putchar ('\n');
    return;
}