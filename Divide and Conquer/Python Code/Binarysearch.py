import pandas as pd
import matplotlib.pyplot as plt

best = pd.read_csv("binary_best_case.csv")
worst = pd.read_csv("binary_worst_case.csv")

plt.plot(best["n"], best["time"], marker="o", label="Best Case O(1)")
plt.plot(worst["n"], worst["time"], marker="o", label="Worst Case O(log n)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (ns or µs)")
plt.title("Binary Search Time Complexity")

plt.legend()
plt.grid(True)
plt.show()
