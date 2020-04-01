int mx_count_words(const char *str, char c) {
    int i = 0;
    int count = 0;
    if (str == 0) return -1;
    while (str[i]) {
        while (str[i] == c) {
            i++;
            if (str[i] == 0) return count;
        }
        count++;
        while (str[i] != c) {
            i++;
            if (str[i] == 0) return count;
        }
    }
    return count;
}