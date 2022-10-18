class Solution(object):
    def middleNode(self, head):
        p1 = head
        p2 = head
        while(p2.next != None):
            p1 = p1.next 
            p2 = p2.next
            if(p2.next != None):
                p2 = p2.next 
        return p1
            
