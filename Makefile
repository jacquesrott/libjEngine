ECHO		=	@/bin/echo
SRCDIR		=	lib
OBJDIR		=	obj
INCDIR		=	inc

CC		=	g++
LDCC		=	g++

LIBNAME		=	libjEngine
LIBVER		=	1.0
LIBEXT		=	dylib
LIBFULLNAME	=	$(LIBNAME).$(LIBEXT)

LIB_INSTALL_PATH=	/usr/local/lib

CFLAGS		=	-fPIC -c -g -Wall
LDFLAGS		=	-dynamiclib -current_version $(LIBVER) -install_name $(LIB_INSTALL_PATH)

LOCAL_INCLUDE	=	-I$(INCDIR)
CPOSTFLAGS	=	$(LOCAL_INCLUDE)

HEADERS		=	$(shell ls $(INCDIR)/*.h 2> /dev/null)
SOURCES		=	$(shell ls $(SRCDIR)/*.cpp 2> /dev/null)
OBJECTS		=	$(shell ls $(SRCDIR)/*.cpp 2> /dev/null | sed -e 's/$(SRCDIR)\(.*\)\.cpp/\$(OBJDIR)\1.o/g')
LIBRARY		=	$(LIBFULLNAME)

BUILDDIR	=	build

ifeq ($(shell uname),Darwin)
    OS_LDPF	=	-framework Cocoa\
			-framework OpenGL\
			-framework SDL\
			-framework SDL_image
    BUILDARCH	=	macosx
endif

BUILD		=	$(BUILDDIR)/$(BUILDARCH)


BLIB_LIBS	=	-ljansson
BLIB_LDPF	=	-L/usr/lib $(BLIB_LIBS)

LDPOSTFLAGS	=	$(BLIB_LIBS) $(OS_LDPF)

.SUFFIXES:
.SUFFIXES: .cpp .c .o

all: $(LIBRARY)

# Link the binary using new object files
$(LIBRARY): $(OBJECTS)
	$(LDCC) $(LDFLAGS) $(OBJECTS) $(LDPOSTFLAGS) -o $(BUILD)/$@

# Create .o files for each .cpp file in $(SRCDIR) and move it to $(OBJDIR)
$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCDIR)/%.h
	$(CC) $(CFLAGS) $< $(CPOSTFLAGS) -o $@

# Remove (RM = rm -f) all .o files and the executable
clean:
	$(ECHO) -n "Cleaning... "
	@$(RM) $(BUILD)/$(LIBRARY)
	@$(RM) $(OBJDIR)/*.o
	$(ECHO) ok.

test: install
	$(CC) -c test/main.cpp -Wall -o $(OBJDIR)/main.o
	$(CC) -o $(OBJDIR)/main.o TEST -L/usr/local/lib -ljEngine -framework OpenGL -framework SDL -framework Cocoa

install: all
	sudo mv $(BUILD)/$(LIBRARY) $(LIB_INSTALL_PATH)/$(LIBRARY)
	#mkdir -p /usr/local/include/jEngine
	#sudo cp $(INCDIR)/*.h /usr/local/include/jEngine

uninstall: install
	sudo rm $(LIB_INSTALL_PATH)/$(LIBRARY)
	#sudo rm -rf /usr/local/include/jEngine


