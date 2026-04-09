import pandas as pd
import matplotlib.pyplot as plt

# Load CSV files
best = pd.read_csv("linear_worst_case.csv")

plt.plot(best["n"], best["time"])
plt.xlabel("n")
plt.ylabel("Time (ns)")
plt.title("Best Case Linear Search O(n)")
plt.show()


# Legend
plt.legend()

# Show Graph
plt.show()
