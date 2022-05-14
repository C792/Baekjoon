//7662 : 이중 우선순위 큐
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void sync_max_heap(bool valid[], priority_queue<pair<int, int>>& max_heap) {
    while (!max_heap.empty() && !valid[max_heap.top().second]) {
        max_heap.pop();
    }
    return;
}

void sync_min_heap(bool valid[], priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_heap) {
    while (!min_heap.empty() && !valid[min_heap.top().second]) {
        min_heap.pop();
    }
    return;
}

void make_pq(int quest, priority_queue<pair<int, int>>& max_heap, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_heap) {
    bool valid[1000001]{};
    char order; int num = 0;

    for (int q = 0; q < quest; q++) {
        scanf("%c %d", &order, &num);
        switch (order) {
        case 'I':
            min_heap.push(make_pair(num, q));
            max_heap.push(make_pair(num, q));
            valid[q] = true;
            break;
        case 'D':
            if (num > 0) {
                sync_max_heap(valid, max_heap);
                if (!max_heap.empty()) {
                    valid[max_heap.top().second] = false;
                    max_heap.pop();
                }
            }
            else {
                sync_min_heap(valid, min_heap);
                if (!min_heap.empty()) {
                    valid[min_heap.top().second] = false;
                    min_heap.pop();
                }
            }
            break;
        default:
            q--;
            break;
        }
    }

    sync_min_heap(valid, min_heap);
    sync_max_heap(valid, max_heap);

    return;
}

void print_result(priority_queue<pair<int, int>>& max_heap, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& min_heap) {
    if (max_heap.empty()) {
        printf("EMPTY\n");
    }
    else {
        printf("%d %d\n", max_heap.top().first, min_heap.top().first);
    }
    return;
}

int main() {
    int testcase = 0;
    scanf("%d", &testcase);

    while (testcase--) {
        int quest = 0;
        priority_queue<pair<int, int>> max_heap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        scanf("%d", &quest);

        make_pq(quest, max_heap, min_heap);
        print_result(max_heap, min_heap);
    }

    return 0;
}