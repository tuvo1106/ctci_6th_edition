SinglyLinkedList = __import__('singly_linked_list').SinglyLinkedList


class SinglyLinkedList_2_6(SinglyLinkedList):

    def is_palindrome(self):
        """
        Determines if a linked list is a palindrome
        O(n) time and space complexity
        """
        hare = tortoise = self.head
        stack = []
        # navigate to middle node
        while hare and hare.next:
            hare = hare.next.next
            stack.append(tortoise.value)
            tortoise = tortoise.next
        if self.length & 1:
            tortoise = tortoise.next
        while tortoise:
            if tortoise.value != stack.pop():
                return False
            tortoise = tortoise.next
        return True


sll = SinglyLinkedList_2_6()
sll.add_to_front(1)
sll.add_to_front(2)
sll.add_to_front(3)
sll.add_to_front(4)
sll.add_to_front(3)
sll.add_to_front(2)
sll.add_to_front(1)
sll.print_linked_list()  # 1-> 2-> 3-> 4-> 3-> 2-> 1
print(sll.is_palindrome())  # True

sll2 = SinglyLinkedList_2_6()
sll2.add_to_front(1)
sll2.add_to_front(2)
sll2.add_to_front(3)
sll2.add_to_front(3)
sll2.add_to_front(2)
sll2.add_to_front(1)
sll2.print_linked_list()  # 1-> 2-> 3-> 3-> 2-> 1
print(sll2.is_palindrome())  # True

sll3 = SinglyLinkedList_2_6()
sll3.add_to_front(1)
sll3.add_to_front(2)
sll3.add_to_front(3)
sll3.add_to_front(4)
sll3.add_to_front(5)
sll3.add_to_front(3)
sll3.add_to_front(2)
sll3.add_to_front(1)
sll3.print_linked_list()  # 1-> 2-> 3-> 4-> 5-> 3-> 2-> 1
print(sll3.is_palindrome())  # False
