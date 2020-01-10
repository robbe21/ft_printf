# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-ket <rvan-ket@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/25 13:40:40 by rvan-ket       #+#    #+#                 #
#    Updated: 2019/06/16 19:20:40 by rvan-ket      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/

SRCS = extra.c getargument_scp.c ft_itoa_.c getdata_flag_mod_w.c \
getargument_f.c getdata.c print.c print_f.c print_d.c print_p.c \
getargument_diouxx.c print_s.c print_c.c print_o.c putstr.c printf.c print_xx.c

OBJS := extra.o getargument_scp.o ft_itoa_.o getdata_flag_mod_w.o \
getargument_f.o getdata.o print.o print_f.o print_d.o print_p.o \
getargument_diouxx.o print_s.o print_c.o print_o.o putstr.o printf.o print_xx.o

all: $(NAME)

$(NAME):
	@echo "Creating $(NAME)..."
	@make -C $(LIBFT)
	@gcc $(CFLAGS) -c $(SRCS) -I .
	@ar rcs $(NAME) $(OBJS) ./libft/*.o

clean:
	@echo "Cleaning .o files"
	@rm -f $(OBJS)
	@echo "Cleaning .o files in libft"
	@make clean -C $(LIBFT)

fclean: clean
	@echo "Removing file"
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re: fclean all