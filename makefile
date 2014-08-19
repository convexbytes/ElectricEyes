CC 				= g++
CFLAGS 			= -g -Wall -o3
LDFLAGS 		= 
LDLIBS 			= -L/usr/lib -lm -lrt -lpthread
EXECUTABLE 		= electric_eyes
OBJ_DIR 		= obj
SRC_DIR 		= src
INCLUDES		= $(SRC_DIR)/includes.h
OBJECTS 		:= $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.cpp) )
OBJECTS 		:= $(filter-out $(OBJ_DIR)/main.o, $(OBJECTS))
PARSER_DIR 		= src/parser
PARSER_OBJ_DIR 	= src/parser
PARSER_OBJ 		:= $(PARSER_OBJ_DIR)/client_parser.tab.o $(PARSER_OBJ_DIR)/lex.yy.o $(PARSER_OBJ_DIR)/client_parser_driver.o
PARSER_DEPENDENCIES := $(PARSER_DIR)/client_parser.y $(PARSER_DIR)/client_lexer.l $(PARSER_DIR)/client_lexer.h $(PARSER_DIR)/client_parser_driver.cpp $(PARSER_DIR)/client_parser_driver.h $(PARSER_DIR)/client_parser_types.h
PARSER_LDLIBS 	= -lfl

all: $(OBJ_DIR) $(PARSER_DEPENDENCIES) $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(PARSER_OBJ) $(OBJ_DIR)/main.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) $(PARSER_OBJ) $(OBJ_DIR)/main.o $(LDLIBS) $(PARSER_LDLIBS)  -o $(EXECUTABLE)

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/%.h
	$(CC) -c -include $(INCLUDES) $(CFLAGS) $(LDFLAGS) $(patsubst $(OBJ_DIR)/%.o,$(SRC_DIR)/%.cpp, $@) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c -include $(INCLUDES) $(CFLAGS) $(LDFLAGS) $< -o $@

$(PARSER_OBJ): $(PARSER_DEPENDENCIES)
	cd $(PARSER_DIR) && make

$(PARSER_DEPENDENCIES): 
	cd $(PARSER_DIR) && make	

.PHONY: clean

$(OBJ_DIR): 
	mkdir -p $(OBJ_DIR)

clean:
	rm $(OBJECTS)
	rm $(PARSER_OBJ)
	rm $(EXECUTABLE)

