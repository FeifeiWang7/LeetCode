#include <unordered_map>
 
class Solution {
public:
    static const int EPSILON = 1000000;  // float precision purpose
    std::unordered_map<int, int> lines;  // We use the unordered_map, key is the slope of the line and value is the count of points
    int find_sub_max_points(vector<Point> &points, int last) {
        lines.clear();  // Clear the hash table
        int num_same_x = 0;  // count the number of points with same x-coordinate of Point[last]
        int num_same_point = 1;
        const int x0 = points[last].x;
        const int y0 = points[last].y;
        int x,y,tmp;
        int res = 0;
        for (int i = last-1; i >= 0; i--) {
            x = points[i].x;
            y = points[i].y;
            if (x == x0) {
                if (y == y0) num_same_point++;
                else if(++num_same_x > res)
                    res = num_same_x;
            }
            else {
                tmp = int( (y-y0) * EPSILON ) / (x-x0);
                if (++lines[tmp] > res) res = lines[tmp];
                /* the line above is equal to following lines
                std::unordered_map<int,int>::const_iterator got = lines.find (tmp);
                if (got == lines.end())
                    lines[tmp] = 1;
                else
                    lines[tmp]++;
                if (lines[tmp]>res) res = lines[tmp];
                */
            }
        }
        return res+num_same_point; // Point[last] itself should be counted
    }
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n <= 2) return n;
        int res = 2;
        int tmp = 0;
        for(int i=2; i<n; i++) {
            tmp = find_sub_max_points(points, i);
            if (tmp > res) res = tmp;
        }
        return res;
    }
};
