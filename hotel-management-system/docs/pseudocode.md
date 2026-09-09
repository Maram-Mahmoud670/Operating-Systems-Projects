
# Hotel Management System - Pseudocode

## 1. Start Program

START

Create the Hotel directory structure.

Ask the user to select a role:

1. Admin
2. Staff
3. Guest

Validate the selected role.

If the role is invalid:
    Display an error message.
    Ask the user again.

Display the main menu.

Repeat until the user chooses Exit.

---

## 2. List Files

IF Admin:
    List files inside Admin directory.

ELSE IF Staff:
    List files inside Staff directory.

ELSE:
    List files inside Guests directory.

---

## 3. Change Permissions

IF Admin:
    Change permissions of Admin directory.

ELSE IF Staff:
    Change permissions of booking_data.

ELSE:
    Display permission denied message.

---

## 4. Create File

Ask the user for a file name.

Determine the directory based on the user's role.

Create the file.

Display success or error message.

---

## 5. Delete File

Ask the user for the file name.

Determine the correct directory.

Delete the file.

Display success or error message.

---

## 6. Create Symbolic Link

IF user is Admin:
    Create a symbolic link to room_availability.

ELSE:
    Display permission denied message.

---

## 7. Copy Files

IF user is Admin or Staff:
    Copy booking_data to Staff/backup.

ELSE:
    Copy bookings_details to Guests/backup.

---

## 8. Append Data

IF user is Admin:
    Display that the operation is not available.

ELSE IF user is Staff:
    Append data to booking_data.

ELSE:
    Append data to feedback.

---

## 9. Set Alias

Ask the user for an alias name.

Ask the user for a command.

Display the Linux alias command.

---

## 10. View File Content

IF user is Admin:
    Display permission denied message.

ELSE:
    Ask for the file name.

    Open the file.

    Read and display its content.

---

## 11. Find Files

IF user is Guest:
    Display permission denied message.

ELSE:
    Ask for a file or directory name.

    Search inside the user's directory.

    Display matching results.

---

## 12. Exit

Display exit message.

END