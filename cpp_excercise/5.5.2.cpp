#include <cstdio>
#include <queue>
#include <algorithm>

//@f to be read
const int MAXN = 100000;

int N;
int a[MAXN], b[MAXN];

typedef struct node_t {
    int sum;
    int b;
    bool operator>(const node_t &other) const {
        return sum > other.sum;
    }
} node_t;

void k_merge() {
    sort(a, a + N);
    sort(b, b + N);
    priority_queue<node_t, vector<node_t>,
            greater<node_t> > q;

    for (int i = 0; i < N; ++i) {
        node_t tmp;
        tmp.sum = a[i] + b[0];
        tmp.b = 0;
        q.push(tmp);
    }

    for (int i = 0; i < N; ++i) {
        node_t tmp= q.top();
        q.pop();
        printf("%d ", tmp.sum);
        tmp.sum = tmp.sum - b[tmp.b] + b[tmp.b + 1];
        tmp.b ++;
        q.push(tmp);
    }

    return;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    k_merge();
    return 0;
}

