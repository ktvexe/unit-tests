/* FIXME : introduce elegant ways to reuse */
#include "swap.c"

void bubble_sort(List **head)
{
    if (head == NULL || (*head == NULL))
        return;

    int num_list = 0;
    int i = 0;
    int sub_i;
    int sub_for_Max;
    List **pre_sub_head = head;
    List *sub_head;

    sub_head = *head;
//version1
    for (; sub_head && sub_head ->next;) {
        num_list++ ;
        sub_head = sub_head->next;
    }

    for (; i < num_list; i++) {
        sub_head = *head;
        sub_for_Max = num_list - (i + 1);
        pre_sub_head = head;
        for (sub_i = 0; sub_i < sub_for_Max;sub_i++) {
            if (sub_head->value < sub_head->next->value) {
                sub_head = swap(sub_head,sub_head,sub_head->next);
                *pre_sub_head = sub_head;
            }

            pre_sub_head = &((*pre_sub_head)->next);
            sub_head = sub_head->next;
        }
    }

    return;
}
