//#include <assert.h>
//#include <iostream>

//using namespace::std;

//char *strstr(const char *haystack, const char *needle){//
//    if (!*needle) return (char*)haystack;//(char*)

//    const char *p1;
//    const char *p2;
//    const char *p1_advance = haystack;

//    for (p2 = &needle[1]; *p2; ++p2) {// &, pos
//        p1_advance++;
//    }

//    for (p1 = haystack; *p1_advance; ++p1_advance) {
//        char *p1_old = (char*) p1;//(char*)
//        p2 = needle; //
//        while (*p1 && *p2 && *p1 == *p2) {//while, *p1 == *p2
//            p1++;
//            p2++;
//        }
//        if (!*p2) return p1_old;// !*p2, p1_old

//        p1 = p1_old + 1;
//    }

//    return  NULL;
//}

//int main(int argc, char *argv[])
//{
//    const char *a = "0test";
//    const char *b = "te";
//    cout << strstr(a, b) << endl;
//    return 0;
//}



