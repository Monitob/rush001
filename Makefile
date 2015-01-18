CXX		= g++
RM		= rm -rf
NAME	= ft_gkrellm
HEADER	= ./inc/
SRCDIR	= ./src/
OBJDIR	= ./obj/
CFLAGS	= -lncurses -I ~/.brew/Cellar/sdl2/2.0.3/include -L ~/.brew/Cellar/sdl2/2.0.3/lib -lSDL2 -Wall -Wextra -Werror -I$(HEADER)
SRC			= $(SRCDIR)main.cpp gkrellm.class.cpp Module.class.cpp Get_clock.class.cpp GraphicDisplay.class.cpp TerminalDisplay.class.cpp ramModule.class.cpp CpuModule.class.cpp CpuModuleIndicator.class.cpp 
OBJ			= $(addprefix $(OBJDIR),$(notdir $(SRC:.cpp=.o)))

all:			$(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

$(NAME):	$(OBJ)
	@$(CXX) -o $(NAME) -lncurses -I ~/.brew/Cellar/sdl2/2.0.3/include -L ~/.brew/Cellar/sdl2/2.0.3/lib -lSDL2 $(OBJ)
	@echo "Linking complete!"

clean:
	@$(RM) $(OBJ)
	@echo "Objects removed successfully"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed successfully"

re: fclean all

.PHONY: all clean fclean re
