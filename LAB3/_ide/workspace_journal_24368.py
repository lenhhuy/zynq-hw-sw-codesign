# 2026-05-25T08:29:09.499647400
import vitis

client = vitis.create_client()
client.set_workspace(path="LAB3")

comp = client.create_hls_component(name = "matrix_mult_prj",cfg_file = ["hls_config.cfg"],template = "empty_hls_component")

