#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
/* will return char pointer to substring */
const char* substr(const char* needle, const char* haystack) {
    int needle_n = strlen(needle), current_state = 0, i;
    for (i = 0; haystack[i] != 0; i++) {
        (needle[current_state] == haystack[i]) ? current_state++ : current_state = 0;
        if (current_state == needle_n) return haystack+(i-needle_n+1);
    }
    return 0;
}

int main(int argc, char**argv) {
    (argv[1]&&argv[2]) ? std::cout<<substr(argv[1],argv[2])<<std::endl:std::cout<<"error"<<std::endl;
    return 0;
}
