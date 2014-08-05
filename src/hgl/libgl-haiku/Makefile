TOP = ../../..
include $(TOP)/configs/current

SOURCES = \
      GLDispatcher.cpp \
      GLRenderer.cpp \
      GLRendererRoster.cpp \
      GLView.cpp

GLAPI_LIB = $(TOP)/src/mapi/glapi/libglapi.a
GLU_LIB = $(TOP)/src/glu/sgi/$(GLU_LIB_NAME)

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -I. \
    -I$(TOP)/include \
    -I$(TOP)/include/GL/internal \
    -I$(TOP)/include/HGL \
    -I$(TOP)/src/mesa \
	-I$(TOP)/src/mesa/main \
    -I$(TOP)/src/mapi \
    -I$(TOP)/src/mapi/glapi \
	-I/boot/system/develop/headers/private


##### RULES #####

.c.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $(EXTRA_DEFINES) $< -o $@

.cpp.o:
	$(CXX) -c $(INCLUDES) $(CFLAGS) $(EXTRA_DEFINES) $< -o $@

.S.o:
	$(CC) -c $(INCLUDES) $(CFLAGS) $(EXTRA_DEFINES)  $< -o $@

##### TARGETS #####

default: $(TOP)/$(LIB_DIR)/$(GL_LIB_NAME)

$(GLAPI_LIB):
	@$(MAKE) -C $(TOP)/src/mapi/glapi

# Make libGL
$(TOP)/$(LIB_DIR)/$(GL_LIB_NAME): $(OBJECTS) $(GLAPI_LIB) Makefile
	$(MKLIB) -o $(GL_LIB) -linker '$(CXX)' -ldflags '$(LDFLAGS)' \
		-cplusplus $(MKLIB_OPTIONS) -install $(TOP)/$(LIB_DIR) \
		$(GL_LIB_DEPS) $(GLAPI_LIB) $(OBJECTS) $(GLU_LIB)

# Remove .o and backup files
clean:
	-rm -f $(TOP)/$(LIB_DIR)/$(GL_LIB_GLOB)
	-rm -f *.o *~

