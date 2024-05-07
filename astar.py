import copy

def gn(state, finalstate):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != -1 and state[i][j] != finalstate[i][j]:
                count += 1
    return count

def findposblank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == -1:
                return [i, j]
    return None

def move_left(state, pos):
    if pos[1] == 0:
        return None
    retarr = copy.deepcopy(state)
    retarr[pos[0]][pos[1]], retarr[pos[0]][pos[1]-1] = retarr[pos[0]][pos[1]-1], retarr[pos[0]][pos[1]]
    return retarr

def move_up(state, pos):
    if pos[0] == 0:
        return None
    retarr = copy.deepcopy(state)
    retarr[pos[0]][pos[1]], retarr[pos[0]-1][pos[1]] = retarr[pos[0]-1][pos[1]], retarr[pos[0]][pos[1]]
    return retarr
    
def move_right(state, pos):
    if pos[1] == 2:
        return None
    retarr = copy.deepcopy(state)
    retarr[pos[0]][pos[1]], retarr[pos[0]][pos[1]+1] = retarr[pos[0]][pos[1]+1], retarr[pos[0]][pos[1]]
    return retarr

def move_down(state, pos):
    if pos[0] == 2:
        return None
    retarr = copy.deepcopy(state)
    retarr[pos[0]][pos[1]], retarr[pos[0]+1][pos[1]] = retarr[pos[0]+1][pos[1]], retarr[pos[0]][pos[1]]
    return retarr

def printM(matArr):
    print("")
    count = 1
    for matrix in matArr:
        print("Step {}".format(count))
        for row in matrix:
            print(row)
        count += 1
        print("")

def eightpuzzle(initialstate, finalstate):
    hn = 0
    explored = []
    while True:
        explored.append(initialstate)
        if initialstate == finalstate:
            break
        pos_blank = findposblank(initialstate)
        if pos_blank is None:
            print("Error: Blank tile not found in the puzzle state!")
            return
        left = move_left(initialstate, pos_blank)
        right = move_right(initialstate, pos_blank)
        up = move_up(initialstate, pos_blank)
        down = move_down(initialstate, pos_blank)
        fnl = 1000 if left is None else hn + gn(left, finalstate)
        fnr = 1000 if right is None else hn + gn(right, finalstate)
        fnu = 1000 if up is None else hn + gn(up, finalstate)
        fnd = 1000 if down is None else hn + gn(down, finalstate)
        minfn = min(fnl, fnr, fnu, fnd)
        if fnl == minfn and left not in explored:
            initialstate = left
        elif fnr == minfn and right not in explored:
            initialstate = right
        elif fnu == minfn and up not in explored:
            initialstate = up
        elif fnd == minfn and down not in explored:
            initialstate = down
    printM(explored)

def main():
    while True:
        ch = int(input("1 to continue, 0 for exit:\n"))
        if not ch:
            break
        start = []
        print("Start State: \n")
        for i in range(3):
            arr = []
            for j in range(3):
                a = int(input("Enter element at {},{}: ".format(i, j)))
                arr.append(a)
            start.append(arr)
        final = []
        print("Final state: \n")
        for i in range(3):
            arr = []
            for j in range(3):
                a = int(input("Enter element at {},{}: ".format(i, j)))
                arr.append(a)
            final.append(arr)
        eightpuzzle(start, final)

if __name__ == "__main__":
    main()
