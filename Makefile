CXX := clang++
TARGET := tbl-test
OBJECTS = $(SOURCES:%.cpp=$(BLDDIR)/%.o)
DEPS = $(OBJECTS:.o=.d)
INCLUDES := -I include -I deps/doctest
SOURCES := \
           test/math/integer.cpp \

ifndef CONFIG
   CONFIG=Valgrind
endif

ifeq ($(CONFIG), AddSan)
   BLDDIR := build/sanitize
   CFLAGS := -g3 -O0 -fsanitize=address
   LFLAGS := -g3 -O0 -fsanitize=address
endif

ifeq ($(CONFIG), Valgrind)
   BLDDIR := build/debug
   CFLAGS := -g3 -O0
   LFLAGS := -g3 -O0
endif

ifeq ($(CONFIG), Release)
   BLDDIR := build/release
   CFLAGS := -g0 -O3
   LFLAGS := -g0 -O3
endif

WARNINGS = -Werror -Weverything -Wno-c++98-compat-pedantic -Wno-padded
CFLAGS += -c -std=c++14 -stdlib=libc++ -MP -MMD
LFLAGS += -lc++ -lc++abi

.PHONY: all check clean
all: $(TARGET)

check: $(TARGET)
	./$(TARGET)

clean:
	$(RM) -r build $(TARGET)

$(TARGET): $(OBJECTS) $(BLDDIR)/test/main.o
	$(CXX) $(LFLAGS) $^ -o $@

$(BLDDIR):
	mkdir -p $(dir $(OBJECTS))

$(BLDDIR)/%.o: %.cpp | $(BLDDIR)
	$(CXX) $(CFLAGS) $(WARNINGS) $(INCLUDES) -o $@ $<

-include $(DEPS)
