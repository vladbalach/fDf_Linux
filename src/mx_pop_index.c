#include "header.h"

void mx_pop_index(t_list **list, int index) {
    int i = 0;
    t_list *tmp = *list;
    t_list **ttt = list;
    if ((list == 0) || (*list == 0))
        return;
    if (index == 0) {
        tmp = (*list)->next;
        free((*list)->data);
        free(*list);
        *list = tmp;
        return;
    }
    while (tmp->next) {
        if (++i == index) {
            t_list *tmp2 = tmp->next->next;
            free(tmp->next->data);
            free(tmp->next);
            
            tmp->next = tmp2;
            return ;
        }
        tmp = tmp->next;
    }
}