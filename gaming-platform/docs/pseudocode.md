
# Gaming Platform - Pseudocode

## 1. Start Program

1. Start the program.
2. Create the Gaming directory structure.
3. Display the available roles:
   - Admin
   - Moderator
   - Player
4. Ask the user to select a role.
5. Validate the selected role.

---

## 2. Main Menu

Display the following menu:

1. List files/directories
2. Change permissions
3. Create file
4. Delete file
5. Create symbolic links
6. Copy files
7. Move files
8. Append data to file
9. View file content
10. Find files
11. Exit

Ask the user to select an operation.

---

## 3. List Files

1. Determine the directory according to the selected role.
2. Open the directory.
3. Read its contents.
4. Ignore "." and "..".
5. Display the files and directories.
6. Close the directory.

---

## 4. Change Permissions

1. Check the user's role.
2. If the user is not Admin:
   - Display "Only Admin can change permissions."
3. Otherwise:
   - Change the permissions of the selected file.
   - Display a success message.

---

## 5. Create File

1. Check the user's role.
2. If the user is a Player:
   - Deny the operation.
3. Otherwise:
   - Ask for the file name.
   - Determine the correct directory.
   - Create the file.
   - Display a success message.

---

## 6. Delete File

1. Check the user's role.
2. If the user is a Player:
   - Deny the operation.
3. Otherwise:
   - Ask for the file name.
   - Determine the correct directory.
   - Delete the file.
   - Display a success message.

---

## 7. Create Symbolic Links

1. Check the user's role.
2. If the user is not Admin:
   - Deny the operation.
3. Otherwise:
   - Create symbolic links for policies and guidelines.
   - Display a success message.

---

## 8. Copy Files

1. Check the user's role.
2. If the user is Admin:
   - Copy server logs to the Admin backup directory.
3. If the user is Player:
   - Copy save data to the Player backup directory.
4. Otherwise:
   - Deny the operation.

---

## 9. Move Files

1. Check the user's role.
2. If the user is not Moderator:
   - Deny the operation.
3. Otherwise:
   - Move violation logs to the archive directory.
   - Display a success message.

---

## 10. Append Data

1. Check the user's role.
2. If the user is not Player:
   - Deny the operation.
3. Otherwise:
   - Ask the user for data.
   - Open the player profile file.
   - Append the data.
   - Close the file.
   - Display a success message.

---

## 11. View File

1. Ask the user for a file name.
2. Determine the directory according to the user's role.
3. Open the file.
4. Read its contents.
5. Display the contents.
6. Close the file.

---

## 12. Find File

1. Check the user's role.
2. If the user is a Player:
   - Deny the operation.
3. Otherwise:
   - Ask for the file name.
   - Open the appropriate directory.
   - Search for the file.
   - Display whether the file was found.
   - Close the directory.

---

## 13. Exit

1. If the user selects Exit:
   - Display an exit message.
   - Terminate the program.