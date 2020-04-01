SRC = ./src/main.c \
	./src/draw_line.c \
	./src/fill_circle.c \
	./src/mx_create_node.c \
	./src/mx_pop_index.c \
	./src/mx_push_top.c \
	src/libmx/mx_read_line.c \
	src/libmx/mx_strjoin.c \
	src/libmx/mx_strjoin2.c \
	src/libmx/mx_strjoin3.c \
	src/libmx/mx_strnew.c \
	src/libmx/mx_strlen.c \
	src/libmx/mx_strdup.c \
	src/libmx/mx_strcpy.c \
	src/init.c \
	src/init_objects.c \
	src/libmx/mx_count_words.c \
	src/libmx/mx_strsplit.c \
	src/libmx/mx_strncpy.c \
	src/event_loop.c \
	src/update_basis.c \
	src/update.c \
	src/draw.c \
	
all:
	clang  $(SRC) -w -lpthread -lSDL2 -lm -I inc -o sdl