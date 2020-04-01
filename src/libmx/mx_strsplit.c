#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    
    if (s == 0) return 0;

    char **str = (char **)malloc(sizeof(char**) * 
                        mx_count_words(s,c) + 1);
    int iStartWord  = 0;
    int iEndWord    = 0;
    int iWord       = 0;

    while(s[iStartWord]) {
        while(s[iStartWord] == c)
            iStartWord++;
        iEndWord = iStartWord;
        while((s[iEndWord] != c) && (s[iEndWord] != 0))
            iEndWord++;
        if (iStartWord == iEndWord) break;
        str[iWord] = (char*) malloc (iEndWord - iStartWord + 1);
        mx_strncpy(str[iWord], &s[iStartWord],iEndWord - iStartWord);
        iWord++;
        iStartWord = iEndWord;
    }

    str[iWord] = 0;
    return str;
}
