class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0;
        int maxRooms = 0;
        int i = 0, j = 0;

        while (i < n) {
            if (start[i] < end[j]) {
                rooms++;          // new meeting starts
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;          // meeting ends
                j++;
            }
        }
        return maxRooms;
    }
};
