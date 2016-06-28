//#include <queue>
//#include <stdio.h>

//using namespace::std;

//void yanghui_triangle(const int n) {
//    queue<int> q;
//    // put 1 into the first line
//    q.push(1);

//    for (int i = 0; i <= n; ++i) { // process per line
//        int s = 0;
//        // insert a 0 btw each line
//        q.push(s);

//        // process i+2 factors pro line
//        for (int j = 0; j < i + 2; ++j) {
//            int t;
//            int tmp;
//            t = q.front(); // read a factor, put it into t
//            q.pop();
//            // cal the factors for the next line, and put it into the queue
//            tmp = s + t;
//            q.push(tmp);
//            s = t;
//            // print a factor, the (i+2)th factor is 0
//            if (j != i + 1) {
//                printf("%d ", s);
//            }
//        }
//        printf("\n");
//    }

//}





//int main(int argc, char *argv[])
//{
//    yanghui_triangle(29);
//    return 0;
//}

