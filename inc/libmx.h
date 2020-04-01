#ifndef LIBMX_H
#define LIBMX_H

#include <sys/types.h>
#include <stdlib.h>

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_strjoin2(char *s1, char *s2);
char *mx_strjoin3(char *s1, char *s2);
int mx_strlen (const char *s);
char *mx_strdup(const char *s1);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_count_words(const char *str, char c);
char **mx_strsplit(const char *s, char c);

#endif