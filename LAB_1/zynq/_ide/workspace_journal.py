# 2026-05-18T09:37:15.782953900
import vitis

client = vitis.create_client()
client.set_workspace(path="C:/zynq")

comp = client.get_component(name="led_test")
status = comp.import_files(from_loc="$COMPONENT_LOCATION/..", files=["LED_test_tut_1C.c"], dest_dir_in_cmp = "src", is_skip_copy_sources = False)

platform = client.get_component(name="zybo_platform")
status = platform.build()

comp = client.get_component(name="led_test")
comp.build()

status = platform.build()

comp.build()

vitis.dispose()

