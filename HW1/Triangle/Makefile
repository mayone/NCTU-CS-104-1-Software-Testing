CXX = g++
TITLE = triangle
GTEST_DIR = ../gtest
CPPFLAGS += -isystem $(GTEST_DIR)/include -I include
CXXFLAGS += -g -Wall -Wextra -pthread
LDFLAGS = -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_LIBS = $(GTEST_DIR)/lib/*.a

EXECUTE = main

all: bin/$(TITLE)_unittest

obj/$(TITLE).o : src/$(TITLE).cc include/$(TITLE).h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

obj/$(TITLE)_unittest.o : test/$(TITLE)_unittest.cc \
			include/$(TITLE).h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

bin/$(TITLE)_unittest : obj/$(TITLE).o obj/$(TITLE)_unittest.o \
			$(GTEST_LIBS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

run:
	bin/$(TITLE)_unittest
clean:
	rm -rf obj/*.o
	rm -rf bin/$(TITLE)_unittest
