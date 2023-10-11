class Solution:
    def isPalindrome(self, x: int) -> bool:
        number = str(x)
        length = len(number)
        
        for i in range(length):
            if number[i] != number[length-i-1]:
                return False
            
        return True
        