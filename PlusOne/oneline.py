class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, digits):
        return [int(x) for x in list(str(int(''.join([str(x) for x in digits])) + 1))]
