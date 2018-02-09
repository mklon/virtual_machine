
NAME = avm

SOURCE =    src/main.cpp \
            src/Lexer.class.cpp \
            src/analyse.cpp \
            src/lexeme.cpp \

OBJECTS = $(SOURCE:.cpp=.o)

CC = clang++

all: $(NAME) done

$(NAME): $(OBJECTS)
	@$(CC) $(FL) $(SOURCE) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FL) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@echo "\033[;33m[ It's clean ]\033[33;0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[;31m[ Deleted ]\033[33;0m"

re: fclean all

done:
	@echo "\033[;32m[ Well done ]\033[33;0m"