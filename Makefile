CC = cc
CFLAGS = -Iinclude -Wall -Werror -Wextra

NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = 	server.c\
				utils_t.c\
				utils.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT = 	client.c\
				utils.c\
				utils_t.c

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)




SRCS_SERVER_BONUS = 	bonus/server_bonus.c\
						bonus/utils_t.c\
						bonus/utils.c

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

SRCS_CLIENT_BONUS = 	bonus/client_bonus.c\
						bonus/utils.c\
						bonus/utils_t.c

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)



all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	find . -name "*.o" -delete -print

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT_BONUS)

.PHONY: all clean fclean re bonus

