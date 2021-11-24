import numpy as np
import math

def square(arr,row,col):
    #col = max(map(len, arr))
    #print(col)
    sq_arr= np.zeros([row,col])
    sq_max = 0
    

    for i in range(col):
        sq_arr[0][i] = arr[0][i]

    for i in range(row):
        sq_arr[i][0] = arr[i][0]

    

    for i in range(1,row):
        for j in range(1,col):
            if(arr[i][j]==1):
                sq_arr[i][j] = min(sq_arr[i- 1][j - 1],min(sq_arr[i][j - 1], sq_arr[i - 1][j]))+1
            else:
                sq_arr[i][j] = 0

    #print(sq_arr)
    for i in range(row):
        for j in range(col):
            if (sq_arr[i][j] > sq_max):
                sq_max = sq_arr[i][j]

    mat=math.trunc(sq_max)
    print(">> ",mat,"x",mat,"square matrix")





row = int(input("Enter total number of rows: \n>> "))
arr = [] 
print("Fill row-wise")
for i in range(row):
    arr.append([int(j) for j in input().split()])
col = max(map(len, arr))
square(arr,row,col)


# array = []
# with open('pattern.txt') as file:
#     lines = file.readlines()
# for line in lines:
#     line = line.split()
#     col = []
#     for c in line:
#         col.append(c)
#     array.append(col)
# arr=np.array(array)
# arr=arr.astype(np.uint8)
# row = arr.shape[0]
# col = arr.shape[1]
# square(arr,row,col)