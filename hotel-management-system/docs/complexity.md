
# Time and Space Complexity

Let:

- `n` = number of files/directories in a directory
- `k` = size of a file
- `m` = size of appended data

---

## 1. Create Directory Structure

The program creates a fixed number of directories and files.

Time Complexity:

O(1)

Space Complexity:

O(1)

---

## 2. List Files

The program visits each entry in the selected directory.

Time Complexity:

O(n)

Space Complexity:

O(1)

---

## 3. Change Permissions

Changing permissions is a constant-time system operation.

Time Complexity:

O(1)

Space Complexity:

O(1)

---

## 4. Create File

Creating one file is a constant-time operation.

Time Complexity:

O(1)

Space Complexity:

O(1)

---

## 5. Delete File

Deleting one file is a constant-time operation.

Time Complexity:

O(1)

Space Complexity:

O(1)

---

## 6. Create Symbolic Link

Creating a symbolic link is a constant-time operation.

Time Complexity:

O(1)

Space Complexity:

O(1)

---

## 7. Copy File

The file is copied block by block.

Time Complexity:

O(k)

Space Complexity:

O(1)

where `k` is the file size.

---

## 8. Append Data

Appending data requires writing the new data to the file.

Time Complexity:

O(m)

Space Complexity:

O(m)

where `m` is the amount of appended data.

---

## 9. View File Content

The program reads the file from beginning to end.

Time Complexity:

O(k)

Space Complexity:

O(1)

where `k` is the file size.

---

## 10. Find Files

The `find` command may visit the entries inside the selected directory.

Time Complexity:

O(n)

Space Complexity:

O(n)

depending on the search process.

---

## Overall Complexity

The complexity depends on the selected operation.

The most expensive operations are generally:

- File copying: O(k)
- File reading: O(k)
- File searching: O(n)

Simple file operations such as creating, deleting, changing permissions, and creating symbolic links are approximately O(1).