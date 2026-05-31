# 2026-06-01T00:08:36.033240400
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis")

platform = client.get_component(name="led_platform")
status = platform.build()

comp = client.get_component(name="led_app")
comp.build()

status = platform.build()

status = platform.build()

comp.build()

client.delete_component(name="led_app")

client.delete_component(name="componentName")

client.delete_component(name="componentName")

comp = client.create_app_component(name="led_app",platform = "$COMPONENT_LOCATION/../led_platform/export/led_platform/led_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

vitis.dispose()

