from collections import deque
import matplotlib.pyplot as plt


processes = [

    {"pid": 1, "burst_time": 5},

    {"pid": 2, "burst_time": 3},

    {"pid": 3, "burst_time": 4}
]


quantum = 2


queue = deque(processes)


current_time = 0


fig, ax = plt.subplots()


while queue:

    process = queue.popleft()

    pid = process["pid"]

    burst = process["burst_time"]


    execution_time = min(quantum, burst)


    ax.barh(
        y="CPU",
        width=execution_time,
        left=current_time
    )

    ax.text(
        current_time + execution_time / 2,
        0,
        f"P{pid}",
        ha='center',
        va='center'
    )


    current_time += execution_time


    process["burst_time"] -= execution_time


    if process["burst_time"] > 0:

        queue.append(process)


ax.set_xlabel("Time")

ax.set_title("Round Robin Gantt Chart")


plt.show()