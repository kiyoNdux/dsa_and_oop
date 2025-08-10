## Searching an Array

**Goal:**

Find the position (index) of a specific value in an array.

**Steps:**

1. **Set up the data**

   * Have an array with known elements.
   * Decide how many elements are actually being used (`lengthOfArray`).
   * Choose a value you want to search for (`valueToSearch`).

2. **Prepare a variable for the result**

   * Use a variable (e.g., `indexValue`) to store the position if found.
   * Initialize it with `-1` to mean "not found yet."

3. **Loop through the array**

   * Start from the first element (`index 0`) and go up to `lengthOfArray - 1`.
   * Compare the current element to the value we’re looking for.

4. **Check for a match**

   * If a match is found:

     * Store the current index in `indexValue`.
     * Stop the loop early (because we don’t need to keep searching).

5. **Return or display the result**

   * If `indexValue` is not `-1`, the value exists in the array and its position can be reported.
   * If it’s still `-1`, the value doesn’t exist in the array.

**Key idea:**

Sequentially check each element until we either find the value or confirm it’s not there — this is a **linear search**.
