CXX			:=	clang++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98
NAME		:=	karen
SRCS		:=	main.cpp Karen.cpp
OBJS		:=	$(SRCS:.cpp=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)
$(NAME)		:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean		:
	$(RM) -rf $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all
