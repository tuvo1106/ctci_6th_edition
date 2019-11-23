#include "tree.h"
#include "binary_search_tree.h"
#include "singly_linked_list.h"

/* Creates a linked list out of every level in a binary tree */
vector<LinkedList *> create_level_linked_list(TreeNode *root)
{
    vector<LinkedList *> res;
    LinkedList *curr, *next;
    Node *tmp;

    curr = new LinkedList();
    curr->add_node(root);
    while (curr->length)
    {
        tmp = curr->head;
        res.push_back(curr);
        next = new LinkedList();
        /* loop through all nodes in parent */
        while (tmp)
        {
            if (tmp->value->left)
                next->add_node(tmp->value->left);
            if (tmp->value->right)
                next->add_node(tmp->value->right);
            tmp = tmp->next;
        }
        curr = next;
    }
    return res;
}

int main()
{
    BinarySearchTree bst;
    vector<LinkedList *> v;

    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(15);
    bst.insert(17);

    v = create_level_linked_list(bst.root);
    for (auto ptr : v)
        ptr->print_list();
    /*
    20
    30 -> 10
    15 -> 5
    7 -> 3 -> 17
    */
    return 0;
}
