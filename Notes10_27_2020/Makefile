# Makefile used to make a purple circle ppm

# The following are oject files that executable is going to depend on.
# They correspond to the .c files used in the project and if the .c file is modified they get recompiled.
OBJS = PurpleCircle.o HelperFunctions.o

# The following are the header files for stenceling functions.
INCLUDES = MyFunctions.h

# Debugging flags are typically put here.
# Use the convention turn on with flag setting: -DDBG_<NAME>
DEBUGFLAGS =

# Parameters automatically used by the gcc to compile the source code to an object file.
CFLAGS = -Wall -g ${DEBUGFLAGS}

# Rule for making the executable file "PurpleCircle"
PurpleCircle: ${OBJS} ${INCLUDES} Makefile
	gcc -Wall -g -o PurpleCircle ${OBJS} -lm

# Dependencies for the object files to include and Makefiles
${OBJS}: ${INCLUDES} Makefile

# This is an unrelated rule that we can use to clean up by removing *.o files.
# Invoke this with "make clean"
clean:
	echo Removing *.o PurpleCircle
	/bin/rm -f *.o PurpleCircle
