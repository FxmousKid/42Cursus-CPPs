# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 10:50:11 by inazaria          #+#    #+#              #
#    Updated: 2025/02/28 12:55:09 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>
SRC_DIR 	= ./src/

BUILD_DIR 	= ./build/

INC_DIR 	= ./includes/

DEBUG_FILE_PATH = ./src/error_manager/debugging_functions
DEBUG_BUILD_PATH = ./build/error_manager/debugging_functions

# .c files for source code
SRC_FILES_NAMES = main.cpp
SRC_FILES_NAMES += ClapTrap.cpp


# Full path to .c files
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_FILES_NAMES))

# .o files for compilation
OBJ_FILES = $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.o, $(SRC_FILES))

# .d files for header dependency
DEP_FILES = $(patsubst $(SRC_DIR)%.cpp, $(BUILD_DIR)%.d, $(SRC_FILES))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

NAME := claptrap
CXX := c++
CXXFLAGS := -gdwarf-4 -Wall -Wextra -Werror -I $(INC_DIR) -MMD -MP -std=c++98
LFLAGS := 
MKDIR := mkdir -p
RM_RF := rm -rf
ECHO  := echo -e


BLUE	:= \e[34m
BROWN	:= \e[33m
GREEN	:= \e[32m
RED		:= \e[31m
NC		:= \e[0m

#<><><><><><><> Recipes <><><><><><><><><><><><><><><><><><>

# Modifying Implicit conversion rules to build in custom directory
$(BUILD_DIR)%.o : $(SRC_DIR)%.cpp
	@$(MKDIR) $(dir $@)
	@$(ECHO) "$(BLUE)[CMP] Compiling $<...$(NC)"
	@$(CXX) -c $(CXXFLAGS) $< -o $@ 


# This is to add the .d files as dependencies for linking
-include $(DEP_FILES) $(DEBUG_BUILD_PATH).d


re : clean all


$(NAME) : $(OBJ_FILES)
	@$(ECHO) "$(BROWN)[BLD] Building $(NAME) executable...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CXX) $(CXXFLAGS) $^ -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

all : $(NAME) 

debug : $(OBJ_FILES)
	@$(ECHO) "$(RED)[DBG] Making in DEBUG MODE...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CXX) $(CXXFLAGS) -D DEBUG -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(ECHO) "$(BROWN)[BLD] Building executable...$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(DEBUG_BUILD_PATH).o -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

force : $(OBJ_FILES)
	@$(ECHO) "$(RED)[DBG] Making in FORCED mode...$(NC)"
	@$(ECHO) "$(BROWN)[BLD] Building libft static library...$(NC)"
	@$(MAKE) --no-print-directory -s -C ./libft all
	@$(ECHO) "$(GREEN)[BLD] successfully built libft.$(NC)"	
	@$(ECHO) "$(BROWN)[BLD] Building $(NAME) executable...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CXX) $(CXXFLAGS) -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(CXX) $(CXXFLAGS) $^ $(DEBUG_BUILD_PATH).o -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built in FORCED mode successfully.$(NC)"


clean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES) $(DEBUG_BUILD_PATH).[od]
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM_RF) $(BUILD_DIR) $(NAME)
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"


.DEFAULT_GOAL := all
.PHONY : all clean fclean re debug
