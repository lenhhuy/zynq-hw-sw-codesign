# 2026-05-21T02:00:48.130859800
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB2")

platform = client.get_component(name="zynq_interrupt_platform")
status = platform.build()

comp = client.get_component(name="interrupt_counter")
comp.build()

vitis.dispose()

