CXX = g++
TITLE = nextDate
GTEST_DIR = ../gtest
CPPFLAGS += -isystem $(GTEST_DIR)/include -I include
CXXFLAGS += -g -Wall -Wextra -pthread
LDFLAGS = -lpthread
GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
		$(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h \
		$(GTEST_HEADERS)
GTEST_LIBS = $(GTEST_DIR)/lib/*.a


all: bin/$(TITLE)_unittest

$(GTEST_DIR)/obj/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc -o $@

$(GTEST_DIR)/obj/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc -o $@

$(GTEST_DIR)/lib/gtest.a : $(GTEST_DIR)/obj/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(GTEST_DIR)/lib/gtest_main.a : $(GTEST_DIR)/obj/gtest-all.o $(GTEST_DIR)/obj/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

obj/$(TITLE).o : src/$(TITLE).cc include/$(TITLE).h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

obj/$(TITLE)_unittest.o : test/$(TITLE)_unittest.cc \
			include/$(TITLE).h $(GTEST_HEADERS)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

bin/$(TITLE)_unittest : obj/$(TITLE).o obj/$(TITLE)_unittest.o \
			$(GTEST_DIR)/lib/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

run:
	bin/$(TITLE)_unittest
clean:
	rm -rf $(GTEST_DIR)/obj/*.o
	rm -rf $(GTEST_LIBS)
	rm -rf obj/*.o
	rm -rf bin/$(TITLE)_unittest
