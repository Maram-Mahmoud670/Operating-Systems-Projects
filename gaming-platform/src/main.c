
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <limits.h>

#define GAMING_DIR "Gaming"

enum Role {
    ADMIN = 1,
    MODERATOR,
    PLAYER
};

/* ==================== Utility Functions ==================== */

const char *get_role_name(int role)
{
    switch (role)
    {
        case ADMIN:
            return "Admin";

        case MODERATOR:
            return "Moderator";

        case PLAYER:
            return "Player";

        default:
            return "Unknown";
    }
}

void create_directory(const char *path)
{
    if (mkdir(path, 0755) == -1 && errno != EEXIST)
    {
        perror("Error creating directory");
    }
}

void create_file(const char *path)
{
    FILE *file = fopen(path, "a");

    if (file == NULL)
    {
        perror("Error creating file");
        return;
    }

    fclose(file);
}

/* ==================== Create Gaming Structure ==================== */

void create_directory_structure(void)
{
    char path[PATH_MAX];

    /* Main Gaming directory */
    create_directory(GAMING_DIR);

    /* ---------- Admin ---------- */

    snprintf(path, sizeof(path), "%s/admin", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/admin/Backup", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/admin/server_logs", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/admin/configurations", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/admin/reports", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/admin/policies", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/admin/guidelines", GAMING_DIR);
    create_file(path);

    /* ---------- Moderators ---------- */

    snprintf(path, sizeof(path), "%s/moderators", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/moderators/archive", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/moderators/violation_logs", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/moderators/user_reports", GAMING_DIR);
    create_file(path);

    /* ---------- Players ---------- */

    snprintf(path, sizeof(path), "%s/players", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/players/Backup", GAMING_DIR);
    create_directory(path);

    snprintf(path, sizeof(path), "%s/players/game_profiles", GAMING_DIR);
    create_file(path);

    snprintf(path, sizeof(path), "%s/players/save_data", GAMING_DIR);
    create_file(path);

    printf("\nGaming platform structure is ready.\n");
}

/* ==================== List Files ==================== */

void list_files(int role)
{
    const char *directory;

    switch (role)
    {
        case ADMIN:
            directory = "Gaming/admin";
            break;

        case MODERATOR:
            directory = "Gaming/moderators";
            break;

        case PLAYER:
            directory = "Gaming/players";
            break;

        default:
            printf("Invalid role.\n");
            return;
    }

    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;

    printf("\nContents of %s:\n", directory);

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0)
        {
            printf("- %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

/* ==================== Change Permissions ==================== */

void change_permissions(int role)
{
    if (role != ADMIN)
    {
        printf("Only Admin can change permissions.\n");
        return;
    }

    const char *path = "Gaming/moderators/violation_logs";

    if (chmod(path, 0700) == -1)
    {
        perror("Unable to change permissions");
        return;
    }

    printf("Permissions updated successfully.\n");
}

/* ==================== Create File ==================== */

void make_file(int role)
{
    char filename[100];
    char path[PATH_MAX];

    if (role == PLAYER)
    {
        printf("Players cannot create new files.\n");
        return;
    }

    printf("Enter the name of the file to create: ");

    if (scanf("%99s", filename) != 1)
    {
        printf("Invalid filename.\n");
        return;
    }

    if (role == ADMIN)
    {
        snprintf(path, sizeof(path),
                 "Gaming/admin/%s",
                 filename);
    }
    else
    {
        snprintf(path, sizeof(path),
                 "Gaming/moderators/%s",
                 filename);
    }

    create_file(path);

    printf("File created successfully.\n");
}

/* ==================== Delete File ==================== */

void delete_file(int role)
{
    char filename[100];
    char path[PATH_MAX];

    if (role == PLAYER)
    {
        printf("Players cannot delete files.\n");
        return;
    }

    printf("Enter the name of the file to delete: ");

    if (scanf("%99s", filename) != 1)
    {
        printf("Invalid filename.\n");
        return;
    }

    if (role == ADMIN)
    {
        snprintf(path, sizeof(path),
                 "Gaming/admin/%s",
                 filename);
    }
    else
    {
        snprintf(path, sizeof(path),
                 "Gaming/moderators/%s",
                 filename);
    }

    if (remove(path) == -1)
    {
        perror("Unable to delete file");
        return;
    }

    printf("File deleted successfully.\n");
}

/* ==================== Symbolic Links ==================== */

void make_symbolic_links(int role)
{
    if (role != ADMIN)
    {
        printf("Only Admin can create symbolic links.\n");
        return;
    }

    if (symlink("../admin/policies",
                "Gaming/players/policies_ln") == -1)
    {
        if (errno != EEXIST)
            perror("Unable to create policies link");
    }

    if (symlink("../admin/guidelines",
                "Gaming/players/guidelines_ln") == -1)
    {
        if (errno != EEXIST)
            perror("Unable to create guidelines link");
    }

    if (symlink("../admin/policies",
                "Gaming/moderators/policies_ln") == -1)
    {
        if (errno != EEXIST)
            perror("Unable to create policies link");
    }

    if (symlink("../admin/guidelines",
                "Gaming/moderators/guidelines_ln") == -1)
    {
        if (errno != EEXIST)
            perror("Unable to create guidelines link");
    }

    printf("Symbolic links created successfully.\n");
}

/* ==================== Copy Files ==================== */

void copy_file(const char *source, const char *destination)
{
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL)
    {
        perror("Error opening files");

        if (src != NULL)
            fclose(src);

        if (dest != NULL)
            fclose(dest);

        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read =
                fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        fwrite(buffer, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
}

void copy_files(int role)
{
    if (role == ADMIN)
    {
        copy_file(
            "Gaming/admin/server_logs",
            "Gaming/admin/Backup/server_logs_backup"
        );

        printf("Server logs copied successfully.\n");
    }
    else if (role == PLAYER)
    {
        copy_file(
            "Gaming/players/save_data",
            "Gaming/players/Backup/save_data_backup"
        );

        printf("Save data copied successfully.\n");
    }
    else
    {
        printf("Copy operation is allowed only for Admin and Player.\n");
    }
}

/* ==================== Move Files ==================== */

void move_files(int role)
{
    if (role != MODERATOR)
    {
        printf("Only Moderator can move files.\n");
        return;
    }

    if (rename(
            "Gaming/moderators/violation_logs",
            "Gaming/moderators/archive/archived_violation_logs"
        ) == -1)
    {
        perror("Unable to move file");
        return;
    }

    printf("Violation logs moved successfully.\n");
}

/* ==================== Append Data ==================== */

void append_data_to_file(int role)
{
    if (role != PLAYER)
    {
        printf("Append operation is allowed only for Player.\n");
        return;
    }

    char data[256];

    printf("Enter data to append to your profile: ");

    getchar();

    if (fgets(data, sizeof(data), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return;
    }

    FILE *file =
        fopen("Gaming/players/game_profiles", "a");

    if (file == NULL)
    {
        perror("Unable to open profile file");
        return;
    }

    fprintf(file, "%s", data);

    fclose(file);

    printf("Data appended successfully.\n");
}

/* ==================== View File Content ==================== */

void view_file_content(int role)
{
    char filename[100];
    char path[PATH_MAX];

    printf("Enter file name to view: ");

    if (scanf("%99s", filename) != 1)
    {
        printf("Invalid filename.\n");
        return;
    }

    if (role == ADMIN)
    {
        snprintf(path, sizeof(path),
                 "Gaming/admin/%s",
                 filename);
    }
    else if (role == MODERATOR)
    {
        snprintf(path, sizeof(path),
                 "Gaming/moderators/%s",
                 filename);
    }
    else
    {
        snprintf(path, sizeof(path),
                 "Gaming/players/%s",
                 filename);
    }

    FILE *file = fopen(path, "r");

    if (file == NULL)
    {
        perror("Unable to open file");
        return;
    }

    char line[256];

    printf("\n---------- File Content ----------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    printf("\n----------------------------------\n");

    fclose(file);
}

/* ==================== Find Files ==================== */

void find_files(int role)
{
    char filename[100];
    char directory[PATH_MAX];

    if (role == PLAYER)
    {
        printf("Search operation is not allowed for Player.\n");
        return;
    }

    printf("Enter the exact file name to search: ");

    if (scanf("%99s", filename) != 1)
    {
        printf("Invalid filename.\n");
        return;
    }

    if (role == ADMIN)
    {
        strcpy(directory, "Gaming/admin");
    }
    else
    {
        strcpy(directory, "Gaming/moderators");
    }

    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    int found = 0;

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, filename) == 0)
        {
            printf("File found: %s/%s\n",
                   directory,
                   entry->d_name);

            found = 1;
            break;
        }
    }

    closedir(dir);

    if (!found)
    {
        printf("File not found.\n");
    }
}

/* ==================== Menu ==================== */

void display_menu(void)
{
    printf("\n");
    printf("====================================\n");
    printf("        GAMING PLATFORM SYSTEM\n");
    printf("====================================\n");

    printf("1. List files/directories\n");
    printf("2. Change permissions\n");
    printf("3. Create file\n");
    printf("4. Delete file\n");
    printf("5. Create symbolic links\n");
    printf("6. Copy files\n");
    printf("7. Move files\n");
    printf("8. Append data to file\n");
    printf("9. View file content\n");
    printf("10. Find files\n");
    printf("11. Exit\n");

    printf("====================================\n");
}

/* ==================== Main ==================== */

int main(void)
{
    create_directory_structure();

    int role;
    int choice;

    printf("\n");
    printf("====================================\n");
    printf("       GAMING PLATFORM SYSTEM\n");
    printf("====================================\n");

    printf("\nSelect your role:\n");
    printf("1. Admin\n");
    printf("2. Moderator\n");
    printf("3. Player\n");

    do
    {
        printf("Enter your role: ");

        if (scanf("%d", &role) != 1)
        {
            printf("Invalid input. Please enter 1, 2, or 3.\n");

            while (getchar() != '\n');

            role = 0;
        }

    } while (role < ADMIN || role > PLAYER);

    printf("\nWelcome, %s!\n",
           get_role_name(role));

    do
    {
        display_menu();

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice)
        {
            case 1:
                list_files(role);
                break;

            case 2:
                change_permissions(role);
                break;

            case 3:
                make_file(role);
                break;

            case 4:
                delete_file(role);
                break;

            case 5:
                make_symbolic_links(role);
                break;

            case 6:
                copy_files(role);
                break;

            case 7:
                move_files(role);
                break;

            case 8:
                append_data_to_file(role);
                break;

            case 9:
                view_file_content(role);
                break;

            case 10:
                find_files(role);
                break;

            case 11:
                printf("\nExiting Gaming Platform System...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 11);

    return 0;
}