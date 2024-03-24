# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orekabe <orekabe@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 02:53:57 by orekabe           #+#    #+#              #
#    Updated: 2022/05/22 04:47:58 by orekabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAMES = server

NAMEC = client

NAMESB = server_bonus

NAMECB = client_bonus

HEADER = -I./include

SRCD = ./src

OBJD = ./objs

SRC = $(SRCD)/ft_putchar_fd.c $(SRCD)/ft_putnbr_fd.c $(SRCD)/ft_atoi.c $(SRCD)/ft_power.c $(SRCD)/ft_strlen.c $(SRCD)/ft_putstr_fd.c $(SRCD)/ft_hand_error.c

SRCS = $(SRCD)/server.c

SRCC = $(SRCD)/client.c

SRCSB = $(SRCD)/server_bonus.c

SRCCB = $(SRCD)/client_bonus.c

OBJ = $(addprefix $(OBJD)/, $(notdir $(SRC:.c=.o)))

OBJS = $(addprefix $(OBJD)/, $(notdir $(SRCS:.c=.o)))

OBJC = $(addprefix $(OBJD)/, $(notdir $(SRCC:.c=.o)))

OBJSB = $(addprefix $(OBJD)/, $(notdir $(SRCSB:.c=.o)))

OBJCB = $(addprefix $(OBJD)/, $(notdir $(SRCCB:.c=.o)))

all: $(NAMES) $(NAMEC)

$(NAMES): $(OBJ) $(OBJS)
	@printf "                                               \r"
	@echo "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "                   		BY: MTRX"
	@$(CC) $(OBJ) $(OBJS) -o $@

$(NAMEC): $(OBJ) $(OBJC)
	@$(CC) $(OBJ) $(OBJC) -o $@

$(NAMESB): $(OBJ) $(OBJSB)
	@printf "                                               \r"
	@echo "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "                   		BY: MTRX"
	@$(CC) $(OBJ) $(OBJSB) -o $@

$(NAMECB): $(OBJ) $(OBJCB)
	@$(CC) $(OBJ) $(OBJCB) -o $@

$(OBJD)/%.o: $(SRCD)/%.c
	@mkdir -p $(OBJD)
	@printf "                                               \r"
	@printf "Compiling $<\r"
	@$(CC) -c $(CFLAGS) $(HEADER) $< -o $@

bonus : $(NAMESB) $(NAMECB)

clean:
	rm -rf $(OBJD)

fclean: clean
	rm -rf $(NAMES) $(NAMEC) $(NAMESB) $(NAMECB)

re:	fclean all
