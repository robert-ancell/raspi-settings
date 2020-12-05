/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-sound-panel.h"

struct _PiSoundPanel
{
   PiSettingsPanel parent_instance;
};

G_DEFINE_TYPE (PiSoundPanel, pi_sound_panel, pi_settings_panel_get_type ());

void
pi_sound_panel_class_init (PiSoundPanelClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  gtk_widget_class_set_template_from_resource (widget_class, "/com/example/raspi-settings/pi-sound-panel.ui");

  //gtk_widget_class_bind_template_child (widget_class, PiSoundPanel, );
}

void
pi_sound_panel_init (PiSoundPanel *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

PiSoundPanel *
pi_sound_panel_new (void)
{
   return g_object_new (pi_sound_panel_get_type (), NULL);
}
