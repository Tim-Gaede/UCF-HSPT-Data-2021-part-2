# triangles.py by Jacob Steinebronn

# Get number of test cases
numTests = (int)(input().strip())

# For each testcase
for testNum in range(numTests):
    # Get the input
    arr = list(map(int, input().strip().split()))
    # N is the first element of the array
    n = arr[0]
    # The actual array is the array, excluding the first element, so slice out the first element
    arr = arr[1:]
    # sort for convenience
    arr.sort()

    maxel = arr[n-1] # maximum element
    squares = [0]*((2*maxel)**2 + 10) # Array of sticks^2, of size 2*maxel^2
    psquares = [0]*((2*maxel)**2 + 10) # prefix sum of squares
    

    for stick in arr:
        squares[stick*stick] = 1
    
    # Set up the prefix sum of squares of stick lengths
    for i in range(1, len(squares), 1):
        psquares[i] = squares[i] + psquares[i-1]
    
    acute = 0
    right = 0
    obtuse = 0

    for i in range(n):
        for j in range(i+1, n, 1):
            a = arr[i]
            b = arr[j]
            # Since sorted, b > a guaranteed

            # There is only one option to make a right triangle
            right += squares[a**2+b**2]
            # Anything between b^2 - a^2+b^2 is an acute triangle
            acute += psquares[a**2+b**2 - 1] - psquares[b**2]
            # Anything between a^2+b^2+1 - (a+b)^2-1 is an obtuse triangle
            obtuse += psquares[(a+b)**2 - 1] - psquares[a**2+b**2]
    
    # Print solution
    print(acute, right, obtuse)
