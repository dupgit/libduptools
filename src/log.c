/* -*- indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*- */
/*
   log.c
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

#include "duptools.h"

static void my_log(log_t *log, GLogLevelFlags log_level, const char *format, ...);

/**
 *  Internal function
 */
static void my_log(log_t *log, GLogLevelFlags log_level, const char *format, ...)
{
	va_list args;
	gchar *str = NULL;
	gchar *display = NULL;

	va_start(args, format);
	str = g_strdup_vprintf(format, args);
	va_end(args);

	switch (log_level)
		{
		case G_LOG_FLAG_RECURSION:
			display = g_strdup_printf("%s - RECURSION: %s\n%c", log->log_domain, str, '\0');
			g_print("%s\n", display);
			exit(log_level);
			break;
 
		case G_LOG_FLAG_FATAL:
			display = g_strdup_printf("%s - FATAL: %s\n%c", log->log_domain, str, '\0');
			g_print("%s\n", display);
			exit(log_level);
			break;

		case G_LOG_LEVEL_ERROR:
			display = g_strdup_printf("%s - ERROR: %s\n%c", log->log_domain, str, '\0');
			g_print("%s\n", display);
			exit(log_level);
			break;

		case G_LOG_LEVEL_CRITICAL:
			display = g_strdup_printf("%s - CRITICAL: %s\n%c", log->log_domain, str, '\0');
			break;

		case G_LOG_LEVEL_WARNING:
			display = g_strdup_printf("%s - WARNING: %s\n%c", log->log_domain, str, '\0');
			break;

		case G_LOG_LEVEL_MESSAGE:
			display = g_strdup_printf("%s - MESSAGE: %s\n%c", log->log_domain, str, '\0');
			break;

		case G_LOG_LEVEL_INFO:
			display = g_strdup_printf("%s - INFO: %s\n%c", log->log_domain, str, '\0');
			break;

		case G_LOG_LEVEL_DEBUG:
			display = g_strdup_printf("%s - DEBUG: %s\n%c", log->log_domain, str, '\0');
			break;

		case G_LOG_LEVEL_MASK: /* To avoid a compilation warning */
			break;
		}

	g_print("%s", display);

	add_text_to_textview(display, log->textview);
	
	g_free(str);
	g_free(display);
}

/**
 * External function to be called in program's that lets one
 * log messages at the desired level within the corresponding
 * log domain
 */
void log_message(log_t *log, GLogLevelFlags log_level, const char *format, ...)
{
	va_list args;
	gchar *str = NULL;
	gchar *str_time = NULL;
	gchar *str_time_utf8 = NULL;
	gchar *str_utf8 = NULL;
	GTimeVal *time = NULL;
	GError *err = NULL;

	g_return_if_fail (format != NULL);

	if (!(log_level == G_LOG_LEVEL_DEBUG && log->debug == FALSE))
		{
			va_start(args, format);
			str = g_strdup_vprintf(format, args);
			va_end(args);
	
			time = (GTimeVal *) g_malloc0 (sizeof(GTimeVal));
			g_get_current_time(time);
			str_time = g_time_val_to_iso8601(time);
			str_time_utf8 = g_locale_to_utf8(str_time, -1, NULL, NULL, &err);
			str_utf8 = g_locale_to_utf8(str, -1, NULL, NULL, &err);

			if (str_utf8)
				{
					if (str_time_utf8)
						my_log(log, log_level, "%s - %s%c", str_time_utf8, str_utf8, '\0');
					else
						my_log(log, log_level, "%s - %s%c", str_time, str_utf8, '\0');
				}
			else
				{
					if (str_time_utf8)
						my_log(log, log_level, "%s - %s%c", str_time_utf8, str, '\0');
					else
						my_log(log, log_level, "%s - %s%c", str_time, str, '\0');
				}

			g_free(time);
			g_free(str);
			g_free(str_time);
			g_free(str_time_utf8);
			g_free(str_utf8);
		}
}

/**
 *  Inits the log domain
 */
extern log_t *init_log_domain(GtkTextView *textview, gchar *log_domain, gboolean debug)
{
  log_t *log = NULL;

  log = (log_t *) g_malloc0 (sizeof(log_t));

  log->textview = textview;
  log->log_domain = log_domain;
  log->debug = debug;

  return log;

}
