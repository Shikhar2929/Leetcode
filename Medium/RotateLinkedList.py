class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        size = 1
        temp = head
        if(k == 0):
            return head 
        if(temp == None):
            return head
        while(temp.next != None):
            size += 1
            temp = temp.next
        k %= size
        print(k)
        if(k == 0):
            return head
        temp.next = head
        for i in range(size - k - 1):
            head = head.next
        answer = head.next
        head.next = None
        return answer
