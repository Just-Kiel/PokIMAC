APPNAME = app

SRCFILES = $(wildcard *.cpp)
OBJFILES = $(SRCFILES:%.cpp=%.o)

DEPDIR := .deps

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

all: $(APPNAME)

$(APPNAME): $(OBJFILES)
	g++ $^ -o $(APPNAME)

# %.o : %.cpp
%.o : %.cpp $(DEPDIR)/%.d | $(DEPDIR)
	g++ -c $(DEPFLAGS) $(CFLAGS) $<

$(DEPDIR): ; @mkdir -p $@

DEPFILES := $(SRCS:%.c=$(DEPDIR)/%.d)
$(DEPFILES):

include $(wildcard $(DEPFILES))