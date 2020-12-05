sources = files(
  'main.c',
  'pi-settings-app.c',
  'pi-settings-window.c',
)

resource_files = files(
  'pi-settings-window.ui',
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
