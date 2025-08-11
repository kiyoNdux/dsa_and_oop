# **Sorting an Array** (Bubble Sort)

**Goal:**

Sort the elements of an array in ascending order using the **Bubble Sort** algorithm.

**Steps**

1. **Initialize the array**

   * Start with an unsorted array of integers.
   * Define the maximum size (`maxSize`) and the number of currently used elements (`lengthOfArray`).

2. **Display the initial array**

   * Loop through the array and print its current state for comparison before sorting.

3. **Outer loop – Number of passes**

   * Use a loop (`i` from 0 to `lengthOfArray - 1`) to repeat the process enough times so that all elements are sorted.
   * Each pass ensures that the largest remaining unsorted element “bubbles up” to its correct position at the end of the array.

4. **Inner loop – Comparing adjacent elements**

   * Iterate (`j` from 0 to `lengthOfArray - 2`) through the array, comparing each element with its neighbor.
   * If `compScieSubjects[j]` is greater than `compScieSubjects[j+1]`, **swap** them.

5. **Swapping mechanism**

   * Use a temporary variable to hold the value during the swap so no data is lost.

6. **Repeat until sorted**

   * Continue outer loop passes until no more swaps are needed (in this version, we simply loop `lengthOfArray` times without early exit optimization).

7. **Display the sorted array**

   * After sorting, print the array again to show the final result.
