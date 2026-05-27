processes = [

    {"pid": 1, "priority": 3, "burst_time": 5},

    {"pid": 2, "priority": 1, "burst_time": 2},

    {"pid": 3, "priority": 4, "burst_time": 4},

    {"pid": 4, "priority": 2, "burst_time": 3}
]


processes.sort(key=lambda p: p["priority"])


current_time = 0


print("\nPRIORITY SCHEDULING\n")


for process in processes:

    waiting_time = current_time

    turnaround_time = waiting_time + process["burst_time"]

    print(
        f"PID {process['pid']} "
        f"| Priority: {process['priority']} "
        f"| Waiting: {waiting_time}"
    )

    current_time += process["burst_time"]