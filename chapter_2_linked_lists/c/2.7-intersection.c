#include "singly_linked_lists.h"

/**
 * Finds if two linked lists intersect and returns the node where they first
 * meet.
 * O(n) time and space complexity.
 */
sll_node *find_intersection(sll_node *list1, sll_node *list2)
{
    int len1, len2, difference;
    sll_node *long_list, *short_list;

    len1 = list_len(list1);
    len2 = list_len(list2);
    long_list = len1 > len2 ? list1 : list2;
    short_list = len1 > len2 ? list2 : list1;
    difference = list_len(long_list) - list_len(short_list);
    while (difference)
    {
        long_list = long_list->next;
        difference--;
    }
    while (long_list)
    {
        if (long_list == short_list)
            return long_list;
        long_list = long_list->next;
        short_list = short_list->next;
    }
    return NULL;
}

int main()
{
    sll_node *head = NULL;
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    sll_node *n4 = add_nodeint(&head, 4);
    add_nodeint(&head, 8);
    add_nodeint(&head, 16);

    sll_node *head2 = NULL;
    sll_node *n100 = add_nodeint(&head2, 100);
    add_nodeint(&head2, 101);
    add_nodeint(&head2, 102);
    n100->next = n4;

    sll_node *res = find_intersection(head, head2);
    printf("%i\n", res ? res->n : -1); // 4

    sll_node *head3 = NULL;
    add_nodeint(&head3, 1);
    add_nodeint(&head3, 2);
    add_nodeint(&head3, 4);
    add_nodeint(&head3, 8);
    add_nodeint(&head3, 16);
    sll_node *res2 = find_intersection(head, head3);
    printf("%i\n", res2 ? res2->n : -1); // -1

    return 0;
}