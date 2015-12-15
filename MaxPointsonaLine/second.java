import java.util.Map;
import java.util.HashMap;

/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    public int maxPoints(Point[] points) {
        int maxLine = 0;

        for (int i=0; i<(points.length-maxLine); i++) {
            int coincident = 0;
            Map<Double, Integer> pointCounts = new HashMap<Double, Integer>();
            for (int j=i+1; j<points.length; j++) {
                Double slope;
                if (points[i].x==points[j].x && points[i].y==points[j].y) {
                    coincident++;
                    continue;
                } else if (points[i].x == points[j].x) {
                    slope = Math.PI;
                } else if (points[i].y == points[j].y) {
                    slope = 0.0; // logically we don't need this, but in practice i find that we do
                } else {
                    slope = new Double((double)(points[i].y-points[j].y) / (double)(points[i].x-points[j].x));
                }

                if (pointCounts.containsKey(slope))
                    pointCounts.put(slope, pointCounts.get(slope)+1);
                else
                    pointCounts.put(slope, new Integer(1));
            }
            maxLine = Math.max(maxLine, 1+coincident+maxValue(pointCounts));
        }

        return maxLine;
    }

    private int maxValue(Map<Double, Integer> doubleIntMap) {
        int max = 0;
        Set<Double> keys = doubleIntMap.keySet();
        Iterator iter = keys.iterator();
        while (iter.hasNext())
            max = Math.max(max, doubleIntMap.get(iter.next()));
        return max;
    }
}
My Algorithm was the following:

for every point i from 0 to points.length - maxColinearPointsFoundSoFar {
    for every j from i+1 to points.length-1 {
        ithPointHashTable[slope] += 1;
    } 
    find max value in ithPointHashTable and update maxColinearPointsFoundSoFar;
}
Here are the reasons that combine to make me feel terrible:

Whenever I use a hash table to achieve O(some runtime) having to assume hash table insertion is O(1), I don't feel great. hash tables also use extra memory which we are also watching our algorithms for.

This might've been the first time ever for me attempting to use a Double as a map key. Through this exercise I've discovered that its not a good idea. For instance (double) (0/1) and (double) (0/-1) evaluates to two different things. That's one thing the test cases uncovered. There might be more cases where mathematically expressions should evaluate to the same thing but in above code they don't.

More along those lines, for two points that have infinite slope, I inesrt them into the hashMap with a key of Math.PI. Mathematically no two points with integer coordinates should have an irrational slope, however in practice because of computer precision. But could there be a case where two points with integer coordinates have a slope between them that creates an equivalent map key as Math.PI? Although its not very likely, the probability might not be 0.

///
import java.util.*;

public static class Line {// nested class Line
    Double slope; //slope of the line, null if the line is vertical to x-axis
    Double xInt; //x-intercept, y-intercept if the line is vertical to y-axis
    Line(){slope=null;xInt=null;}
    Line(Double slope, Double xInt){this.slope=slope;this.xInt=xInt;}
    Line(Point a, Point b){//Line construct function given two points
        int deltaX = a.x-b.x;
        int deltaY = a.y-b.y;
        if (deltaX==0){
            this.slope=null;
            this.xInt=Double.valueOf(a.x);
        }else if (deltaY==0){
            this.slope=0.0;
            this.xInt = Double.valueOf(a.y);
        }else{
            this.slope = (double)deltaY/(double)deltaX;
            this.xInt = a.x-a.y/this.slope;
        }
    }
    public boolean nearlyEquals(Double a, Double b){
        return (a==null && b==null)||(Math.abs(a-b)<.0001);
    }

    public boolean nearlyEquals(Object o){is same line? true=same; false=not same
        if (o==null) return false;
        if (!(o instanceof Line)) return false;
        Line to = (Line) o;
        return nearlyEquals(this.slope, to.slope) && nearlyEquals(this.xInt, to.xInt);
    }
    public Double getNearSlope(){// get quantized double value of slope from a double value of slope to remove difference between double values. This is not always necessary.
        if(this.slope==null) return null;
        return ((int)(this.slope/.0001))*0.0001;
    }
    public boolean passesPoint(Point p){// does the Line pass the Point? true = pass; false = not pass
        if (p==null) return false;
        if(this.slope==null){
            return nearlyEquals(Double.valueOf(p.x), this.xInt);
        }
        if (this.slope==0){
            return nearlyEquals(this.xInt, Double.valueOf(p.y));
        }
        return nearlyEquals(Double.valueOf(p.x), 1/this.slope*p.y+xInt);
    }
}
public static int count(Hashtable<Double, ArrayList<Line>> lines, Line line){// count the number of lines in *lines* that are same as *line*. The more duplicates the line has in lines, the more points it passes.
    ArrayList<Line> linesList = lines.get(line.getNearSlope());
    int count=0;
    for (Line oneLine : linesList){
        if (line.nearlyEquals(oneLine)) count++;
    }
    return count;
}
public static int count(ArrayList<Line> nullLinesList, Line line){// count the number of lines in * nullLinesList* that are same as *line*. *nullLinesList* is the list of lines that have null value of slopes. The more duplicates the line has in lines, the more points it passes.
    int count=0;
    for (Line oneLine : nullLinesList){
        if (line.nearlyEquals(oneLine)) count++;
    }
    return count;
}
public static int maxPoints(Point[] points){
    if (points==null || points.length<=0) return 0;
    if(points.length==1) return 1; 
    Hashtable<Double, ArrayList<Line>> lines = new Hashtable<Double, ArrayList<Line>>();
    int max = 0;
    Line optimalLine = null;
    ArrayList<Line> nullLinesList = new ArrayList<Line>();
    for (int i=0;i<points.length-1;++i){//count 
        for (int j=i+1;j<points.length;++j){
            Line line = new Line(points[i], points[j]);
            ArrayList<Line> linesList = null;
            Double key = line.getNearSlope();
            int num;
            if (key==null){
                nullLinesList.add(line);    
                num = count(nullLinesList, line);
            }else{
                if (lines.containsKey(key)){
                    linesList = lines.get(line.getNearSlope());
                }else{
                    linesList=new ArrayList<Line>();
                    lines.put(key, linesList);
                }
                linesList.add(line);
                num = count(lines, line);                   
            }
            if (max < num){
                max = num;
                optimalLine = line;
            }
        }
    }
    if (optimalLine==null) return 0;
    max = 0;
    for (int i=0;i<points.length;++i){
        if(optimalLine.passesPoint(points[i]))max++;
    }
    return max;
}
