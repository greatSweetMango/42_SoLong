NAME		= so_long.out

LIBFT		= libft
MLX			= mlx

LIBS		= libs

INCLUDE    	= include
INCLUDE_BN	= include_bonus

MANDATORYDIR= mandatory/
BONUSDIR	= bonus/

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
FWS			= -framework OpenGL -framework AppKit
RM			= rm -rf
AR			= ar rcs

FILES 		= main.c \
				init_game.c \
				parse_map.c \
				get_next_line.c \
				get_next_line_utils.c \
				push_keys.c \
				update.c \
				draw_screen.c \
				draw_clear_screen.c \
				map_check.c \
				task_error.c \
				push_keys_utils.c

FILES_BN	= main_bonus.c \
				init_game_bonus.c \
				parse_map_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				push_keys_bonus.c \
				update_bonus.c \
				draw_screen_bonus.c \
				draw_clear_screen_bonus.c \
				map_check_bonus.c \
				task_error_bonus.c \
				push_keys_utils_bonus.c

SRCS		= $(addprefix $(MANDATORYDIR), $(FILES))
SRCS_BN		= $(addprefix $(BONUSDIR), $(FILES_BN))

OBJS		= $(SRCS:.c=.o)
OBJS_BN		= $(SRCS_BN:.c=.o)

$(MANDATORYDIR)%.o: $(MANDATORYDIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

$(BONUSDIR)%.o: $(BONUSDIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE_BN)

all		: $(NAME)

bonus	: $(NAME)

ifeq ($(MAKECMDGOALS), bonus)
$(NAME) : $(OBJS_BN)
			make bonus -C $(LIBFT)
			make -C $(MLX)
			cp libft/libft.a $(LIBS)
			cp mlx/libmlx.a $(LIBS)
			$(CC) $(CFLAGS) $(OBJS_BN) -o $(NAME) -L$(LIBS) -lmlx -lft -framework OpenGL -framework AppKit
else
$(NAME) : $(OBJS)
			make bonus -C $(LIBFT)
			make -C $(MLX)
			cp libft/libft.a $(LIBS)
			cp mlx/libmlx.a $(LIBS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBS) -lmlx -lft -framework OpenGL -framework AppKit
endif

clean	:
			$(RM) $(OBJS) $(OBJS_BN)
			make clean -C $(LIBFT)
			make clean -C $(MLX)

fclean	: clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)/libft.a
			$(RM) $(MLX)/libmlx.a
			$(RM) $(LIBS)/*

re		: fclean all

rebn	: fclean
			$(MAKE) bonus

.PHONY:		all clean fclean re rebn