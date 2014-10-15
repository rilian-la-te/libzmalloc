LIBRARY = libzmalloc
VERSION=0.1
MAJOR = 0

SHAREDLIB = $(LIBRARY).so
SONAME = $(SHAREDLIB).$(MAJOR)

INSTALL = install

LIBDIR = $(libdir)

CC=gcc
CFLAGS =$(FLAGS) -I../include $(RPM_OPT_FLAGS)
LINK.o = $(CC) $(LDFLAGS) $(FLAGS) $(TARGET_ARCH)

LIB_SRC = zmalloc.c

LIB_SOBJ = $(LIB_SRC:%.c=%.so)

.PHONY: all install clean

all: $(SHAREDLIB)

install: all
	$(INSTALL) -pD -m755 $(SHAREDLIB) $(libdir)/$(SHAREDLIB).$(VERSION)
	@ln -sf $(SHAREDLIB).$(VERSION) $(libdir)/$(SONAME)
	@ln -sf $(SONAME) $(libdir)/$(SHAREDLIB)
	$(INSTALL) -pD -m755 zmalloc-ctrl $(bindir)/zmalloc-ctrl
	$(INSTALL) -pD -m755 zmalloc-enable $(bindir)/zmalloc-enable
	$(INSTALL) -pD -m755 zmalloc-disable $(bindir)/zmalloc-disable

clean:
	$(RM) $(LIB_SOBJ) $(SHAREDLIB) $(SONAME) core *~ test

$(SHAREDLIB): $(LIB_SOBJ)
	$(LINK.o) -shared -Wl,-soname,$(SONAME)  $+ $(OUTPUT_OPTION)
	ln -sf $(SHAREDLIB) $(SONAME)

%.so: %.c
	$(CC) -c $(CPPFLAGS) -fpic $< $(OUTPUT_OPTION)
