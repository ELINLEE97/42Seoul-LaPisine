CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

SRC_DIR = ./srcs/
SRCS = ft_main.c \
	   dict_parser.c \
	   dict.c \
	   dict_list.c \
	   hash.c \
	   ft_string.c \
	   read_file.c \
	   file_to_hash.c
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))


.c.o :
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all
