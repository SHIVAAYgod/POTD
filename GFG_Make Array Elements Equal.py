class Solution:
    def minOperations(self, N):
        return (N//2)*((N//2)+N%2)
