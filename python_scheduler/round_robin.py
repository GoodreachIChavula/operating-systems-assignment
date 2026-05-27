from collections import deque


processes = [

    {"pid": 1, "burst_time": 5},

    {"pid": 2, "burst_time": 3},

    {"pid": 3, "burst_time": 4}
]


quantum = 2


queue = deque(processes)


print("\nROUND ROBIN SCHEDULING\n")


while queue:

    process = queue.popleft()

    pid = process["pid"]

    burst = process["burst_time"]


    if burst > quantum:

        print(f"P{pid} executed for {quantum} units")

        process["burst_time"] -= quantum

        queue.append(process)

    else:

        print(f"P{pid} executed for {burst} units and finished")