import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv("Permutation.csv")

plt.plot(data["n"],data["time"],marker="o")
plt.title("N! for Permutations ")
plt.xlabel("No of operations n ")
plt.ylabel("Time taken in microsecond ")

plt.legend()
plt.grid=True
plt.show()
