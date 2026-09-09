# 🏨 Hotel Management System

A Linux-based Hotel Management System developed in **C** as a practical project for working with Linux commands, file systems, permissions, file handling, and user roles.

The system simulates a simple hotel environment where different users have different permissions and can perform specific file and directory operations.

---

## 📌 Project Overview

The **Hotel Management System** is a menu-driven C application designed to demonstrate practical Linux system programming concepts.

The application creates a complete hotel directory structure and provides different operations depending on the selected user role.

The project focuses on:

- Linux file and directory management
- File permissions
- File creation and deletion
- File copying and backup
- Symbolic links
- File searching
- File content management
- Linux commands from C
- User roles and access control
- C file handling

---

# 🎯 Project Objectives

The main objectives of this project are to:

1. Practice Linux commands through a C program.
2. Understand file and directory management.
3. Work with Linux file permissions.
4. Implement different user roles.
5. Practice C file handling.
6. Create and manage backup files.
7. Understand symbolic links.
8. Implement file searching.
9. Build a menu-driven application.
10. Apply system programming concepts in a practical project.

---

# 👥 User Roles

The system supports three different user roles:

## 👨‍💼 1. Admin

The Admin has the highest level of access.

The Admin can perform operations such as:

- List files and directories
- Change file permissions
- Create files
- Delete files
- Create symbolic links
- Copy files
- Create backups
- Append data to files
- View file contents
- Search for files and directories
- Create aliases

The Admin also has special permission to create symbolic links.

---

## 👨‍💻 2. Staff

Staff members can manage hotel-related information.

Staff can work with:

- Booking data
- Customer records
- Room assignments
- Room availability
- Hotel policies
- Guest notes

Staff can also:

- List files
- Change permissions for allowed files
- Create files
- Delete files
- Copy files
- Create backups
- Append booking information
- View file contents
- Search for files and directories

Some administrative operations are restricted.

---

## 👤 3. Guest

Guests have limited access to hotel and booking information.

Guests can work with:

- Booking details
- Personal details
- Preferences
- Feedback

Guests can:

- List files
- Create files
- Delete files
- Copy booking information
- Append feedback
- View file contents

Administrative operations such as changing permissions and creating symbolic links are restricted for guests.

---

# 📂 Directory Structure

When the program starts, it creates the following hotel directory structure:

```text
Hotel/
│
├── Admin/
│   ├── administrative
│   └── backup/
│
├── Staff/
│   ├── booking_data
│   ├── customer_record
│   ├── room_assignments
│   ├── room_availability
│   ├── hotel_policies
│   ├── guest_notes
│   └── backup/
│
└── Guests/
    ├── bookings_details
    ├── personal_details
    ├── preferences
    ├── feedback
    └── backup/