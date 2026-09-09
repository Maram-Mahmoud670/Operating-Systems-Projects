
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <limits.h>

#define ADMIN 1
#define STAFF 2
#define GUEST 3

void create_directory_structure();
void list_files(int role);
void change_permissions(int role);
void make_file(int role);
void delete_file(int role);
void make_symbolic_link(int role);
void copy_files(int role);
void append_data_to_file(int role);
void set_alias();
void view_file_content(int role);
void find_files(int role);

void get_hotel_path(char *path, size_t size)
{
    const char *home = getenv("HOME");

    if (home == NULL)
    {
        printf("Error: HOME directory not found.\n");
        exit(EXIT_FAILURE);
    }

    snprintf(path, size, "%s/Desktop/Hotel", home);
}

void create_directory_structure()
{
    char path[PATH_MAX];

    get_hotel_path(path, sizeof(path));

    char command[PATH_MAX];

    snprintf(command, sizeof(command), "mkdir -p \"%s/Admin/backup\"", path);
    system(command);

    snprintf(command, sizeof(command), "mkdir -p \"%s/Staff/backup\"", path);
    system(command);

    snprintf(command, sizeof(command), "mkdir -p \"%s/Guests/backup\"", path);
    system(command);

    char *admin_files[] = {
        "administrative"
    };

    char *staff_files[] = {
        "booking_data",
        "customer_record",
        "room_assignments",
        "room_availability",
        "hotel_policies",
        "guest_notes"
    };

    char *guest_files[] = {
        "bookings_details",
        "personal_details",
        "preferences",
        "feedback"
    };

    for (int i = 0; i < 1; i++)
    {
        char file_path[PATH_MAX];

        snprintf(file_path, sizeof(file_path),
                 "%s/Admin/%s", path, admin_files[i]);

        FILE *file = fopen(file_path, "a");

        if (file != NULL)
            fclose(file);
    }

    for (int i = 0; i < 6; i++)
    {
        char file_path[PATH_MAX];

        snprintf(file_path, sizeof(file_path),
                 "%s/Staff/%s", path, staff_files[i]);

        FILE *file = fopen(file_path, "a");

        if (file != NULL)
            fclose(file);
    }

    for (int i = 0; i < 4; i++)
    {
        char file_path[PATH_MAX];

        snprintf(file_path, sizeof(file_path),
                 "%s/Guests/%s", path, guest_files[i]);

        FILE *file = fopen(file_path, "a");

        if (file != NULL)
            fclose(file);
    }

    printf("\nHotel directory structure created successfully.\n");
}

void list_files(int role)
{
    char hotel_path[PATH_MAX];
    char path[PATH_MAX];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == ADMIN)
        snprintf(path, sizeof(path), "%s/Admin", hotel_path);
    else if (role == STAFF)
        snprintf(path, sizeof(path), "%s/Staff", hotel_path);
    else
        snprintf(path, sizeof(path), "%s/Guests", hotel_path);

    DIR *directory = opendir(path);

    if (directory == NULL)
    {
        printf("Error: Cannot open directory.\n");
        return;
    }

    struct dirent *entry;

    printf("\nContents:\n");

    while ((entry = readdir(directory)) != NULL)
    {
        if (strcmp(entry->d_name, ".") != 0 &&
            strcmp(entry->d_name, "..") != 0)
        {
            printf("- %s\n", entry->d_name);
        }
    }

    closedir(directory);
}

void change_permissions(int role)
{
    char hotel_path[PATH_MAX];
    char path[PATH_MAX];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == ADMIN)
    {
        snprintf(path, sizeof(path), "%s/Admin", hotel_path);

        if (chmod(path, 0777) == 0)
            printf("Admin directory permissions changed successfully.\n");
        else
            perror("chmod");
    }
    else if (role == STAFF)
    {
        snprintf(path, sizeof(path),
                 "%s/Staff/booking_data", hotel_path);

        if (chmod(path, 0777) == 0)
            printf("Booking data permissions changed successfully.\n");
        else
            perror("chmod");
    }
    else
    {
        printf("Guests are not allowed to change permissions.\n");
    }
}

