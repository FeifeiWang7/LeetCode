uint32_t reverseBits(uint32_t n) {
    bitset<32> num(n);
    bitset<32> ret;

    for(int i = 0; i < 32; ++i)
        ret[i] = num[31-i];

    return ret.to_ulong();      
}
