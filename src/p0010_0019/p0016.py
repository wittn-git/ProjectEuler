#What is the sum of the digits of the number 2^1000?

def add(numbers):
    max_len = max([len(n) for n in numbers])
    for i, n in enumerate(numbers): numbers[i] = (max_len-len(n))*"0"+n
    pos, carry, res = max_len-1, 0, ""
    while(pos >= 0):
        temp = carry
        for n in numbers: temp += int(n[pos])
        res = str(str(temp)[-1])+res
        if(temp > 9): carry = int(str(temp[0:-1])) 
        else: carry = 0
        pos -= 1
    if carry > 0: res = str(carry) + res
    return res

def multiply(a, b):
    numbers = [str(int(a[i])*b)+(len(a)-1-i)*"0" for i in range(len(a))]
    return add(numbers)


def __main__():
    mult_res = "1"
    for _ in range(1000):
        mult_res = multiply(mult_res, 2)
    res = 0
    for i in mult_res:
        res += int(i)
    print(res)
    print(sum([int(i) for i in str(pow(2,1000))]))
    

__main__()