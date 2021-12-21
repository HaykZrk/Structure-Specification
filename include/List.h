/**
 * @file List.h
 * @author ZARIKIAN Hayk (haykzrk@gmail.com)
 * @brief Specification of list.
 * @version 0.1
 * @date 2021-11-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Structuration_data.h"

/**
 * @brief 
 * 
 */
typedef struct ListElement
{
    UType value;
    type type_of_value;
    struct ListElement *previous;
    struct ListElement *next;
}ListElement;

/**
 * @brief Empty file.
 * 
 * @return List* 
 */
ListElement* LIST_new_list (void);

/**
 * @brief Return true or false if list is empty.
 * 
 * @param[in] list 
 * @return Bool 
 */
Bool LIST_is_empty (ListElement *list);

/**
 * @brief 
 * 
 * @param list 
 * @return ListElement* 
 */
ListElement* LIST_circular (ListElement *list);

/**
 * @brief 
 * 
 * @param list 
 * @return ListElement* 
 */
ListElement* LIST_no_circular (ListElement *list);

/**
 * @brief 
 * 
 * @param list 
 * @return Bool 
 */
Bool LIST_is_circular (ListElement *list);

/**
 * @brief Return size of list.
 * 
 * @param[in] list 
 * @return int 
 */
int LIST_height (ListElement *list);

/**
 * @brief Return the top value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_head_value (ListElement *list);

/**
 * @brief Return the queue value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_queue_value (ListElement *list);

/**
 * @brief Add new element in front of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
ListElement* LIST_push_front (ListElement *list, UType value, type type_of_value);

/**
 * @brief Delete element in front of list.
 * 
 * @param[in] list 
 * @return List* 
 */
ListElement* LIST_pop_front (ListElement *list);

/**
 * @brief Add new element in back of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
ListElement* LIST_push_back (ListElement *list, UType value, type type_of_value);

/**
 * @brief Delete element in back of list.
 * 
 * @param[in] list 
 * @return List* 
 */
ListElement* LIST_pop_back (ListElement *list);

/**
 * @brief Display element of list.
 * 
 * @param[in] list 
 */
void LIST_show (ListElement *list);
