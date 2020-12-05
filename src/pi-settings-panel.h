/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#pragma once

#include <gtk/gtk.h>

G_BEGIN_DECLS

struct _PiSettingsPanelClass 
{
  GtkBinClass parent_class;
};

G_DECLARE_DERIVABLE_TYPE (PiSettingsPanel, pi_settings_panel, PI, SETTINGS_PANEL, GtkBin)

G_END_DECLS
