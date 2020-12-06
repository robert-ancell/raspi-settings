/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-settings-window.h"

#include "pi-date-time-panel.h"
#include "pi-display-panel.h"
#include "pi-hardware-panel.h"
#include "pi-keyboard-panel.h"
#include "pi-language-panel.h"
#include "pi-mouse-panel.h"
#include "pi-network-panel.h"
#include "pi-printer-panel.h"
#include "pi-security-panel.h"
#include "pi-settings-panel-row.h"
#include "pi-settings-panel.h"
#include "pi-sound-panel.h"
#include "pi-startup-panel.h"

struct _PiSettingsWindow
{
  GtkApplicationWindow parent_instance;

  PiSettingsPanelRow *date_time_row;
  PiSettingsPanelRow *display_row;
  PiSettingsPanelRow *hardware_row;
  PiSettingsPanelRow *keyboard_row;
  PiSettingsPanelRow *language_row;
  PiSettingsPanelRow *mouse_row;
  PiSettingsPanelRow *network_row;
  GtkBox             *panel_box;
  PiSettingsPanelRow *printer_row;
  PiSettingsPanelRow *security_row;
  PiSettingsPanelRow *sound_row;
  PiSettingsPanelRow *startup_row;
};

G_DEFINE_TYPE (PiSettingsWindow, pi_settings_window, GTK_TYPE_APPLICATION_WINDOW);

static void
panel_row_activated_cb (PiSettingsWindow *self, PiSettingsPanelRow *row)
{
  PiSettingsPanel *panel;
  if (row == self->date_time_row) {
    panel = PI_SETTINGS_PANEL (pi_date_time_panel_new ());
  } else if (row == self->display_row) {
    panel = PI_SETTINGS_PANEL (pi_display_panel_new ());
  } else if (row == self->hardware_row) {
    panel = PI_SETTINGS_PANEL (pi_hardware_panel_new ());
  } else if (row == self->keyboard_row) {
    panel = PI_SETTINGS_PANEL (pi_keyboard_panel_new ());
  } else if (row == self->language_row) {
    panel = PI_SETTINGS_PANEL (pi_language_panel_new ());
  } else if (row == self->mouse_row) {
    panel = PI_SETTINGS_PANEL (pi_mouse_panel_new ());
  } else if (row == self->network_row) {
    panel = PI_SETTINGS_PANEL (pi_network_panel_new ());
  } else if (row == self->printer_row) {
    panel = PI_SETTINGS_PANEL (pi_printer_panel_new ());
  } else if (row == self->security_row) {
    panel = PI_SETTINGS_PANEL (pi_security_panel_new ());
  } else if (row == self->sound_row) {
    panel = PI_SETTINGS_PANEL (pi_sound_panel_new ());
  } else if (row == self->startup_row) {
    panel = PI_SETTINGS_PANEL (pi_startup_panel_new ());
  } else {
    return;
  }

  // Remove existing panel
  g_autoptr(GList) children = gtk_container_get_children (GTK_CONTAINER (self->panel_box));
  for (GList *l = children; l != NULL; l = l->next) {
    GtkWidget *child = l->data;
    gtk_widget_destroy (child);
  }

  gtk_widget_show (GTK_WIDGET (panel));
  gtk_container_add (GTK_CONTAINER (self->panel_box), GTK_WIDGET (panel));
}

void
pi_settings_window_class_init (PiSettingsWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  g_type_ensure (pi_settings_panel_row_get_type ());
  g_type_ensure (pi_network_panel_get_type ());

  gtk_widget_class_set_template_from_resource (widget_class, "/com/example/raspi-settings/pi-settings-window.ui");

  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, date_time_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, display_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, hardware_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, keyboard_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, language_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, mouse_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, network_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, panel_box);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, printer_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, security_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, sound_row);
  gtk_widget_class_bind_template_child (widget_class, PiSettingsWindow, startup_row);

  gtk_widget_class_bind_template_callback (widget_class, panel_row_activated_cb);
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
