COMPILER         = -g++
mkfile_path      = $(shell pwd)
#lib from https://github.com/aappleby/smhasher
LIB_HASH         = $(mkfile_path)/../../../smhasher/src/build/libSMHasherSupport.a
INC		 = -I$(mkfile_path)/../../../smhasher/src/
OPTIMIZATION_OPT = -O3
OPTIONS          = -pedantic-errors -ansi -Wall -std=c++11 -Wextra -Werror -Wno-long-long $(INC) $(OPTIMIZATION_OPT) 
LINKER_OPT       = -L/usr/lib  $(LIB_HASH)  -lstdc++ -lm 
 
BUILD_LIST+=bloomFilter
#BUILD_LIST+=bloomFilterTask

all: $(BUILD_LIST)

$(BUILD_LIST) : %: %.cpp bloomFilter.hpp 
	$(COMPILER) $(OPTIONS) -o $@ $@.cpp $(LINKER_OPT)

strip_bin :
	@for f in $(BUILD_LIST); do if [ -f $$f ]; then strip -s $$f; echo $$f; fi done; 

valgrind :
	@for f in $(BUILD_LIST); do \
		if [ -f $$f ]; then \
			cmd="valgrind --leak-check=full --show-reachable=yes --track-origins=yes --log-file=$$f.log -v ./$$f"; \
			echo $$cmd; \
			$$cmd; \
		fi done;

clean:
	rm -f core *.o *.bak *stackdump *

