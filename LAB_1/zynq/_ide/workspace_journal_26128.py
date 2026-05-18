# 2026-05-18T09:07:50.443649
import vitis

client = vitis.create_client()
client.set_workspace(path="C:/zynq")

platform = client.create_platform_component(name = "zybo_platform",hw_design = "$COMPONENT_LOCATION/../first_zynq_design.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

platform = client.get_component(name="zybo_platform")
status = platform.update_desc(desc="")

status = platform.build()

comp = client.create_app_component(name="led_test",platform = "$COMPONENT_LOCATION/../zybo_platform/export/zybo_platform/zybo_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

vitis.dispose()

