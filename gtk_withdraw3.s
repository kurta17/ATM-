.file   "gtk_withdraw.c"
.text
.p2align 4
.globl  on_withdraw_confirm_clicked
.type   on_withdraw_confirm_clicked, @function

on_withdraw_confirm_clicked:
.LFB2284:
    .cfi_startproc
    endbr64
    pushq   %rbp               # Save base pointer
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsi, %rbp         # Move base pointer to RSI

    call    gtk_entry_get_type@PLT  # Get entry widget type
    movq    8(%rbp), %rdi      # Load dialog_data->entry to RDI
    movq    %rax, %rsi         # Move type to RSI
    call    g_type_check_instance_cast@PLT  # Cast to GTK_ENTRY
    movq    %rax, %rdi         # Move cast result to RDI
    call    gtk_entry_get_text@PLT  # Get text from entry widget
    xorl    %esi, %esi         # Zero ESI (base for strtol)
    movl    $10, %edx          # Base 10 for strtol
    movq    %rax, %rdi         # Move text pointer to RDI
    call    strtol@PLT         # Convert text to integer
    testl   %eax, %eax         # Test if integer is <= 0
    jle     .L2                # Jump to .L2 if amount <= 0
    movq    16(%rbp), %rdi     # Load dialog_data->user to RDI
    movl    56(%rdi), %edx     # Load user balance
    cmpl    %eax, %edx         # Compare amount to balance
    jge     .L5                # Jump to .L5 if amount <= balance

.L2:
    movq    0(%rbp), %rdi      # Load dialog_data to RDI
    call    gtk_widget_destroy@PLT  # Destroy dialog widget
    movq    %rbp, %rdi
    popq    %rbp               # Restore base pointer
    .cfi_remember_state
    .cfi_def_cfa_offset 8
    jmp     g_free@PLT         # Free dialog_data
    .p2align 4,,10
    .p2align 3

.L5:
    .cfi_restore_state
    subl    %eax, %edx         # Subtract amount from balance
    movl    %edx, 56(%rdi)     # Store updated balance
    call    updateMainDisplay@PLT  # Update main display
    movq    16(%rbp), %rdi     # Load dialog_data->user to RDI
    call    updateUserData@PLT # Update user data
    jmp     .L2                # Jump to .L2
    .cfi_endproc

.LFE2284:
    .size   on_withdraw_confirm_clicked, .-on_withdraw_confirm_clicked
    .ident  "GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
    .section    .note.GNU-stack,"",@progbits
    .section    .note.gnu.property,"a"
    .align  8
    .long   1f - 0f
    .long   4f - 1f
    .long   5
0:
    .string "GNU"
1:
    .align  8
    .long   0xc0000002
    .long   3f - 2f
2:
    .long   0x3
3:
    .align  8
4:
