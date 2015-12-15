vector<vector<int> > threeSum(vector<int> &num) {
    vector<vector<int> > res;
    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        if(target < 0)
        {
            break;
        }

        while (front < back) {

            int sum = num[front] + num[back];

            // Finding answer which start from number num[i]
            if (sum < target)
                front++;

            else if (sum > target)
                back--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);

                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;

                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }

        }
        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) 
            i++;
    }
    return res;
}

////

class Solution {
public: vector > threeSum (vector &num) { vector > result; if (num.size() < 3) return result;

            sort (num.begin (), num.end ());
             int target = 0;

             auto last = num.end() ;
             for (auto a = num.begin(); a < last; ++a) {
                    auto b = a + 1;
                    auto c = last - 1;
                    while (b < c) {
                            if ( *a + *b + *c < target) {
                                    ++b;
                            } else if ( *a + *b + *c  > target) {
                                    --c;
                            } else  {
                                    result.push_back({*a, *b, *c});
                                    ++b;
                                    --c;
                            }
                    }
                 /*  These word is edded by myself, is to accelerate. If NOT ADD, the code is TLE. */
                    while (*a == *(a+1)) {   // skip duplicate elsments 
                            ++a;
                    }
             }
             sort (result.begin(), result.end());
             result.erase (unique (result.begin(), result.end()), result.end());
             return result;
    }
};
