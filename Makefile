SRCS_cub3d = srcs/ft_cub3d.c srcs/ft_errors.c srcs/ft_check_file.c srcs/ft_read1.c \
srcs/ft_read2.c srcs/ft_init.c srcs/ft_keys.c srcs/ft_cast.c \
srcs/ft_wall.c srcs/ft_functions.c srcs/ft_player.c srcs/ft_texture.c srcs/ft_sprite.c \
srcs/ft_bmap.c srcs/ft_free.c srcs/ft_collision.c  srcs/ft_xpm.c \

SRCS_libft = libft/ft_strlen.c libft/ft_strncmp.c libft/ft_strlcpy.c \
libft/ft_isdigit.c libft/ft_putchar_fd.c libft/ft_strnstr.c libft/ft_atoi.c \
libft/ft_strdup.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_putstr_fd.c \
libft/get_next_line.c libft/ft_strjoin_free.c  libft/ft_strchr.c libft/ft_split.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_strtrim.c\

SRCS = ${SRCS_cub3d} ${SRCS_libft}

INCL = -Iincludes/

OBJS = ${SRCS:.c=.o}

NAME = cub3D

FLAGS = -Wall -Wextra -Werror -g

all : $(NAME)

$(NAME) : ${OBJS}
		gcc  ${FLAGS} -I/usr/local/include -o$(NAME) ${OBJS} -L/usr/local/lib -lmlx -framework Opengl -framework APPKIT
.c.o : ${SRCS}
		gcc ${FLAGS} -c ${INCL} $< -o ${<:.c=.o}
clean :
		rm -f ${OBJS}
fclean : clean
		rm -f $(NAME)
re : fclean
		make all
.PHONY: all clean fclean re
