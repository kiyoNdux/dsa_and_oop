# **Replacing an Element in an Array**

1. **Understand the Goal**

   * We have an array with fixed elements.
   * We want to change the value at a specific position without altering the array’s length or the positions of other elements.

2. **Identify the Target Index**

   * Decide which element (by position) should be replaced.
   * Store that position in a variable (e.g., `indexToReplace`) or use it directly.

3. **Prepare the New Value**

   * Decide what value will replace the current one.
   * Store it in a variable for clarity and reuse.

4. **Perform the Replacement**

   * Use array indexing to directly access the position and assign the new value:
     `array[index] = newValue;`
   * This updates the element in place without shifting any other values.
