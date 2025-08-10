# **Appending a Value to an Array**

**Goal:**

Add a new element to the **end** of the array.

**Steps:**

1. **Set up the data**

   * Have an array with some elements already stored.
   * Track the number of elements currently in use with `lengthOfArray`.
   * Know the maximum size of the array (`maxSize`).
   * Decide the new value you want to append (`newValue`).

2. **Check available capacity**

   * Only append if `lengthOfArray < maxSize`.
   * If the array is full, no action is taken (or handle it as an error).

3. **Insert the new value at the end**

   * The correct position for appending is at `index = lengthOfArray`.
   * Assign `compScieSubjects[lengthOfArray] = newValue`.

4. **Update length**

   * Increment `lengthOfArray` by 1 to reflect the newly added element.

5. **Display results**

   * Print the array before and after appending to verify that the new element was successfully added to the end.

**Key idea:**

Appending is just a special case of insertion — the position is always **at the current length** of the array.
