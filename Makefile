NAME				=	lem-in

CC 					=	gcc
CC_FLAGS			=	-Wall -Werror -Wextra

SRC_PATH			=	./srcs/
INC_PATH			=	./includes/ $(LIBFTPRINTF_PATH)includes/ $(LIBFT_PATH)includes/
OBJ_PATH			=	./obj/
LIBFTPRINTF_PATH	=	./libftprintf/
LIBFT_PATH 			=	$(LIBFTPRINTF_PATH)/libft/
RD_PATH				=	$(SRC_PATH)readdata/

OBJ					=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC					=	$(addprefix -I, $(INC_PATH))

OBJ_NAME			=	$(SRC_NAME:.c=.o)

OBJ_NAME			+=	$(RD_NAME:.c=.o)

SRC_NAME			=	lem_in.c 					\
						force_quit.c 				\
						get_room_by_id.c 			\
						get_room_by_name.c 			\
						find_way.c 					\
						calculate_matrix.c 			\
						check_connectivity.c 		\
						is_acyclic.c 				\
						move_ants.c					\
						elementary_solution.c		\
						build_path.c				\
						close_room.c				\
						open_room.c

RD_NAME				=	readdata.c 					\
						validate_link.c 			\
						parse_link.c 				\
						validate_room.c 			\
						parse_room.c				\
						add_line_to_output.c		\
						build_adjacency_matrix.c	\
						set_ants.c					\
						print_move.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFTPRINTF_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFTPRINTF_PATH)libftprintf.a
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(RD_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) -o $@ -c $< $(INC)
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFTPRINTF_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove [ $(NAME) ]..."

re: fclean all