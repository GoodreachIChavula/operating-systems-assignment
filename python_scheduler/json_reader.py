import json


with open("../c_core/pcb_snapshot.json", "r") as file:

    processes = json.load(file)


print("\nPROCESSES LOADED FROM C SIMULATOR\n")


for process in processes:

    print(
        f"PID: {process['pid']} "
        f"| Name: {process['name']} "
        f"| State: {process['state']}"
    )