.586
.model flat, stdcall
option casemap :none
include \masm32\include\windows.inc
include \masm32\include\kernel32.inc
include \masm32\include\masm32.inc
includelib \masm32\lib\kernel32.lib
includelib \masm32\lib\masm32.lib

;##########################

.data; ??? set_array
	msg_get_rows db "Write count of rows: ", 0
	msg_get_columns db "Write count of columns: ", 0
	msg_c_num db " num",0
	msg_arrow db " -> ", 0
	
	msg_open_bracket db "[", 0
	msg_close_bracket db "]", 0
	
	c_rows dd 0
	c_columns dd 0
	
	array dd 100 dup(?)
	
;##########################
.data?; ??? set_array

	str_rows db 32 dup(?)
	str_columns db 32 dup(?)

	rows dd ?
	columns dd ?
	
	str_get_elem db 32 dup(?); ???????? ??????? ?? StdIn

;##########################
.data; ??? get_array

	msg_exit db "Press any key to continue . . .", 0
	space dd 32
	nxt dd 10
	
;##########################

.data?; ??? end_proc
	trash db 32 dup(?)
	
;##########################

;--------------------------------------------------;

.code
main proc

invoke StdOut, addr msg_get_rows
invoke StdIn, addr str_rows, 32
invoke atodw, addr str_rows
mov rows, eax

invoke StdOut, addr msg_get_columns
invoke StdIn, addr str_columns, 32
invoke atodw, addr str_columns
mov columns, eax
invoke StdOut, addr nxt

set_array:

	check_rows:
	
		mov eax, c_rows
		cmp eax, rows
		je get_array
		jne check_columns
		
		check_columns:
		mov eax, c_columns
		cmp eax, columns
		je nxt_row
		jne fill_row
		
		fill_row:
		mov eax, c_rows
		invoke dwtoa, eax, addr str_rows
		invoke StdOut, addr msg_open_bracket
		invoke StdOut, addr str_rows
		invoke StdOut, addr msg_close_bracket
		
		mov eax, c_columns
		invoke dwtoa, eax, addr str_columns
		invoke StdOut, addr msg_open_bracket
		invoke StdOut, addr str_columns
		invoke StdOut, addr msg_close_bracket
		
		xor eax, eax
		
		invoke StdOut, addr msg_arrow
		invoke StdIn, addr str_get_elem, 32
		invoke atodw, addr str_get_elem
		
		xor ebx, ebx
		
		mov ebx, c_rows 
		imul ebx, columns
		add ebx, c_columns
		imul ebx, 4
		
		mov [array + ebx], eax
		inc c_columns
		jmp check_columns
		
		nxt_row:
		mov eax, c_rows
		inc eax
		mov c_rows, eax
		
		mov eax, c_columns
		sub eax, eax
		mov c_columns, eax
		jmp check_rows


get_array:

	invoke StdOut, addr nxt
	
	mov eax, c_rows
	sub eax, eax
	mov c_rows, eax
	
	mov eax, c_columns
	sub eax, eax
	mov c_columns, eax
	
	cout:
	
	mov eax, c_rows
	cmp eax, rows
	je end_prog
	
	mov ebx, c_rows 
	imul ebx, columns
	add ebx, c_columns
	imul ebx, 4
	
	mov eax, [array+ebx]
	
	invoke dwtoa, eax , addr str_get_elem
	invoke StdOut, addr str_get_elem
	jmp check_space
	
	
	check_space:
	mov eax, c_columns
	inc eax
	cmp eax, columns
	je cout_nxt
	jne cout_space
	
	
	cout_nxt:
	invoke StdOut, addr nxt
	jmp inc_row
	
	cout_space:
	invoke StdOut, addr space
	jmp inc_column
	
	inc_row:
	mov eax, c_columns
	sub eax, eax
	mov c_columns, eax
	
	mov eax, c_rows
	inc eax
	mov c_rows, eax
	
	jmp cout
	
	inc_column:
	
	mov eax, c_columns
	inc eax
	mov c_columns, eax
	
	jmp cout
	

end_prog:

	invoke StdOut, addr nxt
	invoke StdOut, addr msg_exit
	invoke StdIn, addr trash, 1


main EndP
end main
