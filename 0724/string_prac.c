#include<stdio.h>

int my_strlen(char* s) {
    int len = 0;
    while(*s) {
        len++;
        s++;
    }
    return len;
}

char* my_strcat(char *s1, char *s2) {
    int len1 = my_strlen(s1);
    int len2  = my_strlen(s2);

    s1 += len1;

    for(int i=0; i<len2; i++) {
        *s1 = *s2;
        s1++;
        s2++;
    }

    s1 -= (len1+len2);
    
    return s1;
}

void my_strcpy(char* s1, char* s2) {
    int len2 = my_strlen(s2);

    for(int i=0; i<len2; i++) {
        *(s1+i) = *(s2+i);
    }
    *(s1+len2) = 0;
}

//equal = 0, not 1
int my_strcmp(char* s1, char* s2) {
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if(len1 != len2)
        return 0;

    for(int i=0; i<len1; i++) {
        if(*(s1+i) != *(s2+i))
            return 0;
    }

    return 1;
}

int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    int a;

    printf("%d\n", my_strlen(str1));

    printf("%s\n", my_strcat(str1, str2));
    
    printf("%s\n", str1);
    
    my_strcpy(str1, str2);
    
    printf("%s\n", str1);
    
    printf("%d\n", my_strcmp(str1, str2));

    scanf("%d", &a);
    
    return 0;
}
