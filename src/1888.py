def minFlips(s: str) -> int:
    n = len(s)
    s2 = s + s

    alt1 = ""
    alt2 = ""

    for i in range(len(s2)):
        if i % 2 == 0:
            alt1 += "0"
            alt2 += "1"
        else:
            alt1 += "1"
            alt2 += "0"

    diff1 = diff2 = 0
    res = n

    left = 0
    for right in range(len(s2)):
        if s2[right] != alt1[right]:
            diff1 += 1
        if s2[right] != alt2[right]:
            diff2 += 1

        if right - left + 1 > n:
            if s2[left] != alt1[left]:
                diff1 -= 1
            if s2[left] != alt2[left]:
                diff2 -= 1
            left += 1

        if right - left + 1 == n:
            res = min(res, diff1, diff2)

    return res

if __name__ == '__main__':
    ans = minFlips("1110")
    print(ans)