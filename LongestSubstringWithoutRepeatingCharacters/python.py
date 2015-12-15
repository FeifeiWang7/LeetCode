left = -1
    max_length = 0
    char_idx_map = {}
    for right, c in enumerate(s):
        if c in char_idx_map and char_idx_map[c] > left:
            left = char_idx_map[c]
        char_idx_map[c] = right
        print(char_idx_map, left, right)
        max_length = max(max_length, right-left)
    return max_length
