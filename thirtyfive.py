# thirtyfive.py by Jacob Steinebronn
# The idea of the solution is 6*s + o

# Take in number of test cases
numTests = (int)(input().strip())

for testNum in range(numTests):
    # Read in s, o and make sure they're of type int
    s, o = list(map(int, input().strip().split()))

    # The answer is s*base^1 + o*base^0
    # So if the base is 6, then the answer is
    # 6s + o
    print(6 * s + o)