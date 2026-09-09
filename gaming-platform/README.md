# 🎮 Gaming Platform Management System

A Linux-based Gaming Platform Management System developed in C.

This project is designed to practice Linux file-system operations and system programming concepts through an interactive command-line application.

The system provides different operations depending on the selected user role, including file and directory management, file permissions, copying, moving, searching, and reading/writing files.

---

## 📌 Project Overview

The Gaming Platform Management System simulates a simple platform environment with three different user roles:

- 👑 Admin
- 🛡️ Moderator
- 🎮 Player

Each role has different responsibilities and access to specific operations.

The project focuses mainly on applying **C programming** together with **Linux file-system concepts and system calls**.

---

## 👥 User Roles

### 👑 Admin

The Admin is responsible for managing the main platform resources.

Admin operations include:

- Listing files and directories
- Changing file permissions
- Creating files
- Deleting files
- Creating symbolic links
- Copying files
- Viewing file contents
- Searching for files

---

### 🛡️ Moderator

The Moderator is responsible for managing moderation-related resources.

Moderator operations include:

- Listing files and directories
- Creating files
- Deleting files
- Moving violation logs
- Viewing file contents
- Searching for files

---

### 🎮 Player

The Player is responsible for managing personal gaming data.

Player operations include:

- Listing files and directories
- Copying save data
- Appending data to the game profile
- Viewing file contents

Some administrative operations are restricted for Players.

---

# 📂 Project Structure

The project is organized as follows:

```text
gaming-platform/
│
├── docs/
│   ├── complexity.md
│   └── pseudocode.md
│
├── src/
│   └── main.c
│
├── tests/
│   └── test-cases.md
│
├── .gitignore
│
└── README.md