import sys

def solve():

    # Get the full line from input
    word = sys.stdin.readline()

    # Remove newline from end
    word.rstrip('\n')

    # Split it by space
    letters = word.split()

    # Calculate every letter by length
    for l in letters:
        print(chr(ord('A')+len(l)-1), end="")
    print()

if __name__ == "__main__":
    cases = int(input())
    for _ in range(cases):
        solve()