class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
// Sort workers based on their efficiency
        sort(time.begin(), time.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] + a[2] != b[0] + b[2]) {
                return a[0] + a[2] > b[0] + b[2];
            } else {
                return a[3] > b[3];
            }
        });

        // Create priority queues for left and right side of the bridge
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leftQueue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> rightQueue;

        int currentTime = 0;
        int boxesLeft = n;
        vector<int> leftWorkerTimes(k, -1);

        while (boxesLeft > 0) {
            // Move workers from right to left
            while (!rightQueue.empty() && rightQueue.top().first <= currentTime) {
                pair<int, int> worker = rightQueue.top();
                rightQueue.pop();
                int workerIndex = worker.second;
                leftQueue.push({currentTime + time[workerIndex][3], workerIndex});
            }

            // Move workers from left to right
            while (!leftQueue.empty() && leftQueue.top().first <= currentTime) {
                pair<int, int> worker = leftQueue.top();
                leftQueue.pop();
                int workerIndex = worker.second;
                leftWorkerTimes[workerIndex] = currentTime;
                rightQueue.push({currentTime + time[workerIndex][2], workerIndex});
                boxesLeft--;
            }

            // Add waiting workers on the left side to the right queue
            while (!leftQueue.empty() && leftQueue.top().first > currentTime) {
                rightQueue.push(leftQueue.top());
                leftQueue.pop();
            }

            // Move a worker from the right side to the left side if the bridge is free
            if (!rightQueue.empty()) {
                pair<int, int> worker = rightQueue.top();
                rightQueue.pop();
                int workerIndex = worker.second;
                currentTime = max(currentTime, time[workerIndex][0]);
                leftQueue.push({currentTime + time[workerIndex][1], workerIndex});
            } else {
                currentTime++;
            }
        }

        // Find the time at which the last worker reaches the left bank
        int lastWorkerTime = *max_element(leftWorkerTimes.begin(), leftWorkerTimes.end());

        return lastWorkerTime;
    }
};