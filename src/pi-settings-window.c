/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-settings-window.h"

#include "pi-network-panel.h"
#include "pi-sound-panel.h"

struct _PiSettingsWindow
{
   GtkApplicationWindow parent_instance;
};

G_DEFINE_TYPE (PiSettingsWindow, pi_settings_window, GTK_TYPE_APPLICATION_WINDOW);

void
pi_settings_window_class_init (PiSettingsWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  g_type_ensure (pi_network_panel_get_type ());

  gtk_widget_class_set_template_from_resource (widget_class, "/com/example/raspi-settings/pi-settings-window.ui");

  //gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, );
}

void
pi_settings_window_init (PiSettingsWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

PiSettingsWindow *
pi_settings_window_new (PiSettingsApp *app)
{
   return g_object_new (pi_settings_window_get_type (), "application", app, NULL);
}
