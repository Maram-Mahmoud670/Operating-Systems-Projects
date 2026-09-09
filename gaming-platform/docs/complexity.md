
# Gaming Platform - Complexity Analysis

Let:

- n = number of entries in a directory
- k = number of bytes in a file
- m = number of characters in the input data

## 1. Create Directory

Operation:

mkdir()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 2. Create File

Operation:

fopen()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 3. List Files

The program reads all directory entries.

Time Complexity: O(n)

Space Complexity: O(1)

---

## 4. Change Permissions

Operation:

chmod()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 5. Delete File

Operation:

remove()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 6. Create Symbolic Link

Operation:

symlink()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 7. Copy File

The file is read and copied in chunks.

If the file contains k bytes:

Time Complexity: O(k)

Space Complexity: O(1)

The program uses a fixed-size buffer.

---

## 8. Move File

Operation:

rename()

Time Complexity: O(1)

Space Complexity: O(1)

---

## 9. Append Data

If m characters are appended:

Time Complexity: O(m)

Space Complexity: O(m)

The input buffer stores the data before writing.

---

## 10. View File Content

If the file contains k bytes:

Time Complexity: O(k)

Space Complexity: O(1)

The program reads the file line by line.

---

## 11. Find File

The program checks directory entries one by one.

If there are n entries:

Time Complexity: O(n)

Space Complexity: O(1)

---

# Overall Complexity

The complexity depends on the selected operation.

The main operations range from:

O(1)

to:

O(n)

or:

O(k)

for operations that process directory entries or file contents.