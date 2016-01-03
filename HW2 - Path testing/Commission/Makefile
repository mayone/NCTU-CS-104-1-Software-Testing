CXX = g++
TITLE = commission
GTEST_DIR = ../gtest
CXXFLAGS = -isystem $(GTEST_DIR)/include -I include \
		-g -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h \
		$(GTEST_HEADERS)
GTEST_LIBS = $(GTEST_DIR)/lib/*.a
DEPS = include/$(TITLE).h
OBJS = obj/$(TITLE).o

all: bin/$(TITLE)_unittest

$(GTEST_DIR)/obj/gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(GTEST_DIR)/obj/gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(GTEST_DIR)/lib/gtest.a: $(GTEST_DIR)/obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_DIR)/lib/gtest_main.a: $(GTEST_DIR)/obj/gtest-all.o $(GTEST_DIR)/obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

obj/%.o: src/%.cc $(DEPS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

obj/%_unittest.o: test/%_unittest.cc $(DEPS) $(GTEST_HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

bin/%_unittest: obj/%.o obj/%_unittest.o $(GTEST_DIR)/lib/gtest_main.a
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: run coverage clean

run:
	bin/$(TITLE)_unittest

coverage:
	rm -rf cov
	mkdir cov
	gcov -b -o obj src/$(TITLE).cc
	mv *.gcov cov

clean:
	rm -rf $(GTEST_DIR)/obj/*.gcda
	rm -rf $(GTEST_DIR)/obj/*.o
	rm -rf $(GTEST_LIBS)
	rm -rf cov
	rm -rf obj/*.gcda
	rm -rf obj/*.gcno
	rm -rf obj/*.o
	rm -rf bin/$(TITLE)_unittest
