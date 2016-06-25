//#include <assert.h>
//#include <iostream>

//using namespace::std;

//// http://stackoverflow.com/questions/5695992/implementing-a-string-copy-function-in-c
//// 1. n an interview, you could indeed point out the function isn't safe,
//// most notably the buffer on *dest isn't large enough. Also, there may
//// be overlap, i.e. if dest points to the middle of the src buffer, you'll
//// have endless loop (which will eventually creates memory access fault).
//// 2. priority: a++ > () > ++a > *a > &a
//// 3. a++ returns a
//char* strcpy(char *to, const char *from) {
//    assert(to != NULL && from != NULL);
//    char *p = to;
//    while ((*p++ = *from++) != '\0')
//    ;

////    while (*from != '\0') {
////        *p = *from;
////        ++p;
////        ++from;
////    }

//    return to;
//}

//int main(int argc, char *argv[])
//{
//    char *a = "0test";
//    char b[12];
//    strcpy(b, a);
//    cout << b << endl;
//    return 0;
//}


