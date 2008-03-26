/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   ui.h
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
#ifndef _LIBDUPTOOLS_UI_H_
#define _LIBDUPTOOLS_UI_H_

extern GladeXML *load_glade_xml_file(GList *location_list, gchar *filename);
extern void add_text_to_textview(gchar *text, GtkTextView *tv);
extern GtkWidget *gtk_radio_button_get_active(GSList *group);
extern GtkWidget *gtk_radio_button_get_active_from_widget(GtkRadioButton *radio_group_member);

#endif /* _LIBDUPTOOLS_UI_H_ */
