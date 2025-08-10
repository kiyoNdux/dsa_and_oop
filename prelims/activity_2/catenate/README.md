# **Catenate Two Arrays**

**Goal:**

Combine the elements of two arrays (`lista` and `listb`) into a single array (`newList`) that contains all elements in order.

**Steps:**

1. **Initialize array sizes and values**

   * Define the size and elements for `lista` (first array).
   * Define the size and elements for `listb` (second array).

2. **Create a new array for the result**

   * The new array size should be **the sum** of `listaSize` and `listbSize`.

3. **Copy elements from the first array**

   * Use a `for` loop to iterate through all elements in `lista`.
   * Assign each element to the corresponding position in `newList`.

4. **Append elements from the second array**

   * Use another `for` loop to iterate through all elements in `listb`.
   * Assign each element to `newList`, **starting at the index after the last element of `lista`**.
   * This is achieved by `newList[listaSize + j]`.

5. **Display the catenated array**

   * Loop through `newList` and print all elements in order.


**Example Flow:**

* `lista` = {1, 2, 3}
* `listb` = {4, 5}
* After catenation → `newList` = {1, 2, 3, 4, 5}


**Key Points:**

* Ensure the `newList` array is large enough to hold both arrays.
* The second array's elements must start after the last index of the first array.

