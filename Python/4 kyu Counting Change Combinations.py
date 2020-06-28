def count_change(money, coins):
    coins = sorted(coins)
    def dfs(pos, left):
        if pos == len(coins): return 0
        elif left < coins[pos]: return left == 0
        else: return dfs(pos+1, left) + dfs(pos, left-coins[pos])
    return dfs(0, money)