SRCS = $(wildcard *.cpp)
CXX = g++

OBJS = $(addsuffix .o,$(basename $(SRCS)))

ENV = -g

ARCHIVE = libvisitors$(ENV).a

INCLUDES= -I. \
	  -I.. \

CXXFLAGS = $(INCLUDES) $(ENV) 
ARFLAGS = rU

RM = /bin/rm -f

# .SILENT:

DEPENDS = $(addprefix .d_, $(basename $(SRCS)))

LP = (
RP = )
ARCHIVE_OBJS = $(addsuffix $(RP),$(addprefix $(ARCHIVE)$(LP),$(notdir $(OBJS))))

.SUFFIXES: .cpp

$(ARCHIVE): $(ARCHIVE_OBJS)
	echo "Generating" $(ARCHIVE)
	ranlib $(ARCHIVE)

.PHONY: clean

clean:
	$(RM) $(ARCHIVE) .d_*

.cpp.o:
	echo "Compiling" $<
	$(CXX) -c $(CXXFLAGS) $<

#
# default rule to put all .o files in the archive and remove them
#

(%.o) : %.o
	$(AR) $(ARFLAGS) $@ $<
	$(RM) $<

#
# The following two rules make the dependence file for the C source
# files. The C files depend upon the corresponding dependence file. The
# dependence file depends upon the source file's actual dependences. This way
# both the dependence file and the source file are updated on any change.
# The depend.sed sed command file sets up the dependence file appropriately.
#

.d_%.y: %.y
	echo "$(basename $<).cpp: $<" > $@

.d_%.l: %.l
	echo "$(basename $<).cpp: $<" > $@

.d_%: %.cpp 
	echo  "Updating dependences for" $< "..."
	$(CPP) -MM -MT '$(ARCHIVE)($(basename $<).o)' $(INCLUDES) -MF $@ $<

#
# This includes all of the dependence files. If the file does not exist,
# GNU Make will use one of the above rules to create it.
#

include $(DEPENDS)
	 
# DO NOT DELETE THIS LINE -- make depend depends on it.
