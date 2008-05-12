/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   ldt_ui.c
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

static GladeXML *load_glade_xml_if_it_exists(gchar *file_to_load);

/** 
 *  Checks if 'file_to_load' exists and loads it in the XML structure
 */
static GladeXML *load_glade_xml_if_it_exists(gchar *file_to_load)
{
	struct stat *stat_buf;
	GladeXML *xml = NULL;

	stat_buf = (struct stat *) g_malloc0 (sizeof(struct stat));

	stat(file_to_load, stat_buf);
	if (S_ISREG(stat_buf->st_mode) && stat_buf->st_size>0)
			xml = glade_xml_new(file_to_load, NULL, NULL);
	else
		xml = NULL;

	g_free(stat_buf);

	return xml;
}


/**
 *  Loads a glade's XML description file that describes an interface.
 *  Tries all paths defined in the 'location_list' list. If it succeed
 *  then the function returns the loaded XML else it returns NULL
 */ 
GladeXML *ldt_load_glade_xml_file(GList *location_list, gchar *filename)
{	
  gchar *file_to_load = NULL;
  gchar *path = NULL;
  GList *list = g_list_first(location_list);
  GladeXML *xml = NULL;

  while (list != NULL && xml == NULL)
    {
      path = ldt_get_location(list);
      file_to_load =  g_strdup_printf("%s%c%s", path, G_DIR_SEPARATOR, filename);
		  
      xml = load_glade_xml_if_it_exists(file_to_load);

      if (xml == NULL)
	list = ldt_location_list_next(list);	
      g_free(file_to_load);
    }
	
  return xml;
}

/**
 *  Add the text 'text' to the treeview 'tv'
 */
void ldt_add_text_to_textview(gchar *text, GtkTextView *tv)
{
  GtkTextBuffer *tb = NULL;
  GtkTextIter iStart;

  tb = GTK_TEXT_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv)));
  gtk_text_buffer_get_end_iter(tb, &iStart);
  gtk_text_buffer_insert(tb, &iStart, text, -1);

}

/**
 *  Looks for the active widget within a radio button group
 *  Does not take into account inconsistent states
 *  returns the first active radio button it finds.
 */
GtkWidget *ldt_gtk_radio_button_get_active(GSList *group)
{
  GSList *tmp_slist = group;
  
  while (tmp_slist != NULL)
    {
      if (GTK_TOGGLE_BUTTON (tmp_slist->data)->active)
		  {
			  return GTK_WIDGET (tmp_slist->data);
		  }
	  tmp_slist = tmp_slist->next;
    }

  return NULL;
}

/**
 *  gtk_radio_button_get_active_from_widget:
 *  @radio_group_member: widget to get radio group from
 * 
 *  @returns: the active #GtkRadioButton within the group from
 *            @radio_group_member
 **/
GtkWidget *ldt_gtk_radio_button_get_active_from_widget(GtkRadioButton *radio_group_member)
{ 
  if (radio_group_member != NULL)
	  {
		  return ldt_gtk_radio_button_get_active(radio_group_member->group);
	  }
  else
	  {
		  return NULL;
	  }
}
