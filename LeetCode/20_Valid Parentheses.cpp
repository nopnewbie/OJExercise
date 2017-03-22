#include <iostream>
#include <vector>
using namespace std;

bool isValid(char* s) {
    const int len = strlen(s);
    if (NULL == s || !len)
        return true;
    char *stack = (char*)malloc(len * sizeof(char));
    int top = -1;
    while (*s != '\0')
    {
        if (top < 0 || stack[top] != *s)
            stack[++top] = *s;
        else if (stack[top] == *s)
            --top;
        ++s;
    }
    return -1 == top;
}

int main()
{
    char s[] = "()";
    cout << isValid(s) << endl;
    return 0;
}