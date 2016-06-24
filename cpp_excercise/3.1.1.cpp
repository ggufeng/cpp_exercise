#include <iostream>

using namespace::std;

size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s) {
//        cout << s << " " << *s << endl;
    }
//    cout << s << " " << *s << endl;
    return (s - str);
}

int main(int argc, char *argv[])
{
    char *a = "0test";
    cout << strlen(a) << endl;
    return 0;
}

