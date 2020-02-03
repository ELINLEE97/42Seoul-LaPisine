AR = ar
ARFLAGS = crv
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

INCLUDES_DIR = ./includes
INCLUDES = ft.h

SRCS_DIR = ./srcs
OBJS = ft_putchar.o \
	   ft_swap.o \
	   ft_putstr.o \
	   ft_strlen.o \
	   ft_strcmp.o
SRCS = $(OBJS:.o=.c)

all : $(TARGET)

clean : 
	rm -f $(OBJS)

fclean : 
	rm -f $(TARGET)

re : fclean all

$(TARGET) : $(addprefix $(INCLUDES_DIR)/, $(INCLUDES)) $(addprefix $(SRCS_DIR)/, $(OBJS))
	$(AR) $(ARFLAGS) $@ $^
