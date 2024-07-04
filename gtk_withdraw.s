.file   "gtk_withdraw.c"
.text
.p2align 4
.globl  on_withdraw_confirm_clicked
.type   on_withdraw_confirm_clicked, @function

on_withdraw_confirm_clicked:
.LFB2284:
    .cfi_startproc
    endbr64
    pushq   %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsi, %rbp
    
    call    gtk_entry_get_type@PLT      # Get type of the entry widget
    movq    8(%rbp), %rdi               # Load dialog_data->entry
    movq    %rax, %rsi
    call    g_type_check_instance_cast@PLT  # Cast to GTK_ENTRY
    movq    %rax, %rdi
    call    gtk_entry_get_text@PLT      # Get text from the entry
    xorl    %esi, %esi                  # Prepare for strtol
    movl    $10, %edx                   # Base 10
    movq    %rax, %rdi
    call    strtol@PLT                  # Convert text to integer
    testl   %eax, %eax
    jle     .L2                         # Jump if amount <= 0
    
    movq    16(%rbp), %rdi              # Load dialog_data->user
    movl    56(%rdi), %edx              # Load user balance
    cmpl    %eax, %edx                  # Compare amount with balance
    jl      .L2                         # Jump if amount > balance
    
    subl    %eax, %edx                  # Update balance
    movl    %edx, 56(%rdi)
    call    updateMainDisplay@PLT       # Update main display
    movq    16(%rbp), %rdi              # Load dialog_data->user
    call    updateUserData@PLT          # Update user data
    
.L2:
    movq    0(%rbp), %rdi               # Load dialog_data
    call    gtk_widget_destroy@PLT      # Destroy the dialog widget
    movq    %rbp, %rdi
    popq    %rbp
    .cfi_remember_state
    .cfi_def_cfa_offset 8
    jmp     g_free@PLT                  # Free dialog_data
    .p2align 4,,10
    .p2align 3
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
