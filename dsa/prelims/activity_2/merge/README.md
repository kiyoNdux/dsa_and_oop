# **Merge Two Sorted Lists**

**Goal:**
Combine two sorted lists into a single sorted list by comparing elements from each and appending the smaller one to the resultant list.

---

### **Thought Process**

1. **Initialization**

   * Create index variables `a`, `b`, and `c` to track positions in **lista**, **listb**, and **listc** respectively.
   * Prepare an empty array `listc` large enough to hold all elements from both lists.

2. **Compare and Append**

   * While both lists have remaining elements:

     * Compare the current elements `lista[a]` and `listb[b]`.
     * Append the smaller one to `listc[c]`.
     * Increment the index (`a` or `b`) of the list from which the element was taken.
     * Increment `c` to move forward in the merged list.

3. **Copy Remaining Elements**

   * If **lista** still has elements left, copy them all to **listc**.
   * If **listb** still has elements left, copy them all to **listc**.

4. **Final Output**

   * Print the merged list.

---

### **Example**

**Input:**
`lista = {1, 3, 5}`
`listb = {2, 4, 6}`

**Step-by-Step Merge:**

```
Compare 1 and 2 → Add 1 → [1]  
Compare 3 and 2 → Add 2 → [1, 2]  
Compare 3 and 4 → Add 3 → [1, 2, 3]  
Compare 5 and 4 → Add 4 → [1, 2, 3, 4]  
Compare 5 and 6 → Add 5 → [1, 2, 3, 4, 5]  
Copy remaining 6 → [1, 2, 3, 4, 5, 6]
```

**Output:**
`Merged Array: 1 2 3 4 5 6`
