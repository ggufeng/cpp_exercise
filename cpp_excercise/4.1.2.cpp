#include <stack>
#include <cstdio>

using namespace::std;

void convert_base(int n, const int d) {
    stack<int> s;
    int e;

    while (n != 0) {
        e = n % d;
        s.push(e);
        n /= d;
    }

    while (!s.empty()) {
        e = s.top();
        s.pop();
        printf("%x", e);
    }
    return;
}


int main(int argc, char *argv[])
{
    convert_base(99, 4);
    return 0;
}

