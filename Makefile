AR := ar rcs
NAME = minishell
CC = cc
RM = rm -rf
READLINE_INC := -iquote /Users/$(USER)/goinfre/.brew/opt/readline/include
READLINE_LIB := -L/Users/$(USER)/goinfre/.brew/opt/readline/lib
CFLAGS = $(READLINE_INC) -Wall -Wextra -Werror


SRC := src/
INPUT := input/
CHILDREN := children/
BUILTIN := builtin/
UTILS := utils/


# INPUT
INPUTCFILES := input_read.c input_parse.c dredir_in.c dredir_out.c redir_in.c redir_out.c set_cmds.c \
				input_add_spaces.c set_vars.c input_rem_quotes.c input_expand_rem_redir.c set_files.c set_vars_here_doc.c
INPUTCFILES := $(addprefix $(INPUT), $(INPUTCFILES))
INPUTCFILES := $(addprefix $(SRC), $(INPUTCFILES))

# CHILDREN
CHILDRENCFILES := children_exec.c child_exec.c limiter_exec.c child_where.c child_exec_utils.c children_exec_utils.c
CHILDRENCFILES := $(addprefix $(CHILDREN), $(CHILDRENCFILES))
CHILDRENCFILES := $(addprefix $(SRC), $(CHILDRENCFILES))

# BUILTIN
BUILTINCFILES := builtin_exec.c builtin_is_cmd.c builtin_echo.c builtin_cd.c builtin_pwd.c builtin_export.c \
				builtin_env.c builtin_unset.c builtin_exit.c
BUILTINCFILES := $(addprefix $(BUILTIN), $(BUILTINCFILES))
BUILTINCFILES := $(addprefix $(SRC), $(BUILTINCFILES))

# UTILS
UTILSCFILES := utils_env.c utils_dllist.c utils_llist.c open_files.c utils_free.c utils_redirs.c split_mod.c utils_split_mod.c
UTILSCFILES := $(addprefix $(UTILS), $(UTILSCFILES))
UTILSCFILES := $(addprefix $(SRC), $(UTILSCFILES))

# SPEC
CFILES := set_to_default.c
CFILES := $(addprefix $(SRC), $(CFILES))

# ALL
CFILES := $(CFILES) $(INPUTCFILES) $(CHILDRENCFILES) $(BUILTINCFILES) $(UTILSCFILES) minishell.c
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	make -C libs
	$(CC) $(CFLAGS) $(OFILES) $(READLINE_LIB) libs/libs.a -lreadline -o $(NAME)

clean: 
	$(RM) $(OFILES)
	make clean -C libs

fclean: clean
	$(RM) $(NAME)
	make fclean -C libs

re: fclean all

