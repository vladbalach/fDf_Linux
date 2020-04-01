#include "header.h"
#include "libmx.h"

static t_vector* create_vector(float x, float y, float z) {
    t_vector *vector = malloc(sizeof(t_vector));
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}

static void add_object(t_list **objects, int X, int Y, int Z) {
    t_object *obj = malloc(sizeof(t_object));
    obj->vectors = malloc(sizeof(t_vector*) * 4);
    obj->size = 4;
    obj->vectors[0] = create_vector(X * BLOCKSIZE, Y * BLOCKSIZE, Z * BLOCKSIZE);
    obj->vectors[1] = create_vector((X + 1) * BLOCKSIZE,Y * BLOCKSIZE, Z * BLOCKSIZE);
    obj->vectors[2] = create_vector((X + 1) * BLOCKSIZE,(Y + 1) * BLOCKSIZE, Z * BLOCKSIZE);
    obj->vectors[3] = create_vector(X * BLOCKSIZE, (Y + 1) * BLOCKSIZE, Z * BLOCKSIZE);
    mx_push_top(objects, obj);
}

static void add_line(t_list **objects, char *line, int row, int *w) {
    char **strs = mx_strsplit(line, ' ');
    int i = -1;

    while (strs[++i]) {
        int z = atoi(strs[i]);
        add_object(objects, i, row, z);
    }
    *w = i;
}

void add_objects(t_list **objects, int fd, int *w, int *h) {
    char *line = 0;
    int count  = 1;
    int row = 0;

    while (count) {
    count = mx_read_line(&line, 1000, '\n', fd);
    if (count == 0) {
        *h = row;
        return;
    }
    add_line(objects, line, row, w);
    row++;
    }
    *h = row;
}

t_list *mx_get_index(t_list **list, int index) {
    t_list *tmp = *list;
    int i = -1;

    if (index < 0) 
        return 0;
    while (tmp) {
        if (++i == index)
            return tmp;
        tmp = tmp->next;
    }
    return 0;
}

void fill_list(t_list **objects, int w, int h) {
    t_list *tmp = *objects;
    printf("w = %d\nh = %d\n", w, h );
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (i < h - 1) 
               tmp->up = mx_get_index(objects, (i + 1) * w + j);
            if (i > 0)
                tmp->down = mx_get_index(objects, (i - 1) * w + j);
            if (j < w - 1) 
               tmp->left = mx_get_index(objects, i * w + j + 1);
            if (j > 0)
                tmp->right = mx_get_index(objects, i * w + j - 1);
            tmp = tmp->next;
        }
    }   
}

void init_objects(t_list **objects, char *filename) {
    int w = 0;
    int h = 0;
    int fd = open(filename, O_RDONLY);

    *objects = 0;
    if (fd == -1) 
        fprintf(stderr, "open error: %s\n", strerror(errno));
    add_objects(objects, fd, &w, &h);
    close(fd);
    fill_list(objects, w, h);
}
