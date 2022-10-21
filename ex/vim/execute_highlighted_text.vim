" --------------------------------------------------------------------
" Execute the text that is visually highlighted.

function! ExecHighlighted () range

        " Grab the highlighted text: save the contents of an arbitrary
        " register, yank the highlighted text to it, copy the register
        " contents to a local variable, and restore the register
        " contents.
    let l:saved_a = @a
    silent! normal! gv"ay
    let l:text = @a
    let @a = l:saved_a

        " Concatenate continuation lines, else for some reason it
        " fails to work.
    let l:text = substitute(l:text, '\n\s*\\\\', ' ', 'g')

        " Execute the grabbed text.
   " echo '⦃' . l:text . '⦄'
    exec l:text

endfunction

    " Have a Visual-mode-only mapping to invoke the function.
xnoremap <f9> :call ExecHighlighted()<cr>
