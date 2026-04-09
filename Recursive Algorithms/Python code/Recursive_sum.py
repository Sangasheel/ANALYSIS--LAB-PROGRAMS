import pandas as pd
import matplotlib.pyplot as plt
worst=pd.read_csv("sum_time2.csv")

plt.plot(worst["n"],worst["time"],marker="o",label="Worst Case O(n)")
plt.title("Recursive sum complexity ")
plt.xlabel("Number of operations n ")
plt.ylabel("Time taken ")
plt.legend()
plt.grid=True
plt.show()