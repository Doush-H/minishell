AR := ar rcs
CFLAGS = -Wall -Wextra -Werror

NAME = libs.a

LIBFT := libft
PRINTF := printf
GNL := get_next_line

# LIBFT
LIBFTCFILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c   \
		    ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c ft_lstadd_front.c       \
		    ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c           \
		    ft_lstnew.c ft_lstsize.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c    \
		    ft_memset.c ft_ptrlen.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c       \
		    ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c              \
		    ft_strjoin_free.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c         \
		    ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c             \
		    ft_substr.c ft_tolower.c ft_toupper.c ft_atoi_l.c ft_protect.c               \
			ft_free_split.c ft_fileexists.c ft_strdup_i.c
LIBFTCFILES := $(addprefix $(LIBFT)/, $(LIBFTCFILES))

# PRINTF
PRINTFCFILES = functions/ft_printChar.c functions/ft_printf.c functions/ft_printNumber.c \
		       functions/ft_itoa_u_int.c  functions/ft_putnbr_base_u.c                   \
			   functions/ft_putnbr_base_u_long.c
PRINTFCFILES := $(addprefix $(PRINTF)/, $(PRINTFCFILES))

# GNL
GNLCFILES := get_next_line.c get_next_line_utils.c
GNLCFILES := $(addprefix $(GNL)/, $(GNLCFILES))

# LIBS
CFILES := $(LIBFTCFILES) $(PRINTFCFILES) $(GNLCFILES)
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(AR) $(NAME) $(OFILES)

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

