# Everything about string

## Brute-force pattern matching

```
BruteForceMatch(T, P):
    input: T of length t, P of length p

for all start = 0 to t-p do
    pointer = 0
    while pointer < p and T[start, pointer] = P[pointer] do
        pointer++
    end while
    if pointer = p then     // not break mean entire pattern has been checkecd
        return start
    end if
end for
return -1

complexity: O(t * p)
if p is constant, then O(t)
```

## Boyer-Moore Algorithm

- looking-glass heuristic

    Compare P with subsequence of T moving backwards

- Character-jump heuristic

    When a mismatch occurs at T[i] = c

    - if P contains c -> shift to align the last occurrence of c in P
    - otherwise -> shift P so as to align with T[i+1]

### last-occurrence function

- L contains the largest index i of P[i] = c
- or -1 if no index exists
- L can be computed in O(a + p)

### pseudo code

```
BoyerMooreMatch(T, P， A):

    t = length(T) - 1   // pointer in text
    p = length(P) - 1   // pointer in pattern

    if T[t] = P[p] then
        if p = 0 then
            return t
        else 
            t--
            p--
        end if
    else
        t += length(P) - min(p, 1+L[T[t]])    // pointer in text
        p = length(P) - 1    // pointer in pattern
    end if
```