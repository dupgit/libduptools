/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   ldt_files.c
   libduptools library

   (C) Copyright 2007-2008 Olivier Delhomme
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

#include "duptools.h"

/**
 *  Gives the file's size or 0 if the file does not
 *  exists
 */
#ifdef SYS_MINGW
guint64 ldt_get_file_size(gchar *filename)
{
  WIN32_FILE_ATTRIBUTE_DATA attr;
  guint64 taille;
  
  if (GetFileAttributesEx(filename, GetFileExInfoStandard, &attr) != 0)
   {
     if (attr.nFileSizeHigh != 0)
       {
	 taille = attr.nFileSizeHigh;
	 taille = taille << 32;
	 taille += attr.nFileSizeLow;
       }
     else
       taille = attr.nFileSizeLow;

     return taille;
   }
  else
    return 0;
}
#endif /* SYS_MINGW */

#ifdef SYS_POSIX
guint64 ldt_get_file_size(gchar *filename)
{
  struct stat *stat_buf = NULL;

  stat_buf = (struct stat *) g_malloc0 (sizeof(struct stat));

  if (g_stat(filename, stat_buf) == 0)
    return (guint64) stat_buf->st_size;
  else
    return 0;
}
#endif /* SYS_POSIX */


