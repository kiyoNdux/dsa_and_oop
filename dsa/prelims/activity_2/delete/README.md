# **Deleting a Value from an Array**

**Goal:**

Remove a specific element from the array and shift the remaining elements so there are no gaps.

**Steps:**

1. **Set up the data**

   * Have an array with some elements already stored.
   * Track the current number of elements with `lengthOfArray`.
   * Decide which value you want to remove (`valueToDelete`).

2. **Find the index of the value to delete**

   * Loop through the array from index `0` to `lengthOfArray - 1`.
   * Compare each element with `valueToDelete`.
   * When a match is found, store that index in `indexOftheValueToDelete` and break the loop.

3. **Shift elements left**

   * Starting from `indexOftheValueToDelete`, assign each element to the value of the next element:

     ```
     compScieSubjects[i] = compScieSubjects[i + 1];
     ```
   * This overwrites the deleted value and moves all following elements one position to the left.

4. **Update the length**

   * After shifting, decrement `lengthOfArray` by 1 to reflect the removal.

5. **Display results**

   * Print the array before and after deletion to confirm that the target value is gone and the elements have been shifted correctly.

**Key idea:**

Deletion in a fixed-size array means **finding the index**, **shifting elements left**, and **reducing the logical size** — the physical array size stays the same, but the unused slot at the end is ignored.
