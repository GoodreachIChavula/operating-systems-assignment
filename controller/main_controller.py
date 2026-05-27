import subprocess
import json


print("\nRUNNING C SIMULATOR...\n")


subprocess.run("../c_core/eduos.exe")


print("\nREADING PCB JSON...\n")


with open("../c_core/pcb_snapshot.json", "r") as file:

    processes = json.load(file)


print("PROCESSES:\n")


for process in processes:

    print(process)