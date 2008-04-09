/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   ldt_log.h
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
#ifndef _LIBDUPTOOLS_LOG_H_
#define _LIBDUPTOOLS_LOG_H_

typedef struct
{
	GtkTextView *textview; /* textview where datas will be logged                 */
	gchar *log_domain;     /* message's domain, usually the program's name itself */
	gboolean debug;        /* debug conditions ?                                  */
} log_t;

extern void log_message(log_t *log, GLogLevelFlags log_level, const char *format, ...);
extern log_t *init_log_domain(GtkTextView *textview, gchar *log_domain, gboolean debug);

#endif /* _LIBDUPTOOLS_LOG_H_ */
