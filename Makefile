# Variables
CC			= gcc-13 
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g

# Names
NAME		= so_long
LIBFT		= libft.a
MLX			= libmlx.a

# Includes & Links
INCLUDE		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I/usr/include -I$(MLX_DIR)
LINK		= -Llibft -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Folders
INCLUDE_DIR = include
SRC_DIR		= src
BUILD_DIR	= build
MLX_DIR		= mlx
LIBFT_DIR	= libft

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Files
SRCS		= $(wildcard $(SRC_DIR)/*.c)
# SRCS_BONUS	= $(SRC_DIR)/pipex_bonus.c $(SRC_DIR)/utils.c
SRCS_BONUS	=
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)
	@printf "$(GREEN)$@ compiled! $(DEF_COLOR)\n"

$(LIBFT):
	@printf "$(CYAN)Compiling libft... $< $(DEF_COLOR)\n"
	@make -C $(LIBFT_DIR) all

$(MLX):
	@printf "$(CYAN)Compiling minilibx... $< $(DEF_COLOR)\n"
	@make -C $(MLX_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@printf "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BUILD_DIR):
	@printf "$(MAGENTA)Build dir not found. Creating...$(DEF_COLOR)\n"
	@mkdir -p $(BUILD_DIR)
	
clean:
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf "$(GREEN)$(NAME) object files cleaned!$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)libft.a cleaned!$(DEF_COLOR)\n"
	@printf "$(GREEN)$(NAME) binaries cleaned!$(DEF_COLOR)\n"

re: fclean all
	@printf "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)\n"

# Phony
.PHONY: clean fclean bonus re all