void make_file(int role)
{
    char hotel_path[PATH_MAX];
    char file_path[PATH_MAX];
    char filename[100];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    printf("\nEnter the name of the file: ");
    scanf("%99s", filename);

    if (role == ADMIN)
        snprintf(file_path, sizeof(file_path),
                 "%s/Admin/%s", hotel_path, filename);
    else if (role == STAFF)
        snprintf(file_path, sizeof(file_path),
                 "%s/Staff/%s", hotel_path, filename);
    else
        snprintf(file_path, sizeof(file_path),
                 "%s/Guests/%s", hotel_path, filename);

    FILE *file = fopen(file_path, "w");

    if (file == NULL)
    {
        perror("Error creating file");
        return;
    }

    fclose(file);

    printf("File created successfully.\n");
}

void delete_file(int role)
{
    char hotel_path[PATH_MAX];
    char file_path[PATH_MAX];
    char filename[100];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    printf("\nEnter the name of the file to delete: ");
    scanf("%99s", filename);

    if (role == ADMIN)
        snprintf(file_path, sizeof(file_path),
                 "%s/Admin/%s", hotel_path, filename);
    else if (role == STAFF)
        snprintf(file_path, sizeof(file_path),
                 "%s/Staff/%s", hotel_path, filename);
    else
        snprintf(file_path, sizeof(file_path),
                 "%s/Guests/%s", hotel_path, filename);

    if (remove(file_path) == 0)
        printf("File deleted successfully.\n");
    else
        perror("Error deleting file");
}

void make_symbolic_link(int role)
{
    char hotel_path[PATH_MAX];
    char source[PATH_MAX];
    char link_path[PATH_MAX];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role != ADMIN)
    {
        printf("Only Admin can create symbolic links.\n");
        return;
    }

    snprintf(source, sizeof(source),
             "%s/Staff/room_availability", hotel_path);

    snprintf(link_path, sizeof(link_path),
             "%s/Admin/room_availability_link", hotel_path);

    if (symlink(source, link_path) == 0)
        printf("Symbolic link created successfully.\n");
    else
        perror("Error creating symbolic link");
}

void copy_file(const char *source, const char *destination)
{
    FILE *src = fopen(source, "rb");
    FILE *dest = fopen(destination, "wb");

    if (src == NULL || dest == NULL)
    {
        printf("Error copying file.\n");

        if (src != NULL)
            fclose(src);

        if (dest != NULL)
            fclose(dest);

        return;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");
}

void copy_files(int role)
{
    char hotel_path[PATH_MAX];
    char source[PATH_MAX];
    char destination[PATH_MAX];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == ADMIN || role == STAFF)
    {
        snprintf(source, sizeof(source),
                 "%s/Staff/booking_data", hotel_path);

        snprintf(destination, sizeof(destination),
                 "%s/Staff/backup/booking_data", hotel_path);
    }
    else
    {
        snprintf(source, sizeof(source),
                 "%s/Guests/bookings_details", hotel_path);

        snprintf(destination, sizeof(destination),
                 "%s/Guests/backup/bookings_details", hotel_path);
    }

    copy_file(source, destination);
}

void append_data_to_file(int role)
{
    char hotel_path[PATH_MAX];
    char file_path[PATH_MAX];
    char data[256];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == ADMIN)
    {
        printf("Admin does not have append operations.\n");
        return;
    }

    if (role == STAFF)
    {
        snprintf(file_path, sizeof(file_path),
                 "%s/Staff/booking_data", hotel_path);
    }
    else
    {
        snprintf(file_path, sizeof(file_path),
                 "%s/Guests/feedback", hotel_path);
    }

    getchar();

    printf("\nEnter data to append: ");

    fgets(data, sizeof(data), stdin);

    FILE *file = fopen(file_path, "a");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", data);

    fclose(file);

    printf("Data appended successfully.\n");
}

