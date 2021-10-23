import java.util.*;

public class triangles {
	// the maximum length of a stick we could have
	static final int maxLength = 2_000;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// test cases
		int n = sc.nextInt();
		for(int tt = 1; tt <= n; ++tt) {
			// number of sticks
			int m = sc.nextInt();
			// array of sticks
			int[] arr = new int[m];
			for(int i = 0; i < m; ++i) {
				arr[i] = sc.nextInt();
			}
			// we will sort the array to make our lives easier
			Arrays.sort(arr);
			
			// for this problem, we will use a brute force method to solve
			// it; for a triangle with side lengths a, b, and c, such that
			// a <= b <= c, we can brute force a and b and count the number
			// of suitable c values that would give us an acute, right, and
			// obtuse triangle; if we can do this last step efficiently, we
			// can solve the problem
			
			// the formula for right triangles of lengths a, b, and c where
			// a <= b <= c is a^2 + b^2 = c^2
			// we can observe that if a^2 + b^2 < c^2, then our large side is
			// too large to form a right triangle, so it must be obtuse
			// similarly, if a^2 + b^2 > c^2, then our large side is too small
			// to form a right triangle, so it must be acute
			
			// assuming the triangles are non degenerate, i.e., a + b > c, this
			// will be all the observations needed to solve the problem
			
			// we will set up a large array that will store a "prefix sum" of the
			// possible values of c^2
			// if you have not heard about prefix sums, you can look them up online
			// this prefix sum will allow us to find the number of suitable values
			// of c^2 in a range in O(1) time
			
			int[] numC2s = new int[maxLength * maxLength + 1];
			for(int c : arr) {
				++numC2s[c * c];
			}
			
			int[] preC2s = new int[maxLength * maxLength + 1];
			for(int i = 0; i < preC2s.length; ++i) {
				preC2s[i] = numC2s[i];
				// add the value of the index behind us to keep a sum of this prefix
				if(i > 0) {
					preC2s[i] += preC2s[i - 1];
				}
			}
			
			int numAcute = 0, numRight = 0, numObtuse = 0;
			for(int aIdx = 0; aIdx < m; ++aIdx) {
				int a = arr[aIdx];
				// keep aIdx < bIdx so that a < b
				for(int bIdx = aIdx + 1; bIdx < m; ++bIdx) {
					int b = arr[bIdx];
					
					// now that we have a and b, find the number of c^2s that give us...
					
					// an acute triangle:
					// b < c   --->   b^2 < c^2
					// b^2 < c^2 < a^2 + b^2
					numAcute += range(preC2s, b * b + 1, a * a + b * b - 1);
					
					// a right triangle:
					// a^2 + b^2 <= c^2 <= a^2 + b^2
					numRight += range(preC2s, a * a + b * b, a * a + b * b);
					
					// an obtuse triangle:
					// c < a + b   --->   c^2 < (a + b)^2
					// a^2 + b^2 < c^2 < (a + b)^2
					numObtuse += range(preC2s, a * a + b * b + 1, (a + b) * (a + b) - 1);
				}
			}
			
			// total runtime: O(m^2 + maxLength^2)
			
			// print
			System.out.println(numAcute + " " + numRight + " " + numObtuse);
		}
	}
	// this helper function helps us extract the range on the given prefix sum
	static int range(int[] pre, int l, int r) {
		// if the right pointer is too big, adjust it
		if(r >= pre.length) {
			r = pre.length - 1;
		}
		// if the left pointer is too small, adjust it
		if(l < 0) {
			l = 0;
		}
		
		// if the range [l, r] is empty, return 0
		if(l > r) {
			return 0;
		}
		
		// include [0, r]
		int out = pre[r];
		// exclude [0, l - 1]
		if(l > 0) {
			out -= pre[l - 1];
		}
		
		return out;
	}
}
/*

the sample data for convenience:

3
4 3 4 5 8
5 1 3 4 5 6
5 1 2 3 4 5

*/
