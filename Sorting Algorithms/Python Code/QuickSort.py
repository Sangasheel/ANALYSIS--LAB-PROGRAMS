import pandas as pd
import matplotlib.pyplot as plt

best = pd.read_csv("Quicksort.csv")


plt.plot(best["n"], best["time"], marker="o", label=" Worst Case O(n^2)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Quick  Sort Complexity ")

plt.legend()
plt.grid(True)
plt.show()
