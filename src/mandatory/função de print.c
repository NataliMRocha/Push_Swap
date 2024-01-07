#include <stdio.h>


static void    printstack(t_data *stack, char name)
{
    printf("\nPILHA %c\n", name);
    if (!stack)
        return ;
    t_data    *temp;
    temp = stack;
    printf("valores:\t");
    while (temp)
    {
        printf("|%4d| ", temp->value);
        temp = temp->next;
    }
    temp = stack;
    printf("\nindices:\t");
    while (temp)
    {
        printf("[%4d] ", temp->index);
        temp = temp->next;
    }
    temp = stack;
    printf("\nposicoes:\t");
    while (temp)
    {
        printf("<%4d> ", temp->current_pos);
        temp = temp->next;
    }
    temp = stack;
    printf("\ntaget pos:\t");
    while (temp)
    {
        printf("(%4d) ", temp->target_pos);
        temp = temp->next;
    }
    temp = stack;
    printf("\nCOST   A:\t");
    while (temp)
    {
        printf("|%4d| ", temp->cost_a);
        temp = temp->next;
    }
    temp = stack;
    printf("\nCOST   b:\t");
    while (temp)
    {
        printf("|%4d| ", temp->cost_b);
        temp = temp->next;
    }
}