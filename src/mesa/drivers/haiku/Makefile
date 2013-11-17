# src/mesa/drivers/haiku/Makefile

TOP = ../../../..

include $(TOP)/configs/current


default: $(TOP)/$(LIB_DIR) subdirs


$(TOP)/$(LIB_DIR):
	-mkdir $(TOP)/$(LIB_DIR)


subdirs:
	if [ -d swrast ] ; then \
		(cd swrast && $(MAKE)) || exit 1 ; \
	fi

install:
	if [ -d swrast ] ; then \
		(cd swrast && $(MAKE) install) || exit 1 ; \
	fi

clean:
	if [ -d swrast ] ; then \
		(cd swrast && $(MAKE) clean) ; \
	fi
