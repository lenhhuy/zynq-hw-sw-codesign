# 2026-05-25T08:49:12.016274300
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB3")

comp = client.get_component(name="matrix_mult_prj")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.clone_component(name="matrix_mult_prj",new_name="matrix_mult_prj_solution2")

comp = client.get_component(name="matrix_mult_prj_solution2")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.clone_component(name="matrix_mult_prj",new_name="matrix_mult_prj_solution3")

comp = client.get_component(name="matrix_mult_prj_solution3")
comp.run(operation="SYNTHESIS")

comp.run(operation="C_SIMULATION")

comp = client.get_component(name="matrix_mult_prj")
comp.run(operation="IMPLEMENTATION")

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution2\hls_config.cfg")

cfg.set_values(key="syn.file", values=["..\tut3A\matrix_mult.h"])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution3\hls_config.cfg")

cfg.set_values(key="syn.file", values=["..\tut3A\matrix_mult.h"])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution2\hls_config.cfg")

cfg.set_values(key="tb.file", values=[])

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution3\hls_config.cfg")

cfg.set_values(key="tb.file", values=[])

cfg.set_values(key="syn.file", values=["../solution3/matrix_mult.cpp", "../solution3/matrix_mult.h"])

cfg.set_values(key="tb.file", values=["../solution3/matrix_mult_test.cpp"])

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution2\hls_config.cfg")

cfg.set_values(key="syn.file", values=["../solution3/matrix_mult.cpp", "../solution3/matrix_mult.h"])

cfg.set_values(key="syn.file", values=["../solution3/matrix_mult.h"])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=["../solution2/matrix_mult.cpp", "../solution2/matrix_mult.h"])

cfg.set_values(key="tb.file", values=["../solution2/matrix_mult_test.cpp"])

comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

vitis.dispose()

