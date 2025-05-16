# PayPath 
**PayPath** is a smart, efficient, and minimalistic C++ application that automates debt settlement among a group of individuals. It calculates the optimal set of transactions required so everyone is paid or repaid with the **fewest number of payments possible**. Clearing the payment dues among friends or known people, even when people have to pretend to be generous, every individual must be paid what they are owed. Hence, the idea arose, and using C++, the idea is created, and even though this is a base prototype, it gives the idea of working behind the actual application created.

Features:

- Automatically determines who pays whom and how much
- Ensures all debts are resolved to zero
- Uses a recursive algorithm for settlement
- Supports extensibility via object-oriented design
- Accurate rounding for financial transactions

Here's the idea of how it works and the streamlining of its execution:
Each person is represented with a balance:
- **Positive balance** → money to be received
- **Negative balance** → money to be paid
The system matches the **maximum creditor** with the **maximum debtor**, and performs a transaction between them. This continues until all balances are settled.

Technologies Used
1. **C++** (Object-Oriented)
2. STL Containers: `vector`, `unordered_map`, `algorithm`
3. Precision handling with `cmath` and `iomanip`

Let us take an example
Input >> 
A: -5.0  
B: 25.0  
C: -20.0  
D: 25.0  
E: -20.0  
F: -5.0

Output <<
C needs to pay B: 20.00  
E needs to pay D: 20.00  
A needs to pay B: 5.00  
F needs to pay D: 5.00

Final Balances:
All individuals end up with a net balance of 0.0 – settlement achieved!

How to Run: 
g++ SplitEase.cpp -o SplitEase
./SplitEase
