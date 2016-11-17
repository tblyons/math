TARGET := unittests
BLDDIR := build
SOURCES := \
           test/main.cpp \
           test/math/fixed_point.cpp \
           test/math/integer.cpp \
           test/math/stats.cpp \

CPPFLAGS += -c -MP -MMD -Werror -I include -I 3rdparty/doctest
CXXFLAGS += -std=c++14
OBJECTS = $(SOURCES:%.cpp=$(BLDDIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

ifeq ($(CXX), clang++)
   CPPFLAGS += -Weverything -Wno-padded
   CXXFLAGS += -Wno-c++98-compat-pedantic -stdlib=libc++
   LFLAGS += -lc++ -lc++abi
endif

ifeq ($(CXX), g++)
   CPPFLAGS += -Wall -Wextra
endif

.PHONY: all check clean
all: $(TARGET)

check: $(TARGET)
	-./$(TARGET)

clean:
	$(RM) -r build $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LFLAGS) $^ -o $@

$(BLDDIR):
	mkdir -p $(dir $(OBJECTS))

$(BLDDIR)/%.o: %.cpp | $(BLDDIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $<

-include $(DEPS)
