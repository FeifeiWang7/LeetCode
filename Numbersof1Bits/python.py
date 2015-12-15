class Solution(object):
    """
    600 / 600 test cases passed.
    Status: Accepted
    Runtime: 44 ms
    Submitted: 0 minutes ago
    """
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        binary_str_n = bin(n)
        hamming_weight = binary_str_n.count('1')
        return hamming_weight
#######
class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        bitsMap = [0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4]
        i = 0
        result = 0
        while i < 32:
            result += bitsMap[(n>>i) & 15]
            i += 4
        return result
####
class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        return bin(n).count('1')
#####
def hammingWeight(self, n):
    return sum([int(x) for x in str(bin(n))[2:]])
