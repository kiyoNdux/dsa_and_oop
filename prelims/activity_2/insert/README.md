# **Inserting a Value to an Array**

**Goal:**

Add a new element at a specific position in an array, shifting existing elements to make space.

**Steps:**

1. **Set up the data**

   * Have an array with some existing elements and a `lengthOfArray` variable to track how many are in use.
   * Decide the **index** where you want to insert (`indexToInsert`) and the **value** to insert (`valueToInsert`).
   * Have a `maxSize` limit for the total array capacity.

2. **Check boundaries**

   * Ensure `indexToInsert` is not less than `0` and not greater than `lengthOfArray` (insertion at the very end is allowed).
   * Ensure the array is not already full (`lengthOfArray < maxSize`).

3. **Make room for the new element**

   * Starting from the **last used index**, move each element one position to the right until reaching the insertion index.
   * This prevents overwriting data when shifting.

4. **Insert the value**

   * Place `valueToInsert` into `compScieSubjects[indexToInsert]`.
   * Increase `lengthOfArray` by 1 to reflect the new total.

5. **Display results**

   * Print the array before and after insertion to verify correctness.

**Key idea:**

The array must have enough capacity before inserting, and elements are shifted **right** to avoid overwriting before placing the new value.
