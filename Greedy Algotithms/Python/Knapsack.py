import matplotlib.pyplot as plt;
import pandas as pd

PP=pd.read_csv("PP.csv")

PR=pd.read_csv("PR.csv")

PW=pd.read_csv("PW.csv")

PP = PP.sort_values("weight")
PW = PW.sort_values("weight")
PR = PR.sort_values("weight")

plt.plot(PP["weight"],PP["profit"],label="By Profit",marker="o")

plt.plot(PW["weight"],PW["profit"],label="By Weight ",marker="o")

plt.plot(PR["weight"],PR["profit"],label="By Ratio",marker="o")

plt.title("Different methods for Profit Evaluation ")

plt.legend()


plt.xlabel("Weight ")
plt.ylabel("Max Profit")

plt.grid(True)

plt.show()


