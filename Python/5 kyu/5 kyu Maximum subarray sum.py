def max_sequence(arr):
    sum = [0]*(len(arr)+1)
    for i in range(len(arr)): sum[i+1] = arr[i] + sum[i]
    ans = 0
    for i in range(len(arr)): 
        for j in range(i, len(arr)): ans = max(ans, sum[j+1] - sum[i])
    return ans