class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i = 0

        if len(s) > len(t):
            return False
        if len(s) == 0:
            return True
                
        for j in range(0, len(t)):
            if i <= len(s) - 1:
                if s[i] == t[j]:
                    i += 1
                    
        return i == len(s)
    
