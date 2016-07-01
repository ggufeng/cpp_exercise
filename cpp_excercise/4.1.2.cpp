//#include <stack>
//#include <cstdio>

//using namespace::std;

//void convert_base(int n, const int d) {
//    stack<int> s;
//    int e;

//    if (n == 0) {
//        printf("0\n");
//        return;
//    }

//    while (n != 0) {
//        e = n % d;
//        s.push(e);
//        n /= d;
//    }

//    while (!s.empty()) {
//        e = s.top();
//        s.pop();
//        printf("%x", e);
//    }
//    return;
//}

//const int MAXN = 64; // maximal length for stack
//int s[MAXN];
//int top = -1;
//// better than the first version
//void convert_base2(int n, const int d) {
//    int e;

//    if (n == 0) {
//        printf("0\n");
//        return;
//    }

//    while (n != 0) {
//        e = n % d;
//        s[++top] = e;
//        n /= d;
//    }

//    while (top >= 0) {
//        e = s[top--]; // note that top starts from -1
//        printf("%x", e);
//    }
//    return;
//}

//int restore(const char s[MAXN], const int d) {
//    int result = 0;
//    int one;

//    for (int i = 0; s[i] != '\0'; ++i) {
//        if (s[i] >= '0' && s[i] <= '9') one = s[i] - '0';
//        else if (s[i] >= 'A' && s[i] <= 'F') one = s[i] - 'A' + 10;
//        else one = s[i] - 'a' + 10; // (s[i] >= 'a' && s[i] <= 'f')

//        result = result * d + one;
//    }
//    return result;
//}

//int main(int argc, char *argv[])
//{
////    convert_base(0, 4);
////    convert_base2(99,4);
////    char s[10] = "12345B";
//    char *s = "12345b";
//    int res = restore(s, 13);
//    printf("%d", res);
//    return 0;
//}

