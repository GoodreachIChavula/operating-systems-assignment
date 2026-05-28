import matplotlib.pyplot as plt


processes = [

    {"pid": 1, "priority": 3, "burst_time": 5},

    {"pid": 2, "priority": 1, "burst_time": 2},

    {"pid": 3, "priority": 4, "burst_time": 4},

    {"pid": 4, "priority": 2, "burst_time": 3}
]


processes.sort(key=lambda p: p["priority"])


current_time = 0


fig, ax = plt.subplots()


for process in processes:

    ax.barh(
        y="CPU",
        width=process["burst_time"],
        left=current_time
    )

    ax.text(
        current_time + process["burst_time"] / 2,
        0,
        f"P{process['pid']}",
        ha='center',
        va='center'
    )

    current_time += process["burst_time"]


ax.set_xlabel("Time")

ax.set_title("Priority Scheduling Gantt Chart")

plt.savefig("../docs/screenshots/priority_scheduling_gantt.png")

plt.show()