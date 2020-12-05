/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-settings-app.h"
#include "pi-settings-window.h"

struct _PiSettingsApp
{
   GtkApplication parent_instance;
};

G_DEFINE_TYPE (PiSettingsApp, pi_settings_app, GTK_TYPE_APPLICATION);

static void
pi_settings_app_activate (GApplication *application)
{
   PiSettingsApp *self = PI_SETTINGS_APP (application);

   PiSettingsWindow *window = pi_settings_window_new (self);
   gtk_window_present (GTK_WINDOW (window));
}

void
pi_settings_app_class_init (PiSettingsAppClass *klass)
{
  G_APPLICATION_CLASS (klass)->activate = pi_settings_app_activate;
}

void
pi_settings_app_init (PiSettingsApp *self)
{
}

PiSettingsApp *
pi_settings_app_new (void)
{
   return g_object_new (pi_settings_app_get_type (), NULL);
}
