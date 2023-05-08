#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Define constants*/
#define EOL "\n"

/* Log a string message */
#define LOG(message) printf("%s%s",message, EOL)

/* Variables */
const char INTRO[] = "This program implements a simple linked list";

typedef struct element
{
    /* data */
    int elem;
    struct element * next;
} element_t;

/*
    @brief Check if the list is empty 
    @param head the pointer to head of the list
    @return true if is empty, false otherwise
*/
bool is_empty(element_t * head){
    if (NULL == head){
        return true;
    }
    return false;
}

/*
    @brief Print the list element by element
    @param head the pointer to head of the list
*/
void print_list(element_t * head){
    element_t * next_element = head;

    while (NULL != next_element){
        printf("%d ", next_element->elem);
        next_element = next_element->next;
    }
    printf("\n");
}

/*
    @brief Add element to the end of the list
    @param head the pointer to head of the list
    @param new_element value of the new element
*/
void append(element_t * head, int new_element){
    element_t* current = head;

    while (NULL != current->next){
        current = current->next;
    }

    /* add element */ 
    current->next = (element_t *) malloc(sizeof(element_t));
    current->next->elem = new_element;
    current->next->next = NULL;
}

/*
    @brief Add element at the head of the list
    @param head the double pointer to head of the list
    @param new_element value of the new element
*/
void push(element_t ** head, int new_element){
    element_t * new_head;
    new_head = (element_t *) malloc(sizeof(element_t));

    new_head->next = *head;
    new_head->elem = new_element; 
    *head = new_head;
}

/*
    @brief Remove the first element of the list
    @param head the pointer to head of the list
    @param new_element value of the new element
    @return 1 if success, 0 if not
*/
int pop(element_t ** head){
    if (NULL == *head){
        return 0;
    }

    element_t * new_head = NULL;

    new_head = (*head)->next;
    free(*head);
    *head = new_head;
    return 1;
}

int main(void){
    LOG(INTRO);

    element_t * head = NULL;
    head = (element_t *) malloc(sizeof(element_t));

    if (NULL == head){
        return 1;
    }

    head->elem = 1;
    head->next = NULL;

    append(head, 2);
    append(head, 4);
    push(&head, 0);
    print_list(head);
    pop(&head);
    print_list(head);

}