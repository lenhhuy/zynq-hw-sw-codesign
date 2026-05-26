# 2026-05-26T18:45:15.726724200
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB3")

comp = client.get_component(name="matrix_mult_prj_solution1")
comp.run(operation="CO_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.get_component(name="matrix_mult_prj_solution3")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

comp = client.get_component(name="matrix_mult_prj_solution1")
comp.run(operation="C_SIMULATION")

comp.run(operation="SYNTHESIS")

comp.run(operation="CO_SIMULATION")

vitis.dispose()

