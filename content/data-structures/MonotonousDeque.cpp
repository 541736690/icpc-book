/**
 * Author: 
 * Date: 
 * License: 
 * Source: 
 * Description: Monotonous Interval Min Queries
 */
struct MonQueue {
    deque<P> que;

    void clear() {
        que.clear();
    }
    void add(P p) {
        while(!que.empty() && que.back().first >= p.first) que.pop_back();
        que.push_back(p);
    }

    int get(int l, int r) {
        while(!que.empty() && (que.front().second < l || que.front().second > r)) que.pop_front();
        return que.empty() ? -INF : que.front().first;
    }
} cque;