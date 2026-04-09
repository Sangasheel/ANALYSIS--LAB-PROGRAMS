import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("toh_time.csv")

plt.plot(data["n"], data["time"], marker="o")

plt.xlabel("Number of Disks (n)")
plt.ylabel("Time (microseconds)")
plt.title("Tower of Hanoi Time Complexity (Exponential)")

plt.grid(True)
plt.show()
