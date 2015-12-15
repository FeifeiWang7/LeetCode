public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    if (A >= G || E >= C || B >= H || F >= D) return (C - A) * (D - B) + (G - E) * (H - F);
    int x1 = Math.max(A, E);
    int y1 = Math.max(B, F);
    int x2 = Math.min(C, G);
    int y2 = Math.min(D, H);
    return (C - A) * (D - B) + (G - E) * (H - F) - (x2 - x1) * (y2 -y1);
}
/////
public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int common = (C <= E || A >= G || B >= H || D <= F) ? 0 : (Math.min(C, G) - Math.max(A, E)) * (Math.min(D, H) - Math.max(B, F));
    return (C - A) * (D - B) + (G - E) * (H - F) - common;
}
///////
class Point {
    int x;
    int y;
    Point (int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Rectangle {
    Point bottomLeft;
    Point topRight;

    Rectangle (Point bottomLeft, Point topRight) {
        this.bottomLeft = bottomLeft;
        this.topRight = topRight;
    }

    Rectangle (int A, int B, int C, int D) {
        this(new Point(A, B), new Point(C, D));
    }

    // calculate area
    public int getArea() {
        return Math.abs(topRight.x - bottomLeft.x) * 
            Math.abs(topRight.y - bottomLeft.y);
    }

    // return a rectange which is the common area between this rectangle and the given rectangle;
    // otherwise, a rect with area of 0 will be returned
    public Rectangle getOverlayRect(Rectangle rect) {
        int A = Math.max(bottomLeft.x, rect.bottomLeft.x);
        int B = Math.max(bottomLeft.y, rect.bottomLeft.y);
        int C = Math.min(topRight.x, rect.topRight.x);
        int D = Math.min(topRight.y, rect.topRight.y);

        if (A > C || B > D) {
            // rectangles did not overlay
            return new Rectangle(0, 0, 0, 0);
        }
        return new Rectangle(A, B, C, D);
    }
}

public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    Rectangle rect1 = new Rectangle(A, B, C, D);
    Rectangle rect2 = new Rectangle(E, F, G, H);
    Rectangle overlaidRect = rect1.getOverlayRect(rect2);
    return rect1.getArea() + rect2.getArea() - overlaidRect.getArea();
}
///
public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {

        int areaOfSqrA = (C-A) * (D-B);
         int areaOfSqrB = (G-E) * (H-F);

        int left = Math.max(A, E);
        int right = Math.min(G, C);
        int bottom = Math.max(F, B);
        int top = Math.min(D, H);

        //If overlap
        int overlap = 0;
        if(right > left && top > bottom)
             overlap = (right - left) * (top - bottom);

        return areaOfSqrA + areaOfSqrB - overlap;
    }
Hello! So, the code should be fairly straightforward. I first calculate the area of each rectangle and then calculate the overlapping area between the two rectangles (if there is one!). At the end, we sum up the individual areas and subtract the overlapping area/0 !

Feel free to ask should you have any queries for me OR if my solution can be improved upon! :)
///
hero has the same opinion! Mine is similar with yours :)

public int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int together;
        if (C <= E || A >= G || B >= H || D <= F) {
            together = 0;
        } else {
            int x = Math.min(C, G) - Math.max(A, E);
            int y = Math.min(D, H) - Math.max(B, F);
            together = x * y;
        }
        return (C - A) * (D - B) + (G - E) * (H - F) - together;
    }
