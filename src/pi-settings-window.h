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

#include "pi-settings-app.h"

G_BEGIN_DECLS

G_DECLARE_FINAL_TYPE (PiSettingsWindow, pi_settings_window, PI, SETTINGS_WINDOW, GtkApplicationWindow)

PiSettingsWindow *pi_settings_window_new (PiSettingsApp *app);

G_END_DECLS
