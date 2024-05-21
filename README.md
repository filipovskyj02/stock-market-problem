# Infinite Money Glitch. Maybe

Your friend recently discovered margin trading, which involves trading with borrowed money, and claims it's an "infinite money glitch." Help your friend test it by analyzing historical stock price data.

In margin trading, you can leverage your investment by borrowing money from a broker. For example, if you invest $1 with 5x leverage, the broker lends you $4, making your total position worth $5.

Let's expand on the example above with two scenarios:

    1) The asset's price doubles, your position becomes worth $10. After repaying the $4 loan to the broker, you're left with $6, resulting in a 500% return on a 100% price movement of the underlying asset.
    2) The asset's price drops by 20%, your position becomes worth $4. Since you still owe $4 to the broker, your position is automatically closed - liquidated, leaving you with $0, resulting in a 100% loss.
    Note that this happens as soon as the position is worth the borrowed amount, not less - the broker wants to make sure he gets all his money back

As you can see a leverage of 5x is a way to amplify your gains or losses 5 times. And the same goes for any other multiple.

# Input Specification

    The input consists of several test cases T (1 <= T <= 10).
    The first line of each test case contains an integer N (2 <= N <= 100 000), indicating the number of stock price data points.
    The second line contains N stock price data points P (0 < P < 1 000 000) separated by spaces.
    The third line contains an integer Q (1 ≤ Q ≤ 1 000 000), representing the number of queries about the dataset.
    The following Q lines each contain three integers l, r, and k (0 <= l < r < N , 1 ≤ k ≤ 2000), indicating queries between two different time points of the dataset (zero - indexed) and specifying the leverage multiple used.

# Output Specification

For each query, determine if your friend will be liquidated in the specified interval of price points using the specified leverage and print out either 'liquidated' or 'not-liquidated'   
Liquidation occurs when the investment value drops below the borrowed amount, resulting in a total loss.

Example
1)
```
Input:
1
9
1 2 3 4 5 2 2 2 100
4
0 8 5
2 8 5
2 8 2
2 8 4
Output:
not-liquidated
liquidated
not-liquidated
liquidated
```
2)
```
Input:
1
10
154 123 133 167 178 220 139 77 82 105
5
0 7 2
1 9 3
1 6 100
5 6 4 
0 9 1  
Output:
liquidated
liquidated
not-liquidated
liquidated
not-liquidated
```