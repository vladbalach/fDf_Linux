char *mx_strncpy(char *dst, const char *src, int len) {
    char isNULL = 0;
    for (int i = 0; i < len; i ++) {
        if (src[i] == 0) isNULL =1;
        if (isNULL == 0) {
            dst[i] = src[i];
        }
        else {
            dst[i] = 0;
        }
    }
    dst[len] = 0;
    return dst;
}