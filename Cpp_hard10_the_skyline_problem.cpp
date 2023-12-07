class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      vector<vector<int>> result;
        vector<pair<int, int>> events;

        // Create events for the left and right edges of each building
        for (const auto& building : buildings) {
            // For the left edge, use negative height to distinguish it from the right edge
            events.push_back({building[0], -building[2]});
            events.push_back({building[1], building[2]});
        }

        // Sort the events based on x-coordinate and then on the height
        sort(events.begin(), events.end());

        // Max heap to store the heights of the buildings
        priority_queue<int> maxHeap;

        // Insert a dummy building to ensure the last key point is always considered
        maxHeap.push(0);

        int prevMaxHeight = 0;

        // Process each event
        for (const auto& event : events) {
            int x = event.first;
            int h = abs(event.second); // Use abs to get the actual height

            if (event.second < 0) { // Left edge of a building
                maxHeap.push(h);
            } else { // Right edge of a building
                maxHeap = removeHeight(maxHeap, h);
            }

            // Check if the current max height has changed
            int currMaxHeight = maxHeap.top();
            if (prevMaxHeight != currMaxHeight) {
                result.push_back({x, currMaxHeight});
                prevMaxHeight = currMaxHeight;
            }
        }

        return result;
    }

private:
    // Helper function to remove height from the heap
    priority_queue<int> removeHeight(priority_queue<int> maxHeap, int target) {
        priority_queue<int> newHeap;
        while (!maxHeap.empty()) {
            int h = maxHeap.top();
            maxHeap.pop();
            if (h != target) {
                newHeap.push(h);
            }
        }
        return newHeap;  
    }
};