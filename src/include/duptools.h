/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   duptools.h
   libduptools library

   (C) Copyright 2007 Olivier Delhomme
   e-mail : olivierdelhomme@gmail.com
 
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.           
*/
#ifndef _LIBDUPTOOLS_H_
#define _LIBDUPTOOLS_H_

#include <errno.h> 
#include <fcntl.h>
#include <glade/glade.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define LIBDUPTOOLS_NAME "duptools"
#define LIBDUPTOOLS_VERSION "0.0.3"  
#define LIBDUPTOOLS_SUMMARY "libduptools library"
#define LIBDUPTOOLS_DESCRIPTION "Provide some GTK and file operation wrappers"
#define LIBDUPTOOLS_AUTHOR "Olivier Delhomme <olivierdelhomme@gmail.com>"
#define LIBDUPTOOLS_HOMEPAGE "none"

#include "config.h"
#include "ui.h" 
#include "locations.h"
#include "log.h"
#include "files.h"

#endif /* _LIBDUPTOOLS_H_ */
