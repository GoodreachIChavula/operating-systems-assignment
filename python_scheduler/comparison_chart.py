import matplotlib.pyplot as plt


algorithms = [

    "FCFS",
    "SJF",
    "Priority",
    "Round Robin"
]


waiting_times = [

    5.3,
    3.1,
    4.0,
    3.8
]


plt.bar(algorithms, waiting_times)

plt.xlabel("Scheduling Algorithms")

plt.ylabel("Average Waiting Time")

plt.title("Scheduling Algorithm Comparison")


plt.savefig("../docs/screenshots/comparison_chart.png")

plt.show()