import pandas as pd
import matplotlib.pyplot as plt

# worst=pd.read_csv("selection_worst_case.csv")
best=pd.read_csv("selection_best_case.csv")

# plt.plot(worst["n"],worst["time"],marker="o",label="Worst Case O(n^2)")
plt.plot(best["n"],best["time"],marker="o",label="Best Case O(n^2)")

plt.xlabel("Input Size n ")
plt.ylabel(" Time ")


plt.title("Selection Sort time Complexity ")
plt.grid(True)
plt.legend()
plt.show()