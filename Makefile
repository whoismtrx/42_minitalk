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

HEADER = minitalk.h

SRC = ft_putchar_fd.c ft_putnbr_fd.c ft_atoi.c ft_power.c ft_strlen.c ft_putstr_fd.c ft_hand_error.c

SRCS = server.c

SRCC = client.c

SRCSB = server_bonus.c

SRCCB = client_bonus.c

OBJ = $(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

OBJSB = $(SRCSB:.c=.o)

OBJCB = $(SRCCB:.c=.o)

all: $(NAMES) $(NAMEC)

$(NAMES): $(OBJ) $(OBJS)

$(NAMEC): $(OBJ) $(OBJC)

bonus : $(NAMESB) $(NAMECB)

$(NAMESB): $(OBJ) $(OBJSB)

$(NAMECB): $(OBJ) $(OBJCB)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OBJ) $(OBJS) $(OBJC) $(OBJSB) $(OBJCB)

fclean: clean
	rm -rf $(NAMES) $(NAMEC) $(NAMESB) $(NAMECB)

re:	fclean all
