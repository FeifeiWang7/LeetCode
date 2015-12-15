public class Solution {
    public int compareVersion(String version1, String version2) {
        int v1Pos = version1.indexOf(".");
        int v2Pos = version2.indexOf(".");

        int firstLevel1 = Integer.parseInt(version1.substring(0, v1Pos == -1 ? version1.length() : v1Pos));
        int firstLevel2 = Integer.parseInt(version2.substring(0, v2Pos == -1 ? version2.length() : v2Pos));

        if (firstLevel1 != firstLevel2)
            return firstLevel1 > firstLevel2 ? 1 : -1;

        if (v1Pos != -1 || v2Pos!= -1)
            return compareVersion(v1Pos == -1 ? "0" :version1.substring(v1Pos + 1), v2Pos == -1 ? "0" :version2.substring(v2Pos + 1));
        else 
            return 0;
    }
}
