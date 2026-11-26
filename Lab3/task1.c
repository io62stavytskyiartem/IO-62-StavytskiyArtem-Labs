// #include <stdio.h>
// #define MAX_SIZE 5

// typedef struct MyArray
// {
//     char data[MAX_SIZE];
//     int head;
//     int tail;
//     int count;
// } Queue;

// Queue init_array()
// {
//     Queue array = {
//         .head = 0,
//         .tail = 0,
//         .count = 0};
//     return array;
// }

// short enqueue(Queue *data, char new_value)
// {
//     if (data->count == MAX_SIZE)
//     {
//         printf("The array is overcharge\n");
//         return 0;
//     }
//     data->data[data->tail] = new_value;
//     data->tail = (data->tail + 1) % MAX_SIZE;
//     data->count++;
//     return 1;
// }
// char dequeue(Queue *data)
// {
//     if (data->count == 0)
//     {
//         printf("The array is empty\n");
//         return '\0';
//     }
//     char del_value = data->data[data->head];
//     data->head = (data->head + 1) % MAX_SIZE;
//     data->count--;
//     return del_value;
// }


// int is_empty(Queue *array){
//     if(array->count == 0){
//         return 1;
//     }else{
//         return 0;
//     }
// }

// int is_full(Queue *array){
//     if(array->count == MAX_SIZE){
//         return 1;
//     }else{
//         return 0;
//     }
// }

// char peek_front(Queue *array){
//     if(is_empty(array)){
//         printf("The buffer is empty");
//         return '\0';
//     }else{
//         return array->data[array->head];
//     }
// }

// int clear_memory(Queue *array){
//     // Заглушка, щоб виконавча функція main була однакова в двух варіантах.
//     return 1;
// }

// int print(Queue *data)
// {
//     if (data->count == 0)
//     {
//         printf("The array is empty\n");
//         return 0;
//     }
//     for (int i = 0; i < data->count; i++)
//     {
//         int char_ind = (data->head + i) % MAX_SIZE;
//         printf("%c", data->data[char_ind]);
//     }
//     return 1;
// }
// int main()
// {
//     Queue array = init_array();
//     printf("Enter char. To print write '1', to dequeue write '2', to exit write '0'\n");
//     char ch = 0;

//     do
//     {
//         printf("\nInput: ");
//         scanf(" %c", &ch);

//         switch (ch)
//         {
//         case '1':
//             print(&array);
//             printf("\n");
//             break;

//         case '2':
//             if (is_empty(&array))
//             {
//                 printf("Queue is empty!\n");
//             }
//             else
//             {
//                 char removed = dequeue(&array);
//                 printf("Removed element: '%c'\n", removed);
//             }
//             break;

//         case '0':
//             printf("Exiting program..\n");
//             break;

//         default:
//             if (is_full(&array))
//             {
//                 printf("Cannot add '%c'. Queue is overcharge!!\n", ch);
//             }
//             else
//             {
//                 enqueue(&array, ch);
//                 printf("Add '%c' to queue\n", ch);
//             }
//             break;
//         }
//     } while (ch != '0');

//     clear_memory(&array);
//     return 0;
// }