#Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

from pathlib import Path

def get_numbers():
    f = open(Path(__file__).parent / "../../files/p0013.txt","r")
    lines = f.readlines()
    lines = [l.replace("\n", "") for l in lines]
    return lines

def __main__():
    numbers = get_numbers()
    n = [int(k) for k in numbers]
    print(str(sum(n))[0:10])

__main__()