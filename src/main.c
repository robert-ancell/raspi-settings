/*
 * Copyright (C) 2020 Robert Ancell.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 or version 3 of the License.
 * See http://www.gnu.org/copyleft/lgpl.html the full text of the license.
 */

#include "pi-settings-app.h"

int
main (int argc, char **argv)
{
   g_autoptr(PiSettingsApp) app = pi_settings_app_new ();

   return g_application_run (G_APPLICATION (app), argc, argv);
}
