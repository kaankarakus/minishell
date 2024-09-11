NAME = minishell
OBJ_DIR = build
SRC_DIR = src
CC = gcc
M_SRC = $(SRC_DIR)/meta.c $(SRC_DIR)/quote.c $(SRC_DIR)/separator.c $(SRC_DIR)/token.c \
	$(SRC_DIR)/token_add.c $(SRC_DIR)/token_append.c $(SRC_DIR)/token_append_util.c $(SRC_DIR)/token_util.c \
	$(SRC_DIR)/util.c $(SRC_DIR)/dollar.c $(SRC_DIR)/dollar_util.c $(SRC_DIR)/dollar_handle.c \
	$(SRC_DIR)/assign_token_types.c $(SRC_DIR)/lexer.c $(SRC_DIR)/exec.c $(SRC_DIR)/path.c \
	$(SRC_DIR)/ft_split.c $(SRC_DIR)/echo.c $(SRC_DIR)/env_util.c $(SRC_DIR)/export.c  $(SRC_DIR)/exit.c \
	$(SRC_DIR)/built_in.c $(SRC_DIR)/cd.c $(SRC_DIR)/syntax_check_util.c $(SRC_DIR)/syntax_check.c \
	$(SRC_DIR)/signal.c $(SRC_DIR)/dispose.c $(SRC_DIR)/print_util.c $(SRC_DIR)/token_util2.c\
	$(SRC_DIR)/util2.c $(SRC_DIR)/util3.c $(SRC_DIR)/quote_util.c $(SRC_DIR)/exec_single_cmd.c $(SRC_DIR)/pwd.c \
	$(SRC_DIR)/env.c $(SRC_DIR)/exec_utils.c $(SRC_DIR)/built_in_utils.c $(SRC_DIR)/error.c cmd/minishell.c \
	$(SRC_DIR)/unset.c $(SRC_DIR)/redirect.c $(SRC_DIR)/redirect2.c $(SRC_DIR)/fork.c $(SRC_DIR)/exec_multi_cmd.c

INC_DIR = -I./inc -I./lib/readline/include
CFLAGS = -g -Wall -Wextra -Werror $(INC_DIR)
SRC = $(M_SRC)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
READLINE = -L./lib/readline/lib -I./lib/readline/include/readline -lreadline 
DIR = $(shell echo $(PWD))
RM = rm -rf
RL = ./lib/readline/lib/libreadline.a

all: $(NAME)

$(NAME): $(RL) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(READLINE) $(INC_DIR)
	@echo "Minishell compiled"

$(RL):
	@echo "Downloading readline"
	@curl -O https://ftp.gnu.org/gnu/readline/readline-8.2-rc1.tar.gz
	@tar -xvf readline-8.2-rc1.tar.gz
	@$(RM) readline-8.2-rc1.tar.gz
	@cd readline-8.2-rc1 && ./configure --prefix=$(DIR)/lib/readline && make && make install
	@$(RM) readline-8.2-rc1
	@echo "Readline installed"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

RLclean:
	@$(RM) lib/readline
	@echo "Readline removed"

clean:
	@$(RM) $(OBJ_DIR)/*.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all
