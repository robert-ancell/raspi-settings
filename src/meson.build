sources = files(
  'main.c',
  'pi-network-panel.c',
  'pi-settings-app.c',
  'pi-settings-panel.c',
  'pi-settings-window.c',
  'pi-sound-panel.c',
)

resource_files = files(
  'pi-network-panel.ui',
  'pi-settings-window.ui',
  'pi-sound-panel.ui',
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
