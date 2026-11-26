#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE -1

struct Element
{
    char data;
    struct Element *next;
};

typedef struct Array
{
    struct Element *head;
    struct Element *tail;
    int count;
} Queue;

struct Array init_array()
{
    Queue my_array = {
        .head = NULL,
        .tail = NULL,
        .count = 0,
    };
    return my_array;
}

int enqueue(Queue *array, char ch)
{
    if (array->count >= MAX_SIZE && MAX_SIZE != -1)
    {
        printf("Buffer overcharge\n");
        return 0;
    }
    struct Element *new_element = (struct Element *)malloc(sizeof(struct Element));
    new_element->data = ch;
    new_element->next = NULL;
    if (array->head != NULL)
    {
        array->tail->next = new_element;
    }
    else
    {
        array->head = new_element;
    }
    array->tail = new_element;
    array->count++;
    return 1;
}

int clear_memory(Queue *array)
{
    struct Element *element = array->head;
    while (element != NULL)
    {
        struct Element *next = element->next;
        free(element);
        element = next;
    }
    return 1;
}

char dequeue(Queue *array)
{
    char removed = 0;
    struct Element *element = array->head;
    if (element != NULL)
    {
        struct Element *new_head = element->next;
        removed = element->data;
        free(element);
        array->head = new_head;
        array->count--;
    }
    if (array->head == NULL)
    {
        array->tail = NULL;
    }
    return removed;
}

int print(Queue *array)
{
    if(array->count == 0){
        printf("The array is empty\n");
        return 0;
    }
    struct Element *element = array->head;
    while (element != NULL)
    {
        char ch = element->data;
        printf("%c", ch);
        element = element->next;
    }
    return 1;
}

char peek_front(Queue *array)
{
    if (array->head != NULL)
    {
        return array->head->data;
    }
    else
    {
        return '\0';
    }
}

int is_empty(Queue *array)
{
    if (array->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(Queue *array)
{
    if (array->count == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    Queue array = init_array();
    printf("Enter char. To print write '1', to dequeue write '2', to exit write '0'\n");
    char ch = 0;

    do
    {
        printf("\nInput: ");
        scanf(" %c", &ch);

        switch (ch)
        {
        case '1':
            print(&array);
            printf("\n");
            break;

        case '2':
            if (is_empty(&array))
            {
                printf("Queue is empty!\n");
            }
            else
            {
                char removed = dequeue(&array);
                printf("Removed element: '%c'\n", removed);
            }
            break;

        case '0':
            printf("Exiting program..\n");
            break;

        default:
            if (is_full(&array))
            {
                printf("Cannot add '%c'. Queue is overcharge!!\n", ch);
            }
            else
            {
                enqueue(&array, ch);
                printf("Add '%c' to queue\n", ch);
            }
            break;
        }
    } while (ch != '0');

    clear_memory(&array);
    return 0;
}