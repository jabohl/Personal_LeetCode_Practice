/**
 * LeetCode Problem: Fibonacci Number (LeetCode 509)
 *
 * Problem Description:
 * The Fibonacci numbers, commonly denoted F(n), form a sequence such that
 * each number is the sum of the two preceding ones, starting from 0 and 1.
 * F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1
 *
 * Example:
 * Input: n = 2
 * Output: 1
 *
 * Input: n = 3
 * Output: 2
 *
 * Input: n = 4
 * Output: 3
 *
 * Constraints:
 * 0 <= n <= 30
 *
 * Time Complexity: O(2^n) - exponential due to recursive calls
 * Space Complexity: O(n) - recursion stack depth
 *
 * Note: This is a simple recursive solution. For better performance,
 * consider using dynamic programming or memoization.
 */

/**
 * Calculate the nth Fibonacci number using recursion.
 *
 * Args:
 *     sequencePosition: The position in the Fibonacci sequence (0-indexed)
 *
 * Returns:
 *     The Fibonacci number at the given position
 */
int fib(int sequencePosition) {
    if (sequencePosition < 2) {
        return sequencePosition;
    }
    return fib(sequencePosition - 1) + fib(sequencePosition - 2);
}
