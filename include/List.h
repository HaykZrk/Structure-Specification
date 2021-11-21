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
typedef struct List
{
    UType value;
    type type_of_value;
    struct List *next;
}List;

/**
 * @brief Empty file.
 * 
 * @return List* 
 */
List* LIST_new_list (void);

/**
 * @brief Return true or false if list is empty.
 * 
 * @param[in] list 
 * @return Bool 
 */
Bool LIST_is_empty (List *list);

/**
 * @brief Return size of list.
 * 
 * @param[in] list 
 * @return int 
 */
int LIST_height (List *list);

/**
 * @brief Return the top value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_head_value (List *list);

/**
 * @brief Return the queue value of the list.
 * 
 * @param[in] list 
 * @return UType 
 */
UType LIST_queue_value (List *list);

/**
 * @brief Add new element in front of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
List* LIST_push_front (List *list, UType value, type type_of_value);

/**
 * @brief Delete element in front of list.
 * 
 * @param[in] list 
 * @return List* 
 */
List* LIST_pop_front (List *list);

/**
 * @brief Add new element in back of list.
 * 
 * @param[in] list 
 * @param[in] value 
 * @param[in] type_of_value 
 * @return List* 
 */
List* LIST_push_back (List *list,UType value, type type_of_value);

/**
 * @brief Delete element in back of list.
 * 
 * @param[in] list 
 * @return List* 
 */
List* LIST_pop_back (List *list);

/**
 * @brief Display element of list.
 * 
 * @param[in] list 
 */
void LIST_show (List *list);
