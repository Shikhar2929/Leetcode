class Solution(object):
    def swapPairs(self, head):
        i = True 
        prev = None
        answer = head
        while(head != None and head.next != None):
            temp = head.next;
            temp2 = temp.next
            temp.next = head
            head.next = temp2
            if(prev != None):
                prev.next = temp
            prev = head
            print(prev.val)
            if i:
                answer = temp
                i = False
            if(head.next != None):
                head = head.next
            else:
                break
        return answer   
