import pandas as pd
import matplotlib.pyplot as plt

best = pd.read_csv("Mergesort.csv")


plt.plot(best["n"], best["time"], marker="o", label=" Worst Case O(nlogn)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Merge  Sort Complexity ")

plt.legend()
plt.grid(True)
plt.show()
