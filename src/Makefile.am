AUTOMAKE_OPTIONS = no-dependencies foreign

SUBDIRS = 

DEFS = 	-DPLUGINS_DIR=\"$(plugins_dir)\" 	\
	-DDATA_DIR=\"$(datadir)\" 		\
	-I$(top_srcdir)/include 		\
	-I$(srcdir)/ $(LIBGLADE_CFLAGS) 	\
	$(GTK2_CFLAGS) $(GLIB2_CFLAGS) $(CFLAGS)\
	-I$(TOP_DIR) -I$(SRC_DIR)/include

libdir=$(exec_prefix)/lib/dup
includedir=$(prefix)/include/dup

headerfiles = 			\
	include/duptools.h	\
	include/ldt_ui.h	\
	include/ldt_locations.h	\
	include/ldt_log.h	\
	include/ldt_files.h

lib_LTLIBRARIES = libduptools.la
include_HEADERS = $(headerfiles)
libduptools_la_LDFLAGS = -version 0:0:1 -no-undefined -module -export-dynamic 
libduptools_la_LIBADD = $(GLIB2_LIBS) $(GTK2_LIBS) $(LIBGLADE_LIBS) $(LDFLAGS)

libduptools_la_SOURCES = 	\
	libduptools.c		\
	ldt_ui.c		\
	ldt_locations.c		\
	ldt_log.c		\
	ldt_files.c		\
	$(headerfiles)