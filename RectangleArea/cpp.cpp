class Solution {
public:
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int total = (C-A) * (D-B) + (G-E) * (H-F), overlap = 0;
    if(G>A && E<C && F<D && H>B)
        overlap = (min(C,G) - max(A,E)) * (min(D,H) - max(B,F));
    return total - overlap;
}
};
///
class Solution { public: int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    int area1 = (C-A)*(D-B);
    int area2 = (G-E)*(H-F);
    if(C<=E || G<=A || D<=F ||B>=H){
        return area1+area2;
    }
    int width =  (A<=E)?min(C-E,G-E):min(C-A,G-A);
    int height = (B>=F)?min(D-B,H-B):min(D-F,H-F);
    return area1+area2-width*height;

}
};
///
// author ： s2003zy.com
// weibo : weibo.com/songzy982
class Solution {

    struct Point {
      int x, y;
      Point(int xx, int yy) : x(xx), y(yy) {}
    };
    struct Rectangle {
      Point lb, ur;
      Rectangle(const Point &a, const Point &b) : lb(a), ur(b) {}
      int size() {
          return (ur.x - lb.x) * (ur.y - lb.y);
      }
      int inter(const Rectangle &a) {
          int maxLeft  = max(this -> lb.x, a.lb.x);
          int minRight = min(this -> ur.x, a.ur.x);
          int minUpper = min(this -> ur.y, a.ur.y);
          int maxLower = max(this -> lb.y, a.lb.y);
          return (minRight - maxLeft) * (minUpper - maxLower);
      }
    };
public:
    bool overLapping(const Rectangle &a, const Rectangle &b) {
        if (a.ur.x < b.lb.x) return false;
        if (a.ur.y < b.lb.y) return false;
        if (b.ur.x < a.lb.x) return false;
        if (b.ur.y < a.lb.y) return false;
        return true;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        Rectangle ra( Point(A, B), Point(C, D) );
        Rectangle rb( Point(E, F), Point(G, H) );
        if (!overLapping(ra, rb)) {
            return ra.size() + rb.size();
        }
        return ra.size() + rb.size() - ra.inter(rb);
    }
};
/////
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
{
    int total = (C-A) * (D-B) + (G-E) * (H-F);

    if (C<=E || A>=G || B>=H || D<=F )
        return total;
    else
    {
        vector <int> h;
        h.push_back(A);
        h.push_back(C);
        h.push_back(E);
        h.push_back(G);

        vector <int> v;
        v.push_back(B);
        v.push_back(D);
        v.push_back(F);
        v.push_back(H);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        total = total - (h[2] - h [1]) * (v[2] - v[1]);
        return total;
    }
}
///
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C>E && G>A && H>B && D>F) ? (C-A)*(D-B)+(G-E)*(H-F)-(min(C,G)-max(A,E))*(min(D,H)-max(B,F)) : (C-A)*(D-B)+(G-E)*(H-F);
    }
};
///
Instead of checking whether the rectangles overlap, I max right with left (and top with bottom). Haven't seen that in other solutions.

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A,E), right = max(min(C,G), left);
    int bottom = max(B,F), top = max(min(D,H), bottom);
    return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
}
///
//36ms
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            return (D-B)*(C-A)+(G-E)*(H-F)-getXY(D,B,H,F)*getXY(C,A,G,E);
        }
        // assert D>=B,H>=F 
        int getXY(int D, int B, int H, int F){
            if((B>=H)||(D<=F))
                return 0;       // no overlap
            vector<int>V(4);
            V[0] = D;V[1] = B; V[2] = H, V[3] = F;
            sort(V.begin(),V.end());     // get the second and the third one to calc overlap length
            return V[2]-V[1];  // if no overLap, then v[2]-v[1] = 0, return 0
        }

        // 32ms
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int S = (D-B)*(C-A)+(G-E)*(H-F);
            if((H<=B)||(D<=F)||(C<=E)||(G<=A)) return S;  //in case of overflow, avoid calc overlap
            return S-(min(D,H)-max(B,F))*(min(C,G)-max(A,E)); 
        // return S-max(min(D,H)-max(B,F), 0)*max(min(C,G)-max(A,E), 0); //old ver

}
///
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int S1 = (C-A)*(D-B);
    int S2 = (G-E)*(H-F);
    if(C < E || G < A || H < B || D < F)
    {
        return S1 + S2; // no intersection
    }
    int xi_left = max(A, E);
    int yi_left = max(B, F);
    int xi_right = min(C, G);
    int yi_right = min(D, H);

    return S1 + S2 - (xi_right - xi_left)*(yi_right - yi_left);
}
///
public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

    int space =0;
    int space1 = (Math.abs(A-C)*Math.abs(B-D));
    int space2 =(Math.abs(E-G)*Math.abs(F-H));

    //borrowed from anther solution
    int left = Math.max(A,E);
    int right = Math.min(G,C);
    int top = Math.min(D,H);
    int bottom = Math.max(B,F);

    if (top >= bottom && right >= left) {
        space = (Math.abs(bottom-top)*Math.abs(left-right));
    }
    return space1+space2-space;

}
///
The original version wasn't passing anymore because of new test cases that cause overflow. So now we're avoiding computing the differences below if the result will be negative. This avoids overflow in cases where the rectangles are far apart. It looks like this is basically the same thing that @shw1500 was suggesting, but you don't need the extra max function on the outside.

The return statement is based on comments from @StefanPochmann. We want to avoid forming the sum area(R1) + area(R2). This avoids overflow in cases where area(R1) + area(R2) will overflow, but area(R1) + area(R2) - overlap(R1, R2) fits in an int. There aren't any test cases for this. Add some maybe? Edit: There are test cases for this, but the overflow didn't matter.

New version- avoids overflow when area(R1) + area(R2) overflows but the answer shouldn't.

class Solution {
    public:
        int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
            int overlap_width = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0; 
            int overlap_height = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
            return ((C - A) * (D - B) - overlap_width * overlap_height) + (G - E) * (H - F); // order avoids overflow
        }
    };
Second version- avoids overflow when rectangles are far apart

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_width = min(C, G) > max(A, E) ? min(C, G) - max(A, E) : 0; 
        int overlap_height = min(D, H) > max(B, F) ? min(D, H) - max(B, F) : 0;
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap_width * overlap_height;
    }
};
Old version- overflows for some inputs where the rectangles are far apart.

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_width = max(min(C, G) - max(A, E), 0), overlap_height = max(min(D, H) - max(B, F), 0);
        return (C - A) * (D - B) + (G - E) * (H - F) - overlap_width * overlap_height;
    }
};
