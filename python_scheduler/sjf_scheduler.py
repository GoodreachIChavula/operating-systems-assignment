processes = [

    {"pid": 1, "burst_time": 6},

    {"pid": 2, "burst_time": 2},

    {"pid": 3, "burst_time": 8},

    {"pid": 4, "burst_time": 3}
]


processes.sort(key=lambda p: p["burst_time"])


current_time = 0


print("\nSJF SCHEDULING\n")


for process in processes:

    waiting_time = current_time

    turnaround_time = waiting_time + process["burst_time"]

    print(
        f"PID {process['pid']} "
        f"| Burst: {process['burst_time']} "
        f"| Waiting: {waiting_time} "
        f"| Turnaround: {turnaround_time}"
    )

    current_time += process["burst_time"]