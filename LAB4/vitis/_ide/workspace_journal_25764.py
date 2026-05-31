# 2026-05-27T10:46:22.454696200
import vitis

client = vitis.create_client()
client.set_workspace(path="vitis")

platform = client.create_platform_component(name = "led_platform",hw_design = "$COMPONENT_LOCATION/../../axi_counter_zybo/led_ctrl_zybo.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

platform = client.get_component(name="led_platform")
status = platform.build()

