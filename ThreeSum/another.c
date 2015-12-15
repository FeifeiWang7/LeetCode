int left(int i)
    {
        return 2*i;
    }

    int right(int i)
    {
        return 2*i + 1;
    }

    void swap(int* pa,int* pb)
    {
        if(*pa != *pb)
        {
            *pa += *pb;
            *pb = *pa - *pb;
            *pa = *pa - *pb;
        }
    }

    void heap_maxify(int* base, int inx, int size)
    {
        int largest = 0;
        int l = 0;
        int r = 0;
        while(true)
        {
            l = left(inx);
            r = right(inx);
            if(l < size && base[inx] < base[l])
                largest = l;
            else
                largest = inx;

            if(r < size && base[largest] < base[r])
                largest = r;

            if(largest != inx)
            {
                swap(base + inx, base + largest);
                inx = largest;
            }
            else
                break;
        }
    }

    void build_heap(int* base,  int len)
    {
        for(int i = len/2; i >= 0 ;--i)
            heap_maxify(base,i,len);

    }

    void head_sort(int* base, int len)
    {
        if(base == NULL || len == 0)
        {
            return;
        }
        build_heap(base,len);
        for(int i = len - 1; i >= 0; --i)
        {
            swap(base,base + i);
            heap_maxify(base,0,i);
        }
    }

    int** threeSum(int* nums, int numsSize, int* returnSize) {
        if(numsSize < 3)
            return NULL;
        int* s = nums;
        int* e = nums + numsSize - 1;
        int* c = NULL;
        int** _3m = (int**)calloc(4048,sizeof(int*));
        int i = 0;
        int tmp = 0;
        head_sort(nums,numsSize);
        while(s < e - 1)
        {
            c = s + 1;
            while(c < e)
            {
                tmp  = *e + *s;
                if(tmp + *c == 0)
                {
                    if(i != 0 && *s == _3m[i - 1][0] && *c == _3m[i - 1][1])
                    {
                            --e;
                            continue;
                    }
                    _3m[i] = (int*)malloc(3*sizeof(int));
                    _3m[i][0] = *s;
                    _3m[i][1] = *c;
                    _3m[i][2] = *e;
                    ++i;
                    while(s < e && *s == *(s + 1)) ++s;
                    while(s < e && *e == *(e - 1)) --e;
                    --e;
                }else if(( tmp > 0 && *c >= 0  )|| ( tmp < 0 && *(e - 1) < 0 ) || (c == e - 1))
                {
                    c = s + 1;
                    while(s < e && *e == *(e - 1)) --e;
                    --e;
                }else
                {
                    ++c;
                }
            }
            ++s;
            e = nums + numsSize - 1;
        }
        *returnSize = i;
        return _3m;
    }
