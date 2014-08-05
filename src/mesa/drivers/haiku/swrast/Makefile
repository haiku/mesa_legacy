# src/mesa/drivers/haiku/swrast/Makefile

TOP = ../../../../..
include $(TOP)/configs/current

MESA_MODULES = $(TOP)/src/mesa/libmesa.a

INCLUDES = \
	-I../common \
	-I$(TOP)/src/mapi \
	-I$(TOP)/src/mapi/mapi \
	-I$(TOP)/src/mesa \
	-I$(TOP)/src/mesa/array_cache \
	-I$(TOP)/src/mesa/main \
	-I$(TOP)/src/mesa/glapi \
	-I$(TOP)/src/mesa/math \
	-I$(TOP)/src/mesa/shader \
	-I$(TOP)/src/mesa/swrast \
	-I$(TOP)/src/mesa/swrast_setup \
	-I$(TOP)/src/mesa/tnl \
	-I$(TOP)/src/mesa/tnl_dd \
	-I$(TOP)/src/mesa/x86 \
	-I. \
	-I- \
	-I$(TOP)/include \
	-I$(TOP)/include/HGL \
	-I/boot/system/develop/headers/private/interface/

DRIVER_SOURCES = \
	MesaSoftwareRenderer.cpp

DRIVER_OBJECTS = $(DRIVER_SOURCES:.c=.o)
DRIVER_OBJECTS := $(DRIVER_OBJECTS:.S=.o)

OBJECTS := $(DRIVER_OBJECTS:.cpp=.o)

RAST_LIB_NAME = libswrast.so
RAST_LIB = swrast

# Rules

.c.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.cpp.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

.S.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@


default: depend $(TOP)/$(LIB_DIR) $(TOP)/$(LIB_DIR)/$(RAST_LIB_NAME)

$(MESA_MODULES):
	cd $(TOP)/src/mesa && $(MAKE) mesa.a ;
	mimeset -f "$@"

$(TOP)/$(LIB_DIR):
	mkdir $(TOP)/$(LIB_DIR)

$(TOP)/$(LIB_DIR)/$(RAST_LIB_NAME): $(OBJECTS) $(MESA_MODULES)
	@$(MKLIB) -o $(RAST_LIB) -linker '$(CC)' -ldflags '$(LDFLAGS)' \
		-major $(MESA_MAJOR) -minor $(MESA_MINOR) -patch $(MESA_TINY) \
		-install $(TOP)/$(LIB_DIR) $(MKLIB_OPTIONS) \
		$(OBJECTS) $(MESA_MODULES)

depend: $(DRIVER_SOURCES)
	touch depend
	$(MKDEP) $(MKDEP_OPTIONS) $(INCLUDES) $(DRIVER_SOURCES) > /dev/null 

clean:
	-rm -f depend depend.bak $(OBJECTS)

include depend
