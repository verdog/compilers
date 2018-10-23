SRCS = nolife_parser.cpp nolife_scanner.cpp $(wildcard *.cpp)
LEX_SRCS = nolife_scanner.l
YACC_SRCS = nolife_parser.y
CXX = g++

OBJS = $(addsuffix .o,$(basename $(SRCS)))

ENV = -g

ARCHIVE = libparser$(ENV).a

INCLUDES= -I. \
	  -I..

CXXFLAGS = $(INCLUDES) -DYYERROR_VERBOSE $(ENV) 
LEX	= flex
LFLAGS  = 
YACC	= bison
YFLAGS	= -d
ARFLAGS = rU

RM = /bin/rm -f

# .SILENT:

LEX_YACC_DEPENDS = $(addprefix .d_,$(LEX_SRCS )) $(addprefix .d_,$(YACC_SRCS))

DEPENDS = $(addprefix .d_, $(basename $(SRCS))) $(LEX_YACC_DEPENDS)

LP = (
RP = )
ARCHIVE_OBJS = $(addsuffix $(RP),$(addprefix $(ARCHIVE)$(LP),$(notdir $(OBJS))))

.SUFFIXES: .cpp .l .y 

$(ARCHIVE): $(ARCHIVE_OBJS)
	echo "Generating" $(ARCHIVE)
	ranlib $(ARCHIVE)

.PHONY: clean

clean:
	$(RM) $(ARCHIVE)

.cpp.o:
	echo "Compiling" $<
	$(CXX) -c $(CXXFLAGS) $<

.y.cpp:
	echo "Running bison on" $<
	$(YACC) $(YFLAGS) -o $@ $< -v

.l.cpp:
	echo "Running flex on" $<
	$(LEX) $(LFLAGS) -o $@ $<

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

