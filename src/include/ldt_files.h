/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
  ldt_files.h
  libduptools library
 
  (C) Copyright 2007-2008 Olivier Delhomme
  e-mail : olivierdelhomme@gmail.com
 
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or  (at your option) 
  any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY;  without even the implied warranty of
  MERCHANTABILITY  or  FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
*/
#ifndef _LIBDUPTOOLS_FILES_H_
#define _LIBDUPTOOLS_FILES_H_

/* Specific includes directives for the Windows system */
#ifdef SYS_MINGW
 #include <windows.h>
 #include <winnt.h>
 #include <winioctl.h>
#endif /* SYS_MINGW */

extern guint64 ldt_get_file_size(gchar *filename);

#endif /* _LIBDUPTOOLS_FILES_H_ */