void set_alias()
{
    char alias_name[50];
    char command[200];

    printf("\nEnter alias name: ");
    scanf("%49s", alias_name);

    printf("Enter command: ");

    getchar();

    fgets(command, sizeof(command), stdin);

    command[strcspn(command, "\n")] = '\0';

    printf("\nAlias command:\n");
    printf("alias %s='%s'\n", alias_name, command);

    printf("\nUse the displayed command in your Linux terminal to create the alias.\n");
}

void view_file_content(int role)
{
    char hotel_path[PATH_MAX];
    char file_path[PATH_MAX];
    char filename[100];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == ADMIN)
    {
        printf("Admin is not allowed to view file content.\n");
        return;
    }

    printf("\nEnter file name: ");
    scanf("%99s", filename);

    if (role == STAFF)
    {
        snprintf(file_path, sizeof(file_path),
                 "%s/Staff/%s", hotel_path, filename);
    }
    else
    {
        snprintf(file_path, sizeof(file_path),
                 "%s/Guests/%s", hotel_path, filename);
    }

    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[256];

    printf("\n--- File Content ---\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    printf("\n--------------------\n");

    fclose(file);
}

void find_files(int role)
{
    char hotel_path[PATH_MAX];
    char search_path[PATH_MAX];
    char pattern[100];
    char command[PATH_MAX + 150];

    get_hotel_path(hotel_path, sizeof(hotel_path));

    if (role == GUEST)
    {
        printf("Only Admin and Staff can search for files.\n");
        return;
    }

    if (role == ADMIN)
        snprintf(search_path, sizeof(search_path),
                 "%s/Admin", hotel_path);
    else
        snprintf(search_path, sizeof(search_path),
                 "%s/Staff", hotel_path);

    printf("\nEnter file/directory name to search: ");
    scanf("%99s", pattern);

    snprintf(command, sizeof(command),
             "find \"%s\" -name \"%s\" 2>/dev/null",
             search_path, pattern);

    printf("\nSearching...\n");

    FILE *process = popen(command, "r");

    if (process == NULL)
    {
        printf("Error executing search.\n");
        return;
    }

    char output[PATH_MAX];
    int found = 0;

    while (fgets(output, sizeof(output), process) != NULL)
    {
        printf("%s", output);
        found = 1;
    }

    pclose(process);

    if (!found)
        printf("No matching files or directories found.\n");
}

int main()
{
    create_directory_structure();

    int role;
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("      HOTEL MANAGEMENT SYSTEM\n");
        printf("====================================\n");

        printf("1. Admin\n");
        printf("2. Staff\n");
        printf("3. Guest\n");
        printf("Enter your role: ");

        scanf("%d", &role);

        if (role < ADMIN || role > GUEST)
            printf("Invalid role. Please choose 1, 2, or 3.\n");

    } while (role < ADMIN || role > GUEST);

    do
    {
        printf("\n====================================\n");
        printf("              MENU\n");
        printf("====================================\n");

        printf("1. List files/directories\n");
        printf("2. Change permissions\n");
        printf("3. Create file\n");
        printf("4. Delete file\n");
        printf("5. Create symbolic link\n");
        printf("6. Copy files\n");
        printf("7. Append data to file\n");
        printf("8. Set alias\n");
        printf("9. View file content\n");
        printf("10. Find files/directories\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                make_symbolic_link(role);
                break;

            case 6:
                copy_files(role);
                break;

            case 7:
                append_data_to_file(role);
                break;

            case 8:
                set_alias();
                break;

            case 9:
                view_file_content(role);
                break;

            case 10:
                find_files(role);
                break;

            case 11:
                printf("\nExiting Hotel Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 11);

    return 0;
}