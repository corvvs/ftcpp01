CXX			:=	clang++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 --pedantic
NAME		:=	replace
SRCS		:=	main.cpp
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

TESTFILE_UNREADABLE	:= 	unreadable.txt
TESTFILE_UNWRITABLE	:= 	unwritable.txt
TESTFILE_DIR		:= 	dir.txt
TESTFILE_DIR_REPL	:= 	Makefile.replace

$(TESTFILE_UNREADABLE)	:
	echo hello > $(TESTFILE_UNREADABLE)
	chmod a-r $(TESTFILE_UNREADABLE)

$(TESTFILE_UNWRITABLE)	:
	echo hello > $(TESTFILE_UNWRITABLE)
	chmod a-w $(TESTFILE_UNWRITABLE)

$(TESTFILE_DIR)			:
	mkdir $(TESTFILE_DIR)

$(TESTFILE_DIR_REPL)	:
	mkdir $(TESTFILE_DIR_REPL)

.PHONY		:	runtest

errortest	: $(NAME) $(TESTFILE_UNREADABLE) $(TESTFILE_UNWRITABLE) $(TESTFILE_DIR) $(TESTFILE_DIR_REPL)
	@@echo "[unexisting file]"
	! ./$(NAME) NOSUCHFILE a b
	@@echo
	@@echo "[unreadable file]"
	! ./$(NAME) $(TESTFILE_UNREADABLE) e b
	@@echo
	@@echo "[unwritable file]"
	./$(NAME) $(TESTFILE_UNWRITABLE) e b
	cat $(TESTFILE_UNWRITABLE).replace
	@@echo
	@@echo "[from directory]"
	! ./$(NAME) $(TESTFILE_DIR) a b
	@@echo
	@@echo "[to directory]"
	! ./$(NAME) Makefile a b
	@@echo
