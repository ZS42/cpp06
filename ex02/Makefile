# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 17:14:37 by zsyyida           #+#    #+#              #
#    Updated: 2023/11/25 02:16:48 by zsyyida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cast

CXX = c++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS = main.cpp Base.cpp

INCLUDE =  Base.hpp A.hpp B.hpp C.hpp

OBJS := $(SRCS:.cpp=.o)

# adding Makefile triggers a rebuild if change in Makefile
all: $(NAME) Makefile

# .c.o:	${CC} ${CFLAGS} -I -c $< -o ${<:.cpp=.o}
%.o: %.cpp $(INCLUDE)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .cpp.o