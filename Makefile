CC = cc

CFLAGS = -Wall -Wextra -Werror

NAMES = server

NAMEC = client

HEADER = minitalk.h

SRC = ft_putchar_fd.c ft_putnbr_fd.c ft_atoi.c ft_power.c

SRCS = server.c

SRCC = client.c

OBJ = $(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

all: $(NAMES) $(NAMEC)

$(NAMES): $(OBJ) $(OBJS)

$(NAMEC): $(OBJ) $(OBJC)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -rf $(OBJ) $(OBJS) $(OBJC)

fclean: clean
	rm -rf $(NAMES) $(NAMEC)

re:	fclean all
