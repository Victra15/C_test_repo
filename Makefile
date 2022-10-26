NAME = test

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFTFLAGS = -Llibft -lft
SRCS = test.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) bonus -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTFLAGS) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -Ilibft -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 

.PHONY : all clean fclean re