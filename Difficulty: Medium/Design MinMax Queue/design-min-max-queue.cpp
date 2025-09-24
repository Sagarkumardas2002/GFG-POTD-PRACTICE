class SpecialQueue {
    queue<int> q;
    deque<int> minDeque; // for minimum values
    deque<int> maxDeque; // for maximum values

  public:

    void enqueue(int x) {
        q.push(x);

        // Maintain increasing order for minDeque
        while (!minDeque.empty() && minDeque.back() > x)
            minDeque.pop_back();
        minDeque.push_back(x);

        // Maintain decreasing order for maxDeque
        while (!maxDeque.empty() && maxDeque.back() < x)
            maxDeque.pop_back();
        maxDeque.push_back(x);
    }

    void dequeue() {
        if (q.empty()) return;
        int frontVal = q.front();
        q.pop();

        if (!minDeque.empty() && minDeque.front() == frontVal)
            minDeque.pop_front();

        if (!maxDeque.empty() && maxDeque.front() == frontVal)
            maxDeque.pop_front();
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minDeque.front();
    }

    int getMax() {
        return maxDeque.front();
    }
};
