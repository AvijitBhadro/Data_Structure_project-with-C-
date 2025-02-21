# Hospital Management System 🏥  

## Overview  
This **Hospital Management System** is a console-based C++ application developed as part of my **Data Structures** course. It allows hospital staff to manage patient records efficiently using **linked lists** for dynamic storage and **file handling** for data persistence.  

## Features  
- **Welcome Screen & Login System**  
  - Displays a **welcome banner** with the system name.  
  - Requires a **password ("1234")** to access the system.  

- **Patient Management System**  
  - **Add Patient** – Stores details such as **name, disease, age, cabin number, and phone number**.  
  - **Update Patient** – Modify patient information using an index-based approach.  
  - **Delete Patient** – Remove a patient from the linked list and update the file storage.  
  - **View All Patients** – Lists all stored patient records with their details.  
  - **View Specific Patient** – Searches for a patient by name and displays details.  

- **File Handling for Data Storage**  
  - All patient records are stored in **patients.txt** for persistence.  
  - Updates and deletions are reflected in the file dynamically.  

- **User-Friendly Console Interface**  
  - **ASCII-based UI** for menus and prompts.  
  - **Password masking** using `_getch()` for security.  

## Technologies Used  
- **C++**  
- **File Handling** (Read/Write patient data)  
- **Linked List** (Dynamic memory allocation for patient records)  
- **Basic Console UI**  

## Code Structure  
The program follows a modular structure:  

- `main()` – Controls the program flow and displays the menu.  
- `welcome_screen()` – Displays the welcome message.  
- `login()` – Handles user authentication.  
- `addPatient()` – Adds a new patient record.  
- `updatePatient()` – Updates patient details.  
- `deletePatient()` – Removes a patient from the system.  
- `viewPatients()` – Displays all patients.  
- `viewSpecificPatient()` – Searches for a patient by name.  
- `endthis()` – Displays a farewell message before exiting.  
