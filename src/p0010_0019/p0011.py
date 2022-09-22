# What is the greatest product of four adjacent numbers in the same direction 
# (up, down, left, right, or diagonally) in the 20×20 grid?

from pathlib import Path

def get_grid():
    f = open(Path(__file__).parent / "../../files/p0011.txt","r")
    grid = []
    for line in f.readlines():
        entries = line.replace("\n", "").split(" ")
        entries = [int(entry) for entry in entries]
        grid.append(entries)
    return grid

def get_down(x,y):
    return [(x, y+i) for i in range(4)]

def get_right(x,y):
    return [(x+i, y) for i in range(4)]

def get_diagonaldown(x,y):
    return [(x+i, y+i) for i in range(4)]

def get_diagonalup(x,y):
    return [(x+i, y-i) for i in range(4)]

def get_res(grid, pos):
    res = 1
    for p in pos: res = res*grid[p[1]][p[0]]
    return res

def __main__():
    res = 0
    grid = get_grid()
    for x in range(len(grid[0])-3):
        for y in range(len(grid)):
            temp = get_res(grid, get_right(x, y))
            if temp > res: res = temp
    for x in range(len(grid[0])):
        for y in range(len(grid)-3):
            temp = get_res(grid, get_down(x, y))
            if temp > res: res = temp
    for x in range(len(grid[0])-3):
        for y in range(len(grid)-3):
            temp = get_res(grid, get_diagonaldown(x, y))
            if temp > res: res = temp
    for x in range(len(grid[0])-3):
        for y in range(3, len(grid)):
            temp = get_res(grid, get_diagonalup(x, y))
            if temp > res: res = temp

    print(res)

__main__()