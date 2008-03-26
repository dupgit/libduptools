/* -*- Mode: C; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
/*
  locations.h
  libduptools library
 
  (C) Copyright 2007 Olivier Delhomme
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
#ifndef _LIBDUPTOOLS_LOCATIONS_H_
#define _LIBDUPTOOLS_LOCATIONS_H_

typedef struct
{
  gchar *path;     /* one directory name that represents a particular location */
} location_t;

extern GList *init_location_list(GList *location_list, gchar *progname);
extern gchar *get_location(GList *location_list);
extern GList *location_list_next(GList *location_list);
extern GList *location_list_prev(GList *location_list);

#endif /* _LIBDUPTOOLS_LOCATIONS_H_ */
