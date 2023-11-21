NAME := checkOS
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    CC := cc
    CFLAGS := -Wall -Wextra
    LIBS := -lm
	NAME := checkOS	
    all:
		$(CC) main.c $(CFLAGS) -o $(NAME) $(LIBS)
		@echo "Linux OS detected"
else ifeq ($(UNAME_S),Darwin)
    CC := clang
    CFLAGS := -Wall -Wextra
    LIBS := -lm

    all: $(NAME)
		@echo "Mac OS detected"
else
    $(error Error getting operating system: $(UNAME_S))
endif
