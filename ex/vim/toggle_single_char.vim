" --------------------------------------------------------------------
" Toggle single character ｢#⋯｣ style one line comments. Presumes that
" the code starts in column 1 or is indented with 4 spaces or more. So
" converts between pairs of lines like these:
"
"   |my $x ⋯
"   |#my $x ⋯
"
"   |    my $x ⋯
"   |   # my $x ⋯

func! PfxLine (pfx_char)
    let l:line = getline('.')
    if strlen(l:line) == 0
        return
    endif
    let l:col_1_char = (l:line)[0]
    if l:col_1_char != ' '
        if l:col_1_char == a:pfx_char
            exec ':.s,' . a:pfx_char . ',,'
        else
            exec ':.s,^,' . a:pfx_char . ','
        endif
    else

        let l:first_nonblank_char = matchstr(l:line, '  \zs\S\ze')
        if l:first_nonblank_char == a:pfx_char
            exec ':.s, ' . a:pfx_char . ', ,'
        else
            exec ':.s,\( \S\),' . a:pfx_char . '\1,'
        endif
    endif
    normal ll
endfunc

" --------------------------------------------------------------------
"     " Line breaks in some other places may cause spurious moving right
"     " of cursor (?!).

nnoremap <silent><Plug>TextPfx :call
\ PfxLine('-')<cr>:call repeat#set("\<Plug>TextPfx")<cr>
nmap ,cx <Plug>TextPfx

nnoremap <silent><Plug>PerlPfx :call
\ PfxLine('#')<cr>:call repeat#set("\<Plug>PerlPfx")<cr>
nmap ,cp <Plug>PerlPfx

nnoremap <silent><Plug>VimPfx :call
\ PfxLine('"')<cr>:call repeat#set("\<Plug>VimPfx")<cr>
nmap ,cv <Plug>VimPfx

nnoremap <silent><Plug>TexPfx :call
 \ PfxLine('%')<cr>:call repeat#set("\<Plug>TexPfx")<cr>
nmap ,ct <Plug>TexPfx
