SRCS = nlc.cpp
OBJS = $(addsuffix .o,$(basename $(SRCS)))
DEPENDS = $(addprefix .d_, $(basename $(SRCS)))
NOLIFE = $(wildcard CodeGeneratorTestfiles/*.nl)

ENV = -g
CXX = g++
INCLUDES= -I. \
	  -I.. \

TARGET	= nlc
DIRS = parser visitors utilities
LIBS = parser/libparser-g.a visitors/libvisitors-g.a utilities/libutilities-g.a

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
	$(RM) $(TARGET) $(TARGET).o .d_*
	rm -rf assembly
cpp.o:
	echo "Compiling" $<
	$(CXX) -c $(CXXFLAGS) $<

.d_%: %.cpp 
	echo  "Updating dependences for" $< "..."
	$(CPP) -MM -MT '$(ARCHIVE)($(basename $<).o)' $(INCLUDES) -MF $@ $<

tests: $(TARGET)
	mkdir -p assembly
	$(foreach f, $(NOLIFE), \
		echo "Making $f..."; \
		./nlc $f; \
		echo "Moving $(notdir $f)..."; \
		mv asm.S assembly/$(addsuffix .S, $(notdir $(basename $f))); \
	)
	
#
# This includes all of the dependence files. If the file does not exist,
# GNU Make will use one of the above rules to create it.
#

include $(DEPENDS)
	 
# DO NOT DELETE THIS LINE -- make depend depends on it.

remote-bin: $(TARGET)
	scp ./asm.S ub32:~/Code/compilers/nolife
	ssh ub32 'cd ~/Code/compilers/nolife && gcc asm.S -o asm'

remote-test: remote-bin
	ssh ub32 'cd ~/Code/compilers/nolife && ./bin'

remote-bin-all: tests
	$(foreach f, $(wildcard assembly/*.S), \
		echo "Copying $f..."; \
		ssh ub32 'mkdir -p ~/Code/compilers/nolife/bin'; \
		scp $f ub32:~/Code/compilers/nolife/$(addsuffix .S, $(notdir $(basename $f))); \
		ssh ub32 'cd ~/Code/compilers/nolife && gcc $(addsuffix .S, $(notdir $(basename $f))) -o bin/$(notdir $(basename $f))'; \
	)