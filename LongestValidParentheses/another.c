int max(int a, int b) {
    return a > b ? a : b;
}
int longestValidParentheses(char* s) {
    int i, m = 0, count = 0, sum = 0;
    if (!s) {
        return 0;
    }
    for (i = 0; s[i]; ++i) {
        count++;
        sum += '(' == s[i] ? 1 : -1;
        if (0 == sum) {
            m = max(m, count);
        } else if (-1 == sum) {
            sum = 0;
            count = 0;
        }
    }
    sum = 0;
    count = 0;
    for (i = i - 1; i >= 0; --i) {
        count++;
        sum += '(' == s[i] ? -1 : 1;
        if (0 == sum) {
            m = max(m, count);
        } else if (-1 == sum) {
            sum = 0;
            count = 0;
        }
    }
    return m;
}
///
When right parentheses are more than left parentheses in the forward pass, we can discard previous parentheses. In the backward pass, when left parentheses are more than right parentheses, we can discard previous parentheses.

int longestValidParentheses(string s) {
    int longest = 0;
    int extra=0;
    int length=0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            extra++;
            length++;
        }
        else {
            if(extra>0) {
                extra--;
                length++;
                if(extra == 0)
                    longest = max(longest, length);
            }
            else {
                extra = 0;
                length=0;
            }
        }
    }
    length = 0;
    extra=0;
    for(int i=s.size()-1; i>=0; i--) {
        if(s[i] == ')') {
            extra++;
            length++;
        }
        else {
            if(extra>0){
                extra--;
                length++;
                if(extra == 0)
                    longest = max(longest, length);

            }
            else {
                extra = 0;
                length=0;
            }
        }
    }
    return longest;
}
/////
My idea is scan once or almost twice (from head to tail and if need from tail to somewhere again.) Please see my code and give some advice. If need more explian, please let me know.

comp :O(n) space:O(1)

int longestValidParentheses(char* s)

{
    int lvp = 0, lvp1 = 0, l = 0, r = 0, complete = 0;
    int i, len = strlen(s);

    for (i = 0; i < len; ++i)
    {
        if (s[i] == '(')
        {
            ++l;
        }
        else if (s[i] == ')')
        {
            ++r;
        }

        if (l == r)
        {
            if (complete == 0)
            {
                lvp1 += r;
            }
            else
            {
                lvp1 = r;
            }

            l = 0;
            r = 0;
            lvp = (lvp > lvp1 ? lvp : lvp1);
            complete = 0;
        }
        else if (l < r)// too much right bracket(s). but the only possible is l == 0 && r == 1.
        {
            // no need to update lvp1 and lvp.
            r = 0;
            lvp1 = 0;
            complete = -1;
        }
        else if (l > r && i == len - 1)
        {
            lvp1 = reverse_lvp(s, l + r);
            lvp = (lvp > lvp1 ? lvp : lvp1);
        }
    }

    lvp *= 2;

    return lvp;
}
// and

int reverselvp(char *s, int lento_deal)

{
    int rev_lvp = 0, lvp1 = 0, l = 0, r = 0, complete = 0;
    int i, len = strlen(s);

    for (i = 1; i <= len_to_deal; ++i)
    {
        if (s[len - i] == ')')
        {
            ++l;
        }
        else if (s[len - i] == '(')
        {
            ++r;
        }

        if (l == r)
        {
            if (complete == 0)
            {
                lvp1 += r;
            }
            else
            {
                lvp1 = r;
            }

            l = 0;
            r = 0;
            rev_lvp = (rev_lvp > lvp1 ? rev_lvp : lvp1);
            complete = 0;
        }
        else if (l < r)// too much right bracket(s). but the only possible is l == 0 && r == 1.
        {
            // no need to update lvp1 and rev_lvp.
            r = 0;
            lvp1 = 0;
            complete = -1;
        }
    }

    return rev_lvp;
}

