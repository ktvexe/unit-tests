#include <stdio.h>
#include <stdlib.h>

typedef struct List_node {
    int value;
    struct List_node *next;
} List;

List *swap(List *head, List *node_1, List *node_2)
{
    if (!head ||
            (node_1 == NULL) || (node_2 == NULL) ||
            (node_1 == node_2))
        return head;

    int check_node_exist = 0;

    List *_head = head;
    List *pre_node_1,*pre_node_2,*tmp_node;
    pre_node_1=NULL;
    pre_node_2=NULL;
    tmp_node=NULL;

    
	 while (head && head->next) {
        if (head->next == node_1) {
            pre_node_1 = head;
            check_node_exist++ ;
        		if(_head == node_2){
        			pre_node_1->next = node_2;
        			tmp_node = node_2->next;
       			node_2->next = node_1->next;
        			node_1->next = tmp_node;
        			return node_1;
				}
		  }
		  else if (head->next == node_2) {
            pre_node_2 = head;
            check_node_exist++ ;
        		if(_head ==node_1){
        			pre_node_2->next = node_1;
        			tmp_node = node_1->next;
        			node_1->next = node_2->next;
        			node_2->next = tmp_node;
        			return node_2;
				}
		  }
		  if(check_node_exist ==2){
		  		break;
		  }
        head = head->next;
    }

    head = _head;
    if (check_node_exist != 2)
        return head;

    pre_node_1->next = node_2;
    pre_node_2->next = node_1;
    tmp_node = node_2->next;
    node_2->next = node_1->next;
    node_1->next = tmp_node;
    return head;
}
