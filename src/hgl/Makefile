# src/hgl/Makefile
TOP = ../..
include $(TOP)/configs/current

SUBDIRS = libgl-haiku

default install clean:
	@for dir in $(SUBDIRS) ; do \
		if [ -d $$dir ] ; then \
			(cd $$dir && $(MAKE) $@) || exit 1; \
		fi \
	done
