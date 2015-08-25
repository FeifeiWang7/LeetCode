def plusOne1(self, digits):
    return map(int, list(str(reduce(lambda x, y: 10*x+y, digits)+1)))

def plusOne(self, digits):
    carry = 1
    for i in xrange(len(digits)-1, -1, -1):
        carry, digits[i] = divmod(digits[i] + carry, 10)
    if carry:
        digits.insert(0, carry)
    return digits
