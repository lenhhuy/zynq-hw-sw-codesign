# 2026-05-20T08:48:23.750893400
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB2")

platform = client.create_platform_component(name = "zynq_interrupt_platform",hw_design = "$COMPONENT_LOCATION/../zynq_interrupts/zynq_interrupt_system_wrapper.xsa",os = "standalone",cpu = "ps7_cortexa9_0",domain_name = "standalone_ps7_cortexa9_0",compiler = "gcc")

platform = client.get_component(name="zynq_interrupt_platform")
status = platform.build()

comp = client.create_app_component(name="interrupt_counter",platform = "$COMPONENT_LOCATION/../zynq_interrupt_platform/export/zynq_interrupt_platform/zynq_interrupt_platform.xpfm",domain = "standalone_ps7_cortexa9_0")

status = platform.build()

comp = client.get_component(name="interrupt_counter")
comp.build()

status = platform.build()

comp.build()

status = platform.update_hw(hw_design = "$COMPONENT_LOCATION/../zynq_interrupts/zynq_interrupt_system_wrapper.xsa")

status = platform.build()

comp = client.get_component(name="interrupt_counter")
status = comp.import_files(from_loc="D:\Semester 6\COMBINED HW AND SW DESIGN", files=["interrupt_counter_2D_SDT.c"], dest_dir_in_cmp = "src", is_skip_copy_sources = False)

status = platform.build()

comp = client.get_component(name="interrupt_counter")
comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.remove_boot_bsp()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

status = platform.build()

comp.build()

