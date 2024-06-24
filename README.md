# ATM Banking System

A simple ATM Banking System developed in C using the GTK+ 3 library. The application provides a graphical user interface (GUI) to simulate basic banking operations such as balance inquiry, deposit, and withdrawal.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Code Overview](#code-overview)



## Features

- **Balance Inquiry**: View the current balance of the user.
- **Deposit Money**: Add money to the user's account.
- **Withdraw Money**: Withdraw money from the user's account.
- **Exit**: Close the application safely.

## Installation

### Prerequisites

- GTK+ 3 development libraries.
- GCC compiler.

### Installing GTK+ 3 on Ubuntu

```bash
sudo apt update
sudo apt install libgtk-3-dev


#### 5.3. Cloning the Repository

```markdown
### Cloning the Repository

```bash
git clone https://github.com/yourusername/atm-banking-system.git
cd atm-banking-system



#### 5.4. Compiling the Code

```markdown
### Compiling the Code

```bash
gcc `pkg-config --cflags gtk+-3.0` -o atm_system atm_system.c `pkg-config --libs gtk+-3.0`


### 6. Usage

```markdown
## Usage

1. Start the X server on your host machine (if running on Windows via WSL).
2. Run the compiled program:

    ```bash
    ./atm_system
    ```

3. The application window will appear, and you can perform the following actions:
   - Check balance
   - Deposit money
   - Withdraw money
   - Exit the application

### Key Functions

- `displayMenu(struct User *user)`: Displays the main window with user information and action buttons.
- `on_withdraw_clicked()`: Handles the withdraw button click event.
- `on_deposit_clicked()`: Handles the deposit button click event.
- `on_exit_clicked()`: Handles the exit button click event.
