/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   ldt_locations.c
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
 *  Inits the location list
 *  Function copied from héraia. Inverted, with usage of g_list_prepend
 *  which is quickier than append.
 *  TODO : take locations as a va_list parameter list
 */
GList *init_location_list(GList *location_list, gchar *progname)
{
	const gchar* const  *system_data_dirs;
	guint i = 0;
	location_t *location;

	/* program's binary path */
	location = (location_t *) g_malloc0 (sizeof(location_t));
	location->path = g_strdup_printf("%s", g_get_current_dir());
	location_list = g_list_prepend(location_list, location);
	
	/* System data dirs */
	system_data_dirs = g_get_system_data_dirs();
	i = 0;
	while (system_data_dirs[i] != NULL)
		{
		  location = (location_t *) g_malloc0 (sizeof(location_t));
		  location->path = g_strdup_printf("%s%c%s", system_data_dirs[i], G_DIR_SEPARATOR, progname);
		  location_list = g_list_prepend(location_list, location);
		  i++;
		}

	/* System config dirs */
	system_data_dirs = g_get_system_config_dirs();
	i = 0;
	while (system_data_dirs[i] != NULL)
		{
		  location = (location_t *) g_malloc0 (sizeof(location_t));
		  location->path = g_strdup_printf("%s%c%s", system_data_dirs[i], G_DIR_SEPARATOR, progname);
		  location_list = g_list_prepend(location_list, location);
		  i++;
		}

	/* the user path */ 
	location = (location_t *) g_malloc0 (sizeof(location_t));
	location->path =  g_strdup_printf("%s%c.%s", g_get_home_dir(), G_DIR_SEPARATOR, progname);
	location_list = g_list_prepend(location_list, location);

	/* A global user data path */
	location = (location_t *) g_malloc0 (sizeof(location_t));
	location->path = g_strdup_printf("%s%c%s", g_get_user_data_dir(), G_DIR_SEPARATOR, progname);
	location_list = g_list_prepend(location_list, location);

	/* A global config data path */
	location = (location_t *) g_malloc0 (sizeof(location_t));
	location->path = g_strdup_printf("%s%c%s", g_get_user_config_dir(), G_DIR_SEPARATOR, progname);
	location_list = g_list_prepend(location_list, location);

	return location_list;
}

/**
 *  Returns the location for the first location's list element
 */
gchar *get_location(GList *location_list)
{
  location_t *location;

  if (location_list != NULL)
    {
      location = location_list->data;
      return location->path;
    }
  else
    return NULL;
}

/**
 *  Returns the next location's list element
 */
GList *location_list_next(GList *location_list)
{
  if (location_list != NULL)
    return location_list->next;
  else
    return NULL;
}

/**
 *  Returns the previous location's list element
 */
GList *location_list_prev(GList *location_list)
{
  if (location_list != NULL)
    return location_list->prev;
  else
    return NULL;
}

