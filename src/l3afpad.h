/*
 *  L3afpad - GTK+ based simple text editor
 *  Copyright (C) 2004-2005 Tarot Osuji
 *  
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _L3AFPAD_H
#define _L3AFPAD_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gtk/gtk.h>
#include <glib/gi18n.h>

#include "window.h"
#include "menu.h"
#include "callback.h"
#include "view.h"
#include "undo.h"
#include "font.h"
#include "linenum.h"
#include "indent.h"
#include "hlight.h"
#include "selector.h"
#include "file.h"
#include "encoding.h"
#include "search.h"
#include "dialog.h"
#include "dnd.h"
#include "utils.h"
#include "emacs.h"
#ifdef ENABLE_PRINT
#include "gtkprint.h"
#endif

#undef GTK_CHECK_MENU_ITEM
#define GTK_CHECK_MENU_ITEM
#define GtkItemFactory GtkUIManager
#define gtk_check_menu_item_get_active gtk_toggle_action_get_active
#define gtk_item_factory_from_widget (GtkUIManager*)
#define gtk_item_factory_get_item(x,y) GTK_TOGGLE_ACTION(gtk_ui_manager_get_action(x,y))
#define gtk_item_factory_get_widget gtk_ui_manager_get_widget
#if GTK_CHECK_VERSION(3, 0, 0)
#include <gdk/gdkkeysyms-compat.h>
#define GTK_OPTION_MENU GTK_COMBO_BOX
#define GTK_WIDGET_IS_SENSITIVE gtk_widget_is_sensitive
#define GTK_WIDGET_VISIBLE gtk_widget_get_visible
#define GtkOptionMenu GtkComboBox
#define gtk_option_menu_get_history gtk_combo_box_get_active
#define gtk_option_menu_new gtk_combo_box_text_new
#define gtk_option_menu_set_history gtk_combo_box_set_active
#define gtk_option_menu_set_menu(x,y)
#endif
#if GTK_CHECK_VERSION(3,1,12)
#undef  GTK_FONT_SELECTION_DIALOG
#define GTK_FONT_SELECTION_DIALOG GTK_FONT_CHOOSER_DIALOG
#define gtk_font_selection_dialog_new(x) gtk_font_chooser_dialog_new(x, NULL)
#define gtk_font_selection_dialog_get_font_name gtk_font_chooser_dialog_get_font_name
#define gtk_font_selection_dialog_set_font_name gtk_font_chooser_dialog_set_font_name
#endif

typedef struct {
	FileInfo *fi;
	MainWin *mw;
} PublicData;

PublicData *pub;

void save_config_file(void);

#endif /* _L3AFPAD_H */