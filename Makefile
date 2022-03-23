NAME1 = server
NAME2 = client

FLAGS = -Wall -Werror -Wextra


all :
		cd ft_printf && make all
		gcc $(FLAGS) server.c minitalk_utils.c ft_printf/libftprintf.a -o $(NAME1)
		gcc $(FLAGS) client.c minitalk_utils.c ft_printf/libftprintf.a -o $(NAME2)

clean :
		cd ft_printf && make clean

fclean : clean
		rm -rf $(NAME1) $(NAME2)

re : fclean all

.PHONY : all clean fclean re