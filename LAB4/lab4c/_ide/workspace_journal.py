# 2026-06-01T09:10:47.916215100
import vitis

client = vitis.create_client()
client.set_workspace(path="lab4c")

comp = client.create_hls_component(name = "hls_nco",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

comp = client.get_component(name="hls_nco")
comp.run(operation="C_SIMULATION")

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB4\lab4c\hls_nco\hls_config.cfg")

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="tb.file", values=[])

cfg.set_values(key="syn.file", values=["../nco.cpp"])

cfg.set_values(key="tb.file", values=["../nco_test.cpp"])

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="PACKAGE")

