class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        int disSquare = INT_MAX;
        for (int x = x1; x <= x2; x++)
            for (int y = y1; y <= y2; y++)
                disSquare = min(disSquare, (x - xCenter) * (x - xCenter) +
                                         (y - yCenter) * (y - yCenter));
        return disSquare <= radius * radius;
    }
};