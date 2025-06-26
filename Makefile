# Variables
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g

# Names
NAME		= so_long
NAME_BONUS	= so_long_bonus
LIBFT		= libft.a
MLX			= libmlx.a

# Includes & Links
INCLUDE		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include -I/usr/include -I$(MLX_DIR)
LINK		= -Llibft -lft -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

# Folders
INCLUDE_DIR		= include
SRC_DIR			= src
MANDATORY_DIR	= mandatory
BONUS_DIR		= bonus
BUILD_DIR		= build
MLX_DIR			= mlx
LIBFT_DIR		= libft

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
SRCS		= $(wildcard $(SRC_DIR)/$(MANDATORY_DIR)/*.c)
SRCS_BONUS	= $(wildcard $(SRC_DIR)/$(BONUS_DIR)/*.c)
OBJS		= $(SRCS:$(SRC_DIR)/$(MANDATORY_DIR)/%.c=$(BUILD_DIR)/$(MANDATORY_DIR)/%.o)
OBJS_BONUS	= $(SRCS_BONUS:$(SRC_DIR)/$(BONUS_DIR)/%.c=$(BUILD_DIR)/$(BONUS_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX) 
	@$(CC) $(CFLAGS) $(OBJS) $(LINK) -o $(NAME)
	@printf "$(GREEN)$@ compiled! $(DEF_COLOR)\n"

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LINK) -o $(NAME_BONUS)
	@printf "$(GREEN)$@ compiled! $(DEF_COLOR)\n"

$(LIBFT):
	@printf "$(CYAN)Compiling libft... $< $(DEF_COLOR)\n"
	@make -C $(LIBFT_DIR) all

$(MLX):
	@printf "$(CYAN)Compiling minilibx... $< $(DEF_COLOR)\n"
	@make -C $(MLX_DIR)

$(BUILD_DIR)/$(MANDATORY_DIR)/%.o: $(SRC_DIR)/$(MANDATORY_DIR)/%.c $(INCLUDE_DIR)/so_long.h | $(BUILD_DIR)/$(MANDATORY_DIR)
	@printf "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/$(BONUS_DIR)/%.o: $(SRC_DIR)/$(BONUS_DIR)/%.c $(INCLUDE_DIR)/so_long_bonus.h | $(BUILD_DIR)/$(BONUS_DIR)
	@printf "$(YELLOW)Compiling: $< $(DEF_COLOR)\n"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BUILD_DIR)/$(MANDATORY_DIR):
	@printf "$(MAGENTA)Build dir not found. Creating...$(DEF_COLOR)\n"
	@mkdir -p $@

$(BUILD_DIR)/$(BONUS_DIR):
	@printf "$(MAGENTA)Build dir not found. Creating...$(DEF_COLOR)\n"
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@printf "$(GREEN)$(NAME) object files cleaned!$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean
	@printf "$(GREEN)libft.a cleaned!$(DEF_COLOR)\n"
	@printf "$(GREEN)$(NAME) binaries cleaned!$(DEF_COLOR)\n"

re: fclean all
	@printf "$(GREEN)Cleaned and rebuilt!$(DEF_COLOR)\n"

# Phony
.PHONY: clean fclean bonus re all
