#include <string.h>
#include <iostream>

class String {
    char* str;
    int len;

    public:
        String(char c, int n);
        String(const char* s);
        String(const String& s);
        ~String();

        void add_string(const String& s);
        void copy_string(const String& s);
        void show_string();
        int strlen();
};

String::String(char c, int n){
    str = new char[n+1];
    len = n;
    for (int i = 0; i<n; i++) {
        str[i] = c;
    }
}
String::String(const char* s) {
    len = 0;
    while(1) {
        if (!s[len]){
            break;
        }
        len++;
    }
    str = new char[len + 1];
    strcpy(str, s);
}
String::String(const String& s) {
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}
String::~String() {
    std::cout << "destructor : " << str << std::endl;
    if (str) {
        std::cout << "deleting" << std::endl;
        delete[] str;
    }
}

int String::strlen() {
    return len;
}
void String::add_string(const String& s) {
    char* str2 = new char[len + s.len + 1];
    for (int i = 0; i< len; i++) {
        str2[i] = str[i];
        str2[len + i] = s.str[i];
    }
    str = str2;
    len += s.len;
}
void String::copy_string(const String& s) {
    str = s.str;
    len = s.len;
}
void String::show_string() {
    std::cout << str << std::endl;
    std::cout << len << std::endl;
}

int main() {
    String str1('c',5);
    str1.show_string();

    String str2("abcd");
    str2.show_string();

    String str3(str2);
    str3.show_string();

    std::cout << "*** adding str2 to str1 ***" << std::endl;
    str1.add_string(str2);
    str1.show_string();

    std::cout << "*** copying str1 to str2" << std::endl;
    str2.copy_string(str1);
    str2.show_string();

    return 0;
}