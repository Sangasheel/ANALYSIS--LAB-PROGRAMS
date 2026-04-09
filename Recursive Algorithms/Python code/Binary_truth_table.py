import pandas as pd
import matplotlib.pyplot as plt 


data=pd.read_csv("BinaryTruth.csv")

plt.plot(data["n"], data["time"],label="WorstCase O(2^n)")
plt.title("Binary Truth Table Complexity ")
plt.xlabel(" Input size (n)")
plt.ylabel(" Time in microseconds (ms)")

plt.legend()
plt.grid(True)
plt.show()
