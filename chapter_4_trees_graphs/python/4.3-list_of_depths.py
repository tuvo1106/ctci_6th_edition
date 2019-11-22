SinglyLinkedList = __import__(
    '../../chapter_2_linked_lists/python/singly_linked_list').SinglyLinkedList
TreeNode = __import__('tree').TreeNode


def list_of_depths(root):
    """
    Creates a linked list out of every level in a binary tree
    """
    res = []
    current = SinglyLinkedList()
    if root:
        current.add_to_front(root)
    while current.length:
        res.append(current)
        tmp = current.head
        current = SinglyLinkedList()
        while tmp:
            # loop through all nodes in parent
            if tmp.value.left:
                current.add_to_front(tmp.value.left)
            if tmp.value.right:
                current.add_to_front(tmp.value.right)
            tmp = tmp.next
    return res


def print_linked_list(linked_list):
    """
    Prints all elements of a singly linked list
    """
    curr = linked_list.head
    while curr:
        print(curr.value.value, end="-> " if curr.next else "\n")
        curr = curr.next


n1 = TreeNode(1)
n2 = TreeNode(2)
n3 = TreeNode(3)
n1.left = n2
n1.right = n3
n4 = TreeNode(4)
n5 = TreeNode(5)
n2.left = n4
n2.right = n5
n6 = TreeNode(6)
n7 = TreeNode(7)
n3.left = n6
n3.right = n7

res = list_of_depths(n1)
for linked_list in res:
    print_linked_list(linked_list)

"""
1
3-> 2
5-> 4-> 7-> 6
"""
