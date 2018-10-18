SRCS = nlc.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))
DEPENDS = $(addprefix .d_, $(basename $(SRCS)))

ENV = -g
CXX = g++
INCLUDES= -I. \
	  -I..

TARGET	= nlc
DIRS = parser 
LIBS = parser/libparser-g.a 

RM = /bin/rm -f

CXXFLAGS = $(INCLUDES) $(ENV) 

.SILENT:

$(TARGET): $(LIBS) $(OBJS)
	echo "Creating $@"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

.PHONY: $(LIBS) clean docs

$(LIBS): 
	echo "Making directory $(dir $@)"
	$(MAKE) -C $(dir $@)

clean:
	for dir in $(DIRS); do \
		echo "Cleaning directory $$dir"; \
		$(MAKE) -C $$dir clean; \
	done
	$(RM) $(TARGET)
cpp.o:
	echo "Compiling" $<
	$(CXX) -c $(CXXFLAGS) $<

.d_%: %.cpp 
	echo  "Updating dependences for" $< "..."
	$(CPP) -MM -MT '$(ARCHIVE)($(basename $<).o)' $(INCLUDES) -MF $@ $<
	
#
# This includes all of the dependence files. If the file does not exist,
# GNU Make will use one of the above rules to create it.
#

include $(DEPENDS)
	 
# DO NOT DELETE THIS LINE -- make depend depends on it.

