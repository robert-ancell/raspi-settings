/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-settings-panel-row.h"

typedef struct
{
   GtkLabel *label;
} PiSettingsPanelRowPrivate;

G_DEFINE_TYPE_WITH_PRIVATE (PiSettingsPanelRow, pi_settings_panel_row, GTK_TYPE_LIST_BOX_ROW);

enum
{
  PROP_0,
  PROP_LABEL,
  PROP_LAST
};

static void
pi_settings_panel_row_set_property (GObject *object, guint property_id, const GValue *value, GParamSpec *pspec)
{
  PiSettingsPanelRow *self = PI_SETTINGS_PANEL_ROW (object);
  PiSettingsPanelRowPrivate *priv = pi_settings_panel_row_get_instance_private (self);

  switch (property_id) {
  case PROP_LABEL:
    gtk_label_set_label (priv->label, g_value_get_string (value));
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}

static void
pi_settings_panel_row_get_property (GObject *object, guint property_id, GValue *value, GParamSpec *pspec)
{
  PiSettingsPanelRow *self = PI_SETTINGS_PANEL_ROW (object);
  PiSettingsPanelRowPrivate *priv = pi_settings_panel_row_get_instance_private (self);

  switch (property_id) {
  case PROP_LABEL:
    g_value_set_string (value, gtk_label_get_label (priv->label));
    break;
  default:
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
    break;
  }
}

void
pi_settings_panel_row_class_init (PiSettingsPanelRowClass *klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

  object_class->set_property = pi_settings_panel_row_set_property;
  object_class->get_property = pi_settings_panel_row_get_property;

  g_object_class_install_property (object_class, PROP_LABEL,
                                   g_param_spec_string ("label", NULL, NULL,
                                                        NULL,
                                                        G_PARAM_READWRITE));

  gtk_widget_class_set_template_from_resource (widget_class, "/com/example/raspi-settings/pi-settings-panel-row.ui");

  gtk_widget_class_bind_template_child_private (widget_class, PiSettingsPanelRow, label);
}

void
pi_settings_panel_row_init (PiSettingsPanelRow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}
