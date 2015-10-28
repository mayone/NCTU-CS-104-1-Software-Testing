CXX = g++
GTEST_DIR = ../gtest
CPPFLAGS += -isystem $(GTEST_DIR)/include -I include
CXXFLAGS = -g -Wall -Wextra -pthread
LDFLAGS = -lpthread
SOURCES = src/triangle_unittest.cc
OBJECTS = $(notdir $(SOURCES:.cc=.o))
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_LIBS = $(GTEST_DIR)/lib/*.a

EXECUTE = main

all: bin/triangle_unittest

obj/triangle.o : src/triangle.cc include/triangle.h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

obj/triangle_unittest.o : test/triangle_unittest.cc \
			include/triangle.h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

bin/triangle_unittest : obj/triangle.o obj/triangle_unittest.o \
			$(GTEST_LIBS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

run:
	bin/triangle_unittest
clean:
	rm -rf obj/*.o
	rm -rf bin/triangle_unittest
