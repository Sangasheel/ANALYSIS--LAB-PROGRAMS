import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv("HOrners.csv")

plt.plot(data["n"],data["time"],label="Worst Case O(n)")

plt.title("Horners MEthod Complexity ")
plt.xlabel(" Degree of Polynomial n ")
plt.ylabel("Time in microseconds (ms)")

plt.grid(True)
plt.legend()
plt.show()
