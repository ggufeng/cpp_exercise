//#include <iostream>

//using namespace::std;

//size_t strlen(const char *str) {
//    const char *s;
//    for (s = str; *s; ++s) {
//    }
//    return (s - str);
//}

//int atoi(const char *str) {
//    if (str == nullptr) return 0;

//    const int len = strlen(str); // const int
//    int i = 0; // int
//    int sign = 1;
//    int num = 0;


//    while (str[i] == ' ' && i < len) { // i < len
//        i++;
//    }

//    if (str[i] == '+') {
//        i++;
//    }

//    if (str[i] == '-') {
//        sign = -1;
//        i++;
//    }

//    for (; i < len; ++i) {
//        if (str[i] == ' ')
//            continue;

//        if (str[i] < '0' || str[i] > '9')
//            break;

//        if ((num > INT_MAX / 10) || // INT_MAX, not MAX_INT
//        (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {//
//            return sign == -1 ? INT_MIN : INT_MAX; //
//        }

//        num = num * 10 + str[i] - '0';
//    }

//    return sign * num;

//}

//int main(int argc, char *argv[])
//{
//    char const *a = "-3924x8fc";
//    char const *b = " + 413";
//    char const *c = " ++c";
//    char const *d = " ++1";
//    char const *e = "2147483648";

//    cout << atoi(a) << endl;
//    cout << atoi(b) << endl;
//    cout << atoi(c) << endl;
//    cout << atoi(d) << endl;
//    cout << atoi(e) << endl;

//    return 0;
//}

