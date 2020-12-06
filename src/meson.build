sources = files(
  'main.c',
  'pi-date-time-panel.c',
  'pi-display-panel.c',
  'pi-hardware-panel.c',
  'pi-keyboard-panel.c',
  'pi-language-panel.c',
  'pi-mouse-panel.c',
  'pi-network-panel.c',
  'pi-printer-panel.c',
  'pi-security-panel.c',
  'pi-settings-app.c',
  'pi-settings-panel.c',
  'pi-settings-panel-row.c',
  'pi-settings-window.c',
  'pi-settings-panel.c',
  'pi-sound-panel.c',
  'pi-startup-panel.c',
)

resource_files = files(
  'pi-date-time-panel.ui',
  'pi-display-panel.ui',
  'pi-hardware-panel.ui',
  'pi-keyboard-panel.ui',
  'pi-language-panel.ui',
  'pi-mouse-panel.ui',
  'pi-network-panel.ui',
  'pi-printer-panel.ui',
  'pi-security-panel.ui',
  'pi-settings-panel-row.ui',
  'pi-settings-window.ui',
  'pi-sound-panel.ui',
  'pi-startup-panel.ui',
)

sources += gnome.compile_resources(
  'pi-settings-resources',
  'pi-settings.gresource.xml',
  dependencies: resource_files,
  export: true,
)

executable(
  'raspi-settings',
  sources,
  dependencies: dependency('gtk+-3.0', version: '>= 3.22'),
)
