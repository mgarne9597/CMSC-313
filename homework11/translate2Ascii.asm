;This program was written by Matt Garner for CMSC-313 Hw11

        global  _start

section .data
inputBuf:
        db      0x83,0x6A,0x88,0xDE,0x9A,0xC3,0x54,0x9A
inputLen equ     $ - inputBuf     ; number of bytes in inputBuf

section .bss
; Reserve 3 bytes of output per input byte: two hex digits + one space
outputBuf:
        resb    inputLen * 3

section .text
_start:

    ; ------------------------------------------------------------
    ; Build the hex string into outputBuf:
    ;   for each byte in inputBuf
    ;     - extract high 4 bits, convert to ASCII hex
    ;     - extract low  4 bits, convert to ASCII hex
    ;     - append a space
    ; ------------------------------------------------------------
        mov     esi, inputBuf      ; ESI → source byte pointer
        mov     edi, outputBuf     ; EDI → destination buffer pointer
        mov     ecx, inputLen      ; ECX → loop counter (# of bytes)

hex_loop:
        mov     al, [esi]          ; AL = current byte

        ; Convert high nibble (AL≫4) → ASCII
        mov     ah, al
        shr     ah, 4
        mov     al, ah
        call    nibbleToAscii
        stosb                       ; store high-digit

        ; Convert low nibble (AL & 0x0F) → ASCII
        mov     al, [esi]
        and     al, 0x0F
        call    nibbleToAscii
        stosb                       ; store low-digit

        ; Append a space after each byte’s two digits
        mov     al, ' '
        stosb

        inc     esi                 ; move to next input byte
        loop    hex_loop

    ; ------------------------------------------------------------
    ; Replace last space with newline for proper formatting
    ; ------------------------------------------------------------
        mov     byte [edi-1], 0x0A

    ; ------------------------------------------------------------
    ; Write the buffer out to STDOUT in one syscall
    ; ------------------------------------------------------------
        mov     eax, 4              ; sys_write
        mov     ebx, 1              ; file descriptor 1 = STDOUT
        mov     ecx, outputBuf      ; pointer to buffer
        mov     edx, edi            ; edx = end_address
        sub     edx, outputBuf      ; edx = length = edi - outputBuf
        int     0x80

    ; ------------------------------------------------------------
    ; Exit cleanly
    ; ------------------------------------------------------------
        mov     eax, 1              ; sys_exit
        xor     ebx, ebx
        int     0x80

; ----------------------------------------------------------------------------
; nibbleToAscii:
;   Input:  AL = 4-bit value (0–15)
;   Output: AL = ASCII code for hex digit ('0'–'9', 'A'–'F')
; ----------------------------------------------------------------------------
nibbleToAscii:
        cmp     al, 9
        jg      .makeLetter
        add     al, '0'
        ret
.makeLetter:
        add     al, 'A' - 10
        ret
