# 2026-05-25T11:18:42.772954300
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB3")

comp = client.get_component(name="matrix_mult_prj_solution2")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.get_component(name="matrix_mult_prj_solution3")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.clone_component(name="matrix_mult_prj",new_name="matrix_mult_prj_solution4")

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution4\hls_config.cfg")

cfg.set_values(key="syn.file", values=["..\tut3A\matrix_mult.h"])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="tb.file", values=[])

cfg.set_values(key="syn.file", values=["../solution4/matrix_mult.cpp", "../solution4/matrix_mult.h"])

cfg.set_values(key="tb.file", values=["../solution4/matrix_mult_test.cpp"])

comp = client.clone_component(name="matrix_mult_prj",new_name="matrix_mult_prj_solution5")

cfg = client.get_config_file(path="D:\Semester_6\HWSW\LAB3\matrix_mult_prj_solution5\hls_config.cfg")

cfg.set_values(key="syn.file", values=["..\tut3A\matrix_mult.h"])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="syn.file", values=[])

cfg.set_values(key="syn.blackbox.file", values=[])

cfg.set_values(key="tb.file", values=[])

cfg.set_values(key="syn.file", values=["../solution5/matrix_mult.cpp", "../solution5/matrix_mult.h"])

cfg.set_values(key="tb.file", values=["../solution5/matrix_mult_test.cpp"])

comp = client.get_component(name="matrix_mult_prj_solution4")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.get_component(name="matrix_mult_prj_solution5")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

vitis.dispose()

